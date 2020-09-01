#include "cpp_header.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

/*
 * if no cycle, the last is NULL
 * if cycle, it should be that duplicate in some node.
 *
 * that is to say,
 * if has NULL node, there must be no cycle.
 * otherwise, there must be cycle.
 */
class Solution {
public:
	ListNode * detectCycle(ListNode * head)
	{
		ListNode *first, *second;

		if(head == NULL) return NULL;

		first = head;
		second = head;

		while(first && second && second->next)
		{
			if(first == second)
				break;

			first = first->next;
			second = second->next->next;
		}

		if(first == second)
		{
			first = head;
			while(first != second)
			{
				first = first->next;
				second = second->next;
			}
			return first;
		}

		return NULL;
	}
};

/*
 * first: k + mc + q
 * second : k/2 + nc + q/2
 * must has n > m
 * k + mc + q = k / 2 + nc + q/2
 * 2k + 2mc + 2q = k + 2nc + q
 * k + q= 2nc - 2mc
 *
 * k = 2nc - 2mc - q
 *
 * q = 2nc - 2mc - k
 *
 * if first get k step from head
 * then second must get multi-c and minus q step
 * that is the first node in the cycle.
 *
 */

