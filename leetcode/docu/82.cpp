#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head)
	{
		if(head == NULL) return NULL;

		if(head->next == NULL) return head;

		ListNode *newhead = NULL;
		ListNode *cur = NULL;
		while(head)
		{
			ListNode *nodup = head->next;
			int count = 1;
			while(nodup && nodup->val == head->val)
			{
				count++;
				nodup = nodup->next;
			}
			if(count > 1)
			{
				ListNode *temp;
				while(head != nodup)
				{
					temp = head->next;
					delete head;
					head = temp;
				}
			}
			else
			{
				if(newhead == NULL)
				{
					newhead = head;
					cur = head;
				}
				else
				{
					cur->next = head;
					cur = head;
				}
				head = head->next;
			}
		}
		if(cur) 
			cur->next = NULL;

		return newhead;
	}
};

