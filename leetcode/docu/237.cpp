#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	ListNode * head;
	void deleteNode(ListNode* node)
	{
		ListNode * cur = head;
		while(cur && cur->next)
		{
			if(cur->next == node)
			{
				cur->next = cur->next->next;
				delete node;
				break;
			}
		}
	}
};
