/*************************************************************************
	> File Name: copy from 102_binary_tree_level_order_traver.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 04 May 2017 01:26:00 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root){
		queue<stack<TreeNode*>> qst;
		stack<TreeNode*> st;
		vector<vector<int>> vvi;
		int zigzag = 0;

		st.push(root);
		qst.push(st);
		while(!qst.empty()){
			stack<TreeNode*>& cur_st = qst.front();
			vector<int> vi;
			stack<TreeNode*> next_st;
			while(!cur_st.empty()){
				TreeNode* t = cur_st.top();
				if(t != NULL){
					if(zigzag == 0){
						next_st.push(t->left);
						next_st.push(t->right);
					} else {
						next_st.push(t->right);
						next_st.push(t->left);
					}
					vi.push_back(t->val);
				}
				cur_st.pop();
			}
			zigzag = !zigzag;
			qst.pop();
			if(!vi.empty())
				vvi.push_back(vi);
			if(!next_st.empty())
				qst.push(next_st);
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

	vector<vector<int>> vvi = s.zigzagLevelOrder(root);
	for(auto& vi : vvi){
		cout << "[";
		for(auto v : vi){
			cout << v << ",";
		}
		cout << "]\n";
	}

	freeTree(root);
}

