#this is a comment

all			:		KrustyKrab

KrustyKrab	:		BinaryTree.o KrustyKrab.o 
					g++ -o KrustyKrab.exe BinaryTree.o KrustyKrab.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
BinaryTree.o	:	BinaryTree.cpp
					g++ -I ./ -c BinaryTree.cpp
				
KrustyKrab.o	:	KrustyKrab.cpp
					g++ -I ./ -c KrustyKrab.cpp
		

clean			:	KrustyKrab.exe
					del *.o 
					del KrustyKrab.exe