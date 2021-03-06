// Implements of Binary Tree

#include "pch.h"

#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
	 TreeNode *left;
     TreeNode *right;
	 TreeNode(int v) { val = v, left = nullptr, right = nullptr;};
};


// 前序遍历 递归方式
void preorderTraversalRecursive(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

 
	res.push_back(root->val);

	if (root->left)
		preorderTraversalRecursive(root->left, res);

	if(root->right)
		preorderTraversalRecursive(root->right, res);
}

// 前序遍历 非递归方式
void preorderTraversalNonRecursive(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> stacks;
	stacks.push(root);
	 
	TreeNode * current;

	while (!stacks.empty())
	{
		current = stacks.top();
		stacks.pop();
		res.push_back(current->val);
		if (current->right != nullptr)
			stacks.push(current->right);
		if (current->left != nullptr) 
			stacks.push(current->left);	
	}
}

// 前序遍历 非递归方式
void preorderTraversalNonRecursive2(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> stacks;

	 
	TreeNode *current = root;

	while (current != nullptr || !stacks.empty())
	{
		if (current != nullptr)
		{
			res.push_back(current->val);
			stacks.push(current);
			current = current->left;
		}
		else {
			current = stacks.top();
			stacks.pop();
			current = current->right;
		}
 
	}
}

// 中序遍历 递归方式
void inorderTraversalRecursive(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	if (root->left)
		inorderTraversalRecursive(root->left, res);

	res.push_back(root->val);

	if (root->right)
		inorderTraversalRecursive(root->right, res);
}


// 中序遍历 非递归方式
void inorderTraversalNonRecursive(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> stacks;
	
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
			res.push_back(current->val);
			stacks.pop();
			current = current->right;
		}
	}

}


// 后序遍历 递归方式
void postorderTraversalRecursive(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	if (root->left != nullptr)
		postorderTraversalRecursive(root->left, res);

	if (root->right != nullptr)
		postorderTraversalRecursive(root->right, res);

	res.push_back(root->val);

}

// 后序遍历 非递归方式
void postorderTraversalNonRecursive(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> stacks;
 

	TreeNode *current = root;
	TreeNode *last = nullptr;

	while (current != nullptr || !stacks.empty())
	{
		if (current != nullptr)
		{
			stacks.push(current);
			current = current->left;
		}
		else {
			TreeNode *top = stacks.top();
			if (top->right != nullptr && last != top->right)
			{
				current = top->right;
			}
			else {
				stacks.pop();
				res.push_back(top->val);
				last = top;
			}
			 
		}
		 
	 
	}
}

// 后序遍历 非递归方式
void postorderTraversalNonRecursive2(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> stacks;
	stacks.push(root);

	TreeNode *current = nullptr;
	TreeNode *last = nullptr;

	while (!stacks.empty())
	{
		current = stacks.top();

		bool isleafnode = current->left == nullptr && current->right == nullptr;//叶节点
		bool hasvisited = last != nullptr &&  last == current->right; //该节点的右孩子节点已经被访问过了
		if (isleafnode || hasvisited)
		{
			// leaf node
			res.push_back(current->val);
			last = current;
			stacks.pop();
		}else {
			if (current->right != nullptr)
				stacks.push(current->right);

			if (current->left != nullptr)
				stacks.push(current->left);
		}

	}
}

// 后序遍历 非递归方式 双栈
void postorderTraversalNonRecursive3(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	stack<TreeNode *> stacks;
	stack<TreeNode *> stacks_r;

	stacks.push(root);
	TreeNode *current;
 

	while (!stacks.empty())
	{
		current = stacks.top();
		stacks.pop();


		if (current->left != nullptr)
			stacks.push(current->left);

		if (current->right != nullptr)
			stacks.push(current->right);

		stacks_r.push(current);
	}

	while (!stacks_r.empty())
	{
		current = stacks_r.top();
		stacks_r.pop();
		res.push_back(current->val);
	}
}


// 层次遍历
void levelTraversal(TreeNode *root, vector<int> &res)
{
	if (root == nullptr)
		return;

	queue<TreeNode *> queues;
	queues.push(root);

	TreeNode * current;

	while (!queues.empty())
	{
		current = queues.front();
		queues.pop();
		res.push_back(current->val);
		if (current->left != nullptr)
			queues.push(current->left);

		if (current->right != nullptr)
			queues.push(current->right);
	}
}




void main()
{
	TreeNode root(1);
	root.left = new TreeNode(2);
	root.right = new TreeNode(3);

	root.left->left = new TreeNode(4);
	root.left->right = new TreeNode(5);

	root.right->left = new TreeNode(6);
	root.right->right = new TreeNode(7);

	//preorderTraversalRecursive(&root);
	vector<int> res;
	levelTraversal(&root, res);

	for (int a : res)
	{
		cout << a << endl;
	}

	system("pause");
}