#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	int kthToLast(ListNode * head, int k)
	{
		ListNode *fast = head;

		while(k--)
			fast = fast->next;

		while(fast)
		{
			fast = fast->next;
			head = head->next;
		}

		return head->val;
	}
};
