#include "cpp_header.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode *root)
	{
		vector<int> res;

		vector<int> root_res = countSum(root);
		root->val += root_res[0] + root_res[1];

		show_tree(root);

		count_val(root, res);

		for(auto x : res)
			cout << x << " ";
		cout << "\n";

		return res;
	}

	void count_val(TreeNode *root, vector<int> & res)
	{
		map<int, int> freqs;
		queue<TreeNode*> que;

		que.push(root);

		while(que.size() > 0)
		{
			TreeNode *node = que.front();
			que.pop();
			if(node->left)
			{
				que.push(node->left);
			}
			if(node->right)
			{
				que.push(node->right);
			}

			freqs[node->val]++;
			cout << node->val << "\n";
		}

		multimap<int, int, greater<int>> freqs_reverse;
		for(auto & x : freqs)
		{
			freqs_reverse.emplace(x.second, x.first);
		}

		for(auto it = freqs_reverse.begin(); it != freqs_reverse.end(); it++)
		{
			if((freqs_reverse.begin())->first == it->first)
			{
				res.push_back(it->second);
			}
			else
			{
				break;
			}
		}
	}



	void show_tree(TreeNode *root)
	{
		queue<TreeNode*> que;

		que.push(root);

		while(que.size() > 0)
		{
			TreeNode *node = que.front();
			que.pop();
			if(node->left)
			{
				que.push(node->left);
			}
			if(node->right)
			{
				que.push(node->right);
			}

			cout << node->val << "  ";
		}
		cout << "\n";
	}

	// return left, right sum
	vector<int> countSum(TreeNode *root)
	{
		vector<int> res(2,0);
		if(root->left)
		{
			vector<int> left_res = countSum(root->left);
			root->left->val += left_res[0] + left_res[1];
			res[0] = root->left->val;
		}
		if(root->right)
		{
			vector<int> right_res = countSum(root->right);
			root->right->val += right_res[0] + right_res[1];
			res[1] = root->right->val;
		}

		return res;
	}
};

int main()
{
	TreeNode *root;

	TreeNode *node = new TreeNode(1);
	root = node;

	node = new TreeNode(2);
	root->left = node;
	node = new TreeNode(3);
	root->right = node;

	node = new TreeNode(4);
	root->left->left = node;
	node = new TreeNode(5);
	root->left->right = node;


	node = new TreeNode(6);
	root->right->left = node;
	node = new TreeNode(7);
	root->right->right = node;

	Solution s;

	s.findFrequentTreeSum(root);




}


