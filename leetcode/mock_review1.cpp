/*************************************************************************
	> File Name: mock_review1.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 07 May 2017 10:37:44 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
		int pos = postorder.size() - 1;
		TreeNode* root = new TreeNode(postorder[pos]);
		
		getChild(inorder, postorder, pos, root);
	}

	TreeNode* getNode(vector<int>& inorder, vector<int>& postorder, int p, int n, int nn, TreeNode* root){
		int cur_pos = find(inorder.begin(), inorder.end(), postorder.at(p)) - inorder.begin();
		int next_pos = find(inorder.begin(), inorder.end(), postorder.at(n)) - inorder.begin();
		int nnext_pos = find(inorder.begin(), inorder.end(), postorder.at(nn)) - inorder.begin();
		if(cur_pos < next_pos && cur_pos < nnext_pos){
			root->left = new TreeNode(postorder.at(next_post_pos));
			getNode(inorder, postorder, p-1, n-1, nn-1 root->left);
		} else if(cur_pos < next_pos && cur_pos > nnext_pos){
			root->left = new TreeNode(postorder.at(next_post_pos));
			root->right = new TreeNode(postorder.at(nnext_post_pos));
			getNode(inorder, postorder, p, n-2, nn-2, root);
		} else if(cur_pos > next_pos && cur_pos > nnext_pos){
			root->right = new TreeNode(postorder.at(next_post_pos));
			getNode(inorder, postorder, p, n-1, nn-2, root->right);
		}
	}
};

