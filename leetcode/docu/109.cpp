#include "cpp_header.h"
#include "singly_linked.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode * sortedListToBST(ListNode * head)
	{
		int count = 0;
		ListNode * cur = head;
		vector<int> vlist;

		while(cur)
		{
			vlist.push_back(cur->val);
			count++;
			cur = cur->next;
		}

		return getTree(vlist, 0, count-1);
	}

	TreeNode * getTree(vector<int>& vlist, int left, int right)
	{
		if(left > right)
			return NULL;
		int mid = (left + right) / 2;
		TreeNode *root = new TreeNode(vlist[mid], getTree(vlist, left, mid-1), getTree(vlist, mid+1, right));

		return root;
	}
};

