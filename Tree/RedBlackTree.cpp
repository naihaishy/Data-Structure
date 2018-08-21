// Implements of Red Black Tree

#include "pch.h"
#include "time.h"
#include <iostream>
#include <vector>
#include <stack>


enum Color{ RED, BLACK };



struct TreeNode {
	int key;
	Color color;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int k) { key = k, parent = nullptr, left = nullptr, right = nullptr; };
};


/**/
void rotate_left(TreeNode *root, TreeNode *node) 
{

}

/**/
void rotate_right(TreeNode *root, TreeNode *node)
{

}


/**/
void insert(TreeNode *root, TreeNode *node)
{

}


void insertFixUp(TreeNode *root, TreeNode *node)
{

}


/**/
void deletes(TreeNode *root, TreeNode *node)
{

}


/**/
void deletesFixUp(TreeNode *root, TreeNode *node)
{

}





void main() 
{

}



