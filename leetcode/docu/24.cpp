#include "cpp_header.h"

class Solution {
	struct ListNode{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
public:
	ListNode* swapPairs(ListNode* head)
	{
		ListNode* newhead;
		ListNode* first, *second;

		if(head == NULL) return head;
		if(head && head->next == NULL) return head;

		ListNode* next_head;
		ListNode* last_tail;

		first = head;
		second = head->next;
		next_head = second->next;

		newhead = second;
		newhead->next = first;
		last_tail = first;
		last_tail->next = NULL;

		while(next_head && next_head->next)
		{
			first = next_head;
			second = next_head->next;
			next_head = second->next;

			last_tail->next = second;
			second->next = first;
			last_tail = first;
			last_tail->next = NULL;
		}

		if(next_head)
			last_tail->next = next_head;

		return newhead;
	}
};

