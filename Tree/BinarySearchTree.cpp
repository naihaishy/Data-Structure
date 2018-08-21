
// ¶þ²æËÑË÷Ê÷ Binary Search Tree ÊµÏÖ

#include "pch.h"
#include "time.h"
#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
	int key;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int k) { key = k, parent = nullptr, left = nullptr, right = nullptr; };
};


/* find the minimum value of root tree*/
TreeNode* minimum(TreeNode *root)
{
	if (root == nullptr)
		return root;

	TreeNode *x = root;

	while (x->left != nullptr)
	{
		x = x->left;
	}
	return x;
}

/* find the maximum value of root tree*/
TreeNode* maximum(TreeNode *root)
{
	if (root == nullptr) 
		return root;
	
	TreeNode *x = root;

	while (x->right != nullptr)
	{
		x = x->right;
	}
	return x;
}

/**/
TreeNode* searchRecursive(TreeNode *root, int val)
{
	if (root == nullptr || root->key == val)
		return root;

	if (val < root->key)
		searchRecursive(root->left, val);
	else
		searchRecursive(root->right, val);

}

/**/
TreeNode* searchNonRecursive(TreeNode *root, int val)
{
	if (root == nullptr) 
		return root;

	TreeNode *x = root;
	TreeNode *y = nullptr;

	while (x != nullptr) 
	{
		y = x; // store pre node

		if (val == x->key)
			break;
		else if (val < x->key)
			x = x->left;
		else
			x = x->right;
	}

	return y;
}


/* inorder tree walk with recursive */
void inorderTraversalRecursive(TreeNode *root, std::vector<int> &res)
{
	if (root == nullptr)
		return;

	if (root->left)
		inorderTraversalRecursive(root->left, res);

	res.push_back(root->key);

	if (root->right)
		inorderTraversalRecursive(root->right, res);
}

/* inorder tree walk without recursive */
void inorderTraversalNonRecursive(TreeNode *root, std::vector<int> &res)
{
	if (root == nullptr)
		return;

	std::stack<TreeNode *> stacks;

	TreeNode *current = root;

	while (current != nullptr || !stacks.empty())
	{
		if (current != nullptr)
		{
			stacks.push(current);
			current = current->left;
		}
		else {
			current = stacks.top();
			res.push_back(current->key);
			stacks.pop();
			current = current->right;
		}
	}



}


/**/
void insertBSTree(TreeNode *root, TreeNode *z)
{
	TreeNode *y = nullptr;

	TreeNode *x = root;

	while (x != nullptr)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else 
			x = x->right;
		
	}

	z->parent = y; //link to parent

	// the tree is empty set z to root of this tree
	if (y == nullptr)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;

}

/**/
void buildBSTree(TreeNode *root, int *arr, int n)
{
	for (int i = 0; i < n; i++) {
		TreeNode *z = new TreeNode(arr[i]);
		insertBSTree(root, z);
	}
		
}



/**/
void transplant(TreeNode *root, TreeNode *u, TreeNode *v)
{
	// link parent to child
	if (u->parent == nullptr) {
		// u is root node
		root = v;
	}
	else if (u == u->parent->left) {
		// u is left child of it's parent
		u->parent->left = v;
	}
	else if (u == u->parent->right) {
		// u is right child of it's parent
		u->parent->right = v;

	}

	// link child to parent
	if (v != nullptr) {
		v->parent = v->parent;
	}

}



/* delete TreeNode from BSTree */
void deleteBSTree(TreeNode *root, TreeNode *z)
{
	// case 1: z has no  child
	// case 2: z has one child
	// case 3: z has two child

	TreeNode *y = nullptr;

	TreeNode *x = z;

	if (z->left == nullptr) {
		transplant(root, z, z->right);
	}
	else if (z->right == nullptr) {
		transplant(root, z, z->left);
	}
	else {

		y = minimum(z->right); // successor of z

		// replace y with it's right child when y is not z's child
		if (y->parent != z) {
			transplant(root, y, y->right);
			y->right = z->right; // link child 
			y->right->parent = y; // link parent
		}
					
		transplant(root, z, y);

		y->left = z->left; // link child 
		y->left->parent = y;

	}


}



/**/
int* creatRandArray(int n) 
{
	int* res = new int[n];
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		res[i] = rand() % 100 + 1;
		printf("%d\n", res[i]);
	}
	return res;
}




int main()
{
	//int* a = creatRandArray(8);

	int a[] = {4,6,7,1,8,3,9};

	TreeNode *root = new TreeNode(5);

	buildBSTree(root, a, 7);



	TreeNode *max = maximum(root);
	TreeNode *min = minimum(root);

	std::cout << "max " << max->key << std::endl;
	std::cout << "min " << min->key << std::endl;

	TreeNode *searchR	= searchRecursive(root, 6);
	TreeNode *searchNR	= searchNonRecursive(root, 6);

	std::cout << "searchRecursive " << searchR->key << std::endl;
	std::cout << "searchNonRecursive " << searchNR->key << std::endl;

	std::vector<int> res;
	//inorderTraversalRecursive(root, res);
	inorderTraversalNonRecursive(root, res);
	for (int a : res) {
		std::cout << a << " -";
	}


	std::cout << "\n Hello World!\n";
}