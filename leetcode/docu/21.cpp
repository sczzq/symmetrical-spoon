#include "cpp_header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode():val(0), next(nullptr){}
	ListNode(int x):val(x), next(nullptr){}
	ListNode(int x, ListNode*next) : val(x), next(next){}
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *head;
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		if(l1->val < l2->val)
		{
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head = l2;
			l2 = l2->next;
		}

		ListNode * cur = head;

		while(l1 && l2)
		{
			if(l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
			}
		}

		if(l1)
			cur->next = l1;
		if(l2)
			cur->next = l2;

		return head;
	}
};