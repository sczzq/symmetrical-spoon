#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	ListNode * partition(ListNode* head, int x)
	{
		ListNode * small = NULL, * ge = NULL;
		ListNode * cur_small, * cur_ge;

		while(head)
		{
			if(head->val < x)
			{
				if(small == NULL)
				{
					small = head;
					cur_small = small;
				}
				else
				{
					cur_small->next = head;
					cur_small = cur_small->next;
				}
			}
			else
			{
				if(ge == NULL)
				{
					ge = head;
					cur_ge = ge;
				}
				else
				{
					cur_ge->next = head;
					cur_ge = cur_ge->next;
				}
			}
			head = head->next;
		}

		if(small)
		{
			cur_small->next = ge;
			head = small;
		}
		else
		{
			head = ge;
		}
		if(ge)
			cur_ge->next = NULL;

		return head;
	}
};

