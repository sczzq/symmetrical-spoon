#include "cpp_header.h"

struct Node {
	int val;
	Node * next;
	Node * random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node * copyRandomList(Node * head)
	{
		vector<int> random;
		vector<Node*> nodes;
		map<Node*, int> ri;
		Node *newhead = NULL;
		Node *cur;
		int count = 0;

		Node *temp = head;
		while(temp)
		{
			if(newhead == NULL)
			{
				newhead = new Node(temp->val);
				cur = newhead;
				nodes.push_back(cur);
			}
			else
			{
				cur->next = new Node(temp->val);
				cur = cur->next;
				nodes.push_back(cur);
			}
			ri[temp] = count++;
			temp = temp->next;
		}

		ri[NULL] = count;
		nodes.push_back(NULL);

		temp = head;
		while(temp)
		{
			random.push_back(ri[temp->random]);
			temp = temp->next;
		}

		cur = newhead;
		count = 0;
		while(cur)
		{
			cur->random = nodes[random[count++]];
			cur = cur->next;
		}

		return newhead;
	}
};


