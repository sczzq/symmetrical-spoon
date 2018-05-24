/*************************************************************************
	> File Name: 102_binary_tree_level_order_traver.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 04 May 2017 01:26:00 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<vector<int>> levelOrder(TreeNode* root){
		queue<queue<TreeNode*>> qqt;
		queue<TreeNode*> qt;
		vector<vector<int>> vvi;

		qt.push(root);
		qqt.push(qt);
		while(!qqt.empty()){
			queue<TreeNode*>& cur_qt = qqt.front();
			vector<int> vi;
			queue<TreeNode*> next_qt;
			while(!cur_qt.empty()){
				TreeNode* t = cur_qt.front();
				if(t != NULL){
					next_qt.push(t->left);
					next_qt.push(t->right);
					vi.push_back(t->val);
				}
				cur_qt.pop();
			}
			qqt.pop();
			if(!vi.empty())
				vvi.push_back(vi);
			if(!next_qt.empty())
				qqt.push(next_qt);
		}
		return vvi;
	}
};

TreeNode* makeTree(int level, int count)
{
	TreeNode* t;
	if(level < 0) return NULL;
	t = new TreeNode(count);
	cout << "make " << count << " node\n";
	t->left = makeTree(level-1, count+1);
	t->right = makeTree(level-1, count+10);
	return t;
}

void freeTree(TreeNode* node){
	if(node == NULL) return;
	freeTree(node->left);
	freeTree(node->right);
	cout << "delete " << node->val << " node\n";
	delete node;
}

int main()
{
	Solution s;
	TreeNode* root;
	root = makeTree(3, 0);

	vector<vector<int>> vvi = s.levelOrder(root);
	for(auto& vi : vvi){
		cout << "[";
		for(auto v : vi){
			cout << v << ",";
		}
		cout << "]\n";
	}

	freeTree(root);
}

