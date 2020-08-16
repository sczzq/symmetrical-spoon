#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> res;

	vector<vector<int>> pathSum(TreeNode* root, int sum){
		sumVal(root, sum);

		findVal(root, sum);

		return res;
	}

	void findVal(TreeNode *root, int sum)
	{
		TreeNode *left, *right;
		queue<vector<TreeNode*>> que;
		vector<TreeNode *> star{root};
		que.push(star);

		while(que.size() > 0 )
		{
			vector<TreeNode *> vt = que.front();
			que.pop();
			auto it = vt.rbegin();
			if((*it)->val == sum 
					&& (*it)->left == NULL
					&& (*it)->right == NULL)
			{
				vector<int> temp;
				int last_val = 0;
				for(auto &node : vt)
				{
					temp.push_back(node->val - last_val);
					last_val = node->val;
				}
				res.push_back(temp);
			}
			else
			{
				if((*it)->left)
				{
					vector<TreeNode *> nvt = vt;
					nvt.push_back((*it)->left);
					que.push(nvt);
				}
				if((*it)->right)
				{
					vector<TreeNode *> nvt = vt;
					nvt.push_back((*it)->left);
					que.push(nvt);
				}
			}

		}
	}

	void sumVal(TreeNode *root, int sum)
	{
		if(root->left)
		{
			root->left->val += root->val;
			sumVal(root->left, sum);
		}
		if(root->right)
		{
			root->right->val += root->val;
			sumVal(root->right, sum);
		}
	}
};


