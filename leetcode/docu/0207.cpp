#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	ListNode * getIntersectionNode(ListNode * headA, ListNode * headB)
	{
		int alen = 0, blen = 0;
		ListNode * ac = headA, * bc = headB;

		while(ac)
		{
			alen++;
			ac = ac->next;
		}
		while(bc)
		{
			blen++;
			bc = bc->next;
		}

		if(alen > blen)
		{
			int diff = alen - blen;
			while(diff--)
			{
				headA = headA->next;
			}
		}
		else
		{
			int diff = blen - alen;
			while(diff--)
			{
				headB = headB->next;
			}
		}

		while(headA && headB)
		{
			if(headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}

		return NULL;
	}
};


