/*********************************************************************************
 *     Title:   BinaryTree.cpp                                                   *
 *     Author:  Trevor Judd		                                                *
 *     Purpose: This is the implementation file for the BinaryTree class, which  *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
   {
      nodePtr = newNode;                  // Insert the node.
   }
   else if (newNode->customerName < nodePtr->customerName)
   {
      insert(nodePtr->left, newNode);     // Search the left branch
   }
   else 
   {
      insert(nodePtr->right, newNode);
   }	  // Search the right branch
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void BinaryTree::insertNode(string name, int num)
{
   TreeNode *newNode = NULL;	// Pointer to a new node.

   newNode = new TreeNode;
   newNode->customerName = name;
   newNode->numPatties = num;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode);
   balance(root);
}

//***************************************************
// searchNode determines if a customer is present   *
// in the tree. If so, the function returns the     *
// number of Krabby Patties eaten by that customer. *
// Otherwise, it returns -1.                        *
//***************************************************

int BinaryTree::searchNode(string name)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
		if (nodePtr->customerName == name)
		{
			return (nodePtr->numPatties);
		}
		else if (name < nodePtr->customerName)
		{
			nodePtr = nodePtr->left;
		}
		else
			nodePtr = nodePtr->right;
   }
   return -1;
}

/*
void BinaryTree::remove(string nameOfCustomer)
{
   cout << "You are trying to remove " << nameOfCustomer << "." << endl;
   deleteNode(root, nameOfCustomer);
   cout << "\n" << nameOfCustomer << " has been deleted." << endl;
}
*/

/*
void BinaryTree::deleteNode(TreeNode *&nodePtr, string nameOfCustomer)
{
   if(nodePtr)
   {
   
   if (nameOfCustomer < nodePtr->customerName)
   {
	  deleteNode(nodePtr->left, nameOfCustomer);
   }
   else if (nameOfCustomer > nodePtr->customerName)
   {
      deleteNode(nodePtr->right, nameOfCustomer);
   }
   else
      makeDeletion(nodePtr);
   }
}
*/

/*
void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = NULL;

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}
*/

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void BinaryTree::displayInOrder(TreeNode *&nodePtr)
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->customerName << endl;
      displayInOrder(nodePtr->right);
   }
}

void BinaryTree::getLeastNumPatties(string &name, int &leastPatties)
{
	name = root->customerName;
	leastPatties = root->numPatties;
	getLeast(root, name, leastPatties);	
}

void BinaryTree::getLeast(TreeNode *nodePtr, string &name, int &nodePatties)
{
	if (nodePtr)
	{
		getLeast(nodePtr->left, name, nodePatties);
		if (nodePtr->numPatties < nodePatties)
		{
			nodePatties = nodePtr->numPatties;
			name = nodePtr->customerName;
		}
		getLeast(nodePtr->right, name, nodePatties);
	}
}

void BinaryTree::getMostNumPatties(string &name, int &mostPatties)
{
	name = root->customerName;
	mostPatties = root->numPatties;
	getHighest(root, name, mostPatties);	
}

void BinaryTree::getHighest(TreeNode *nodePtr, string &name, int &nodePatties)
{
	if (nodePtr)
	{
		getHighest(nodePtr->left, name, nodePatties);
		if (nodePtr->numPatties > nodePatties)
		{
			nodePatties = nodePtr->numPatties;
			name = nodePtr->customerName;
		}
		getHighest(nodePtr->right, name, nodePatties);
	}
}

int BinaryTree::getTotalNumPatties()
{
	int total = 0;
	
	getTotal(root, total);
	
	return total;
}

void BinaryTree::getTotal(TreeNode *nodePtr, int &total)
{
	if (nodePtr)
	{
		getTotal(nodePtr->left, total);
		total = total + (nodePtr->numPatties);
		getTotal(nodePtr->right, total);	
	}
}

/*	balance:	Balance the Tree into an AVL tree	*/
BinaryTree::TreeNode* BinaryTree::balance(TreeNode *&temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = rr_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = ll_rotation(temp);
    }
    return temp;
}

/*	height:  Find the height of a node and return it	*/
int BinaryTree::height(TreeNode *temp) 
{
    int nodeHeight = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        nodeHeight = max_height + 1;
    }
    return nodeHeight;
}

/*	diff:  Find the HEIGHT DIFFERENCE between the left & right subtrees */
int BinaryTree::diff(TreeNode *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
	
    return b_factor;
}

/*	rr_rotation:  Perform RIGHT-RIGHT ROTATION on this parent node	*/
BinaryTree::TreeNode* BinaryTree::rr_rotation(TreeNode *parent)
{

    TreeNode *temp;
	
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
	
    return temp;
}

/*	ll_rotation:  Perform LEFT-LEFT ROTATION on this parent node	*/
BinaryTree::TreeNode* BinaryTree::ll_rotation(TreeNode *parent)
{
    TreeNode *temp;
	
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
	
    return temp;
}

/*	lr_rotation:  Perform LEFT-RIGHT ROTATION on this parent node	*/
BinaryTree::TreeNode* BinaryTree::lr_rotation(TreeNode *parent)
{
    TreeNode *temp;
	
    temp = parent->left;
    parent->left = ll_rotation(temp);
	
    return rr_rotation(parent);
}

/*	rl_rotation:  Perform RIGHT-LEFT ROTATION on this parent node	*/
BinaryTree::TreeNode* BinaryTree::rl_rotation(TreeNode *parent)
{
    TreeNode *temp;
	
    temp = parent->right;
    parent->right = rr_rotation(temp);
	
    return ll_rotation(parent);
}

/*	display:  Display the AVL Tree	*/
void BinaryTree::display(TreeNode *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout << ptr->customerName.substr(0,2);
        display(ptr->left, level + 1);
    }
}