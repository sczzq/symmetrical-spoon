#include "cpp_header.h"

struct TreeNode {
	int val;
	TreeNode * next;
	TreeNode(int x) : val(x), next(NULL) {}
};

int findRKNode(TreeNode *root, int rk)
{
	TreeNode *first = root, *second = root;

	while(rk-- > 0)
	{
		if(second->next)
		{
			second = second->next;
		}
		else
		{
			return -1;
		}
	}

	while(second->next)
	{
		first = first->next;
		second = second->next;
	}

	return first->val;
}

TreeNode *reverseLink(TreeNode *root)
{
	TreeNode *rroot = NULL, *t;

	while(root)
	{
		t = root;
		root = root->next;
		t->next = rroot;
		rroot = t;
	}

	return rroot;
}

int fb(int n)
{
	vector<int> mark;

	mark.push_back(0);
	mark.push_back(1); // n = 1
	mark.push_back(1); // n = 2
	mark.push_back(2); // n = 3


	for(int i = 4; i <= n; i++)
	{
		mark.push_back(mark[i-1] + mark[i-2]);
	}

	return mark[n];
}

int inter_10(int k)
{
	int count = 0;
	if (k < 0)
	{
		k = 0 - k;
		count++;
	}
	while(k)
	{
		if(k % 2 == 1)
		{
			count++;
		}
		k = k / 2;
	}
	
	return count;
}

int reverse_print(TreeNode * root)
{
	if(root)
	{
		if(root->next)
			reverse_print(root->next);
		cout << root->val << "\n";
	}
	return 0;
}

int reverse_print2(TreeNode * root)
{
	stack<int> sta;

	while(root)
	{
		sta.push(root->val);
		root = root->next;
	}

	while(sta.size() > 0)
	{
		cout <<sta.top() << "\n";
		sta.pop();
	}
}

int main()
{
	TreeNode * root, * temp;

	root = new TreeNode(0);
	temp = root;

	for(int i = 1; i < 10; i++)
	{
		temp->next = new TreeNode(i);
		temp = temp->next;
	}

	for(int i = 0; i < 12; i++)
	{
		cout << "Reverse " << i << " : " << findRKNode(root, i) << "\n";
	}

	/*
	TreeNode *rroot = reverseLink(root);

	while(rroot)
	{
		cout << rroot->val << "   ";
		rroot = rroot->next;
	}
	cout << "\n";

	for(int i = 1; i < 10; i++)
	{
		cout << i << ", " << fb(i) << "\n";
	}

	for(int i = -10; i < 20; i++)
	{
		cout << i << ", " << inter_10(i) << "\n";
	}
	*/

	reverse_print2(root);
}

