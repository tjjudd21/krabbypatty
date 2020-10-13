/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Trevor Judd                                                      *
 *     Purpose: This is the specification file for the BinaryTree class, which   *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;


class BinaryTree
{
	private:
		struct TreeNode
		{
			string customerName;
			int numPatties;    // The number of krabby patties consumed
			TreeNode *left;    // Pointer to left child node
			TreeNode *right;   // Pointer to right child node
		};
		
	TreeNode *root;       // Pointer to the root node
	
	//private member functions
	void destroySubTree(TreeNode *);
	void insert(TreeNode *&, TreeNode *&);
	//void deleteNode(TreeNode *&, string);
	//void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *&);
	void getLeast(TreeNode *, string&, int&);
	void getHighest(TreeNode *, string&, int&);
	void getTotal(TreeNode *, int&);
	TreeNode* balance(TreeNode *&);
	int height(TreeNode *);
	int diff(TreeNode *);
	TreeNode* rr_rotation(TreeNode *);
	TreeNode* ll_rotation(TreeNode *);
	TreeNode* lr_rotation(TreeNode *);
	TreeNode* rl_rotation(TreeNode *);
	TreeNode* getLeft();
	TreeNode* getRight();
	
	
	public:
		// Constructor
		BinaryTree()
			{ root = NULL; }
			
		// Destructor
		~BinaryTree()
			{ destroySubTree(root); }
			
		// Binary tree operations
		void insertNode(string, int);
		//void remove(string);
		int searchNode(string);
		
		void displayInOrder()
			{ displayInOrder(root); }
		
		void getLeastNumPatties(string&, int&);
		
		void getMostNumPatties(string&, int&);
			
		int getTotalNumPatties();
		
		void display(TreeNode*, int);
		
		void display()
			{display(root, 1); }
		
};


#endif