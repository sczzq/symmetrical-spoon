#include "cpp_header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head)
	{
		ListNode* even = NULL;
		ListNode* odd = NULL;
		ListNode* cur_even, *cur_odd;

		if(head == NULL) return NULL;
		even = head;
		head = head->next;

		if(head == NULL) return even;
		odd = head;
		head = head->next;

		cur_even = even;
		cur_odd = odd;

		bool is_even = true;
		while(head)
		{
			if(is_even)
			{
				cur_even->next = head;
				cur_even = cur_even->next;
				is_even = false;
			}
			else
			{
				cur_odd->next = head;
				cur_odd = cur_odd->next;
				is_even = true;
			}
			head = head->next;
		}

		cur_even->next = odd;
		cur_odd->next = NULL;

		return even;
	}
};


