#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	ListNode* reverseBetween(ListNode * head, int m, int n)
	{
		ListNode * m_node = head, *n_node = nullptr, *pre_m_node = nullptr;
		ListNode *cur = head;

		ListNode *left = nullptr, *right = nullptr;
		int count = 0;
		while(cur)
		{
			count++;
			if(count < m)
			{
				pre_m_node = cur;
			}
			else if(count == m)
			{
				m_node = cur;
				left = cur;
				right = cur->next;
				continue;
			}
			else if(count > m && count < n)
			{
				cur = right;
				right = cur->next;

				cur->next = left;
				left = cur;
				n_node = cur;
				continue;
			}
			else if(count == n)
			{
				cur = right;
				right = cur->next;
				cur->next = left;
				left = cur;
				n_node = cur;
				continue;
			}
			else
			{
				break;
			}
			cur = cur->next;
		}

		if(m == 1)
		{
			head = n_node;
			m_node->next = right;
		}
		else
		{
			pre_m_node->next = n_node;
			m_node->next = right;
		}

		return head;
	}
};


int main()
{
	Solution sol;
	ListNode *head = getList();

	show(head);
	head = sol.reverseBetween(head, 1, 2);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 1, 3);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 1, 4);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 1, 5);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 2, 3);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 2, 4);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 2, 5);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 3, 4);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 3, 5);
	show(head);

	head = getList();
	show(head);
	head = sol.reverseBetween(head, 4, 5);
	show(head);


}
