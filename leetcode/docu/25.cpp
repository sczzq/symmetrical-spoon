#include "cpp_header.h"
#include "singly_linked.h"

void show(ListNode *head)
{
	while(head)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << "\n-----------------\n";
}


class Solution {
public:
	ListNode * reverseKGroup(ListNode * head, int k)
	{
		ListNode *nhead = head;
		ListNode *pre = nullptr;
		ListNode *newhead = nullptr, *t, *curhead;

		while(nhead)
		{
			int i = k;
			head = nhead;
			while(i-- && nhead)
			{
				pre = nhead;
				nhead = nhead->next;
			}
			pre->next = nullptr;

			if(i < 0)
			{
				head = reverseList(head);
			}

			if(newhead == nullptr)
			{
				newhead = head;
				curhead = head;
			}
			else
			{
				t = curhead;
				while(t)
				{
					pre = t;
					t = t->next;
				}
				pre->next = head;
				curhead = head;
			}
		}

		return newhead;
	}

	ListNode *reverseList(ListNode *head)
	{
		if(head == nullptr || head->next == nullptr)
			return head;

		ListNode *left, *right;
		left = head;
		head = head->next;
		right = head->next;

		left->next = nullptr;

		while(head && right)
		{
			head->next = left;
			left = head;
			head = right;
			right = right->next;
		}
		head->next = left;

		return head;
	}
};
ListNode *getList()
{
	ListNode *head = new ListNode(1);
	ListNode *t = head;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(5);
	t = t->next;
	return head;
}

int main()
{
	Solution sol;
	ListNode *head;

	head = getList();
	show(head);
	head = sol.reverseKGroup(head, 2);
	show(head);

	head = sol.reverseKGroup(head, 2);
	show(head);

	head = sol.reverseKGroup(head, 1);
	show(head);

	head = sol.reverseKGroup(head, 3);
	show(head);

	head = sol.reverseKGroup(head, 3);
	show(head);

	head = sol.reverseKGroup(head, 4);
	show(head);

	head = sol.reverseKGroup(head, 4);
	show(head);

	head = sol.reverseKGroup(head, 5);
	show(head);

	head = sol.reverseKGroup(head, 5);
	show(head);



}



