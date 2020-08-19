#include "cpp_header.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *deleteNode(TreeNode* root, int key)
	{
		if(!root) return root;

		if(root->val == key)
		{
			return deleteRoot(root);
		}

		TreeNode *left = root->left, *right = root->right, *par_node = root;
		TreeNode *res = root;

		while(root && (left || right))
		{
			if(root->val < key)
			{
				if(right && right->val == key)
				{
					root->right = deleteRoot(right);
				}
				root = root->right;
			}
			else if(root->val > key)
			{
				if(left && left->val == key)
				{
					root->left = deleteRoot(left);
				}
				root = root->left;
			}
			if(root)
			{
				left = root->left;
				right = root->right;
			}
		}

		return res;
	}

	TreeNode *deleteRoot(TreeNode *root)
	{
		if(root->left == NULL && NULL == root->right)
		{
			delete root;
			return NULL;
		}
		if(root->left == NULL)
		{
			TreeNode *t = root->right;
			delete root;
			return t;
		}
		if(root->right == NULL)
		{
			TreeNode *t = root->left;
			delete root;
			return t;
		}

		TreeNode * par_node = root->right, *new_root = root->right;
		while(par_node && par_node->left && par_node->left->left)
		{
			par_node = par_node->left;
		}
		while(new_root && new_root->left)
		{
			new_root = new_root->left;
		}

		if(par_node == new_root)
		{
			new_root->left = root->left;
			delete root;
			return new_root;
		}
		else
		{
			TreeNode * t = new_root->right;
			new_root->left = root->left;
			new_root->right = root->right;
			par_node->left = t;
			
			delete root;
			return new_root;
		}
		
		new_root->left = root->left;
		delete root;
		return new_root;
	}
};


