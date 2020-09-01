#include "cpp_header.h"

#include "singly_linked.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubPath(ListNode *head, TreeNode *root)
	{
		if(head == nullptr) return true;
		if(root == nullptr) return false;

		return is_sub_path(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
	}

	bool is_sub_path(ListNode *head, TreeNode *root)
	{
		if(head == nullptr) return true;
		if(root == nullptr) return false;

		return head->val == root->val && (is_sub_path(head->next, root->left) || is_sub_path(head->next, root->right));
	}
};

