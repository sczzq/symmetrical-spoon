#include "cpp_header.h"
#include "singly_linked.h"

class Solution {
public:
	ListNode* partition(ListNode* head, int x)
	{
		ListNode dummy_left(INT_MAX), dummy_right(INT_MAX);
		ListNode *left, *right;

		left = &dummy_left;
		right = &dummy_right;

		while(head)
		{
			if(head->val < x)
			{
				left->next = head;
				left = left->next;
			}
			else
			{
				right->next = head;
				right = right->next;
			}
			head = head->next;
		}
		left->next = nullptr;
		right->next = nullptr;

		left->next = dummy_right.next;

		return dummy_left.next;
	}
};

ListNode *getList()
{
	ListNode *head = new ListNode(1);
	ListNode *t = head;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(5);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	return head;
}


ListNode *getList2()
{
	ListNode *head = new ListNode(1);
	ListNode *t = head;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(20);
	t = t->next;
	t->next = new ListNode(5);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	return head;
}


ListNode *getList3()
{
	ListNode *head = new ListNode(1);
	ListNode *t = head;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(20);
	t = t->next;
	t->next = new ListNode(5);
	t = t->next;
	t->next = new ListNode(-2);
	t = t->next;
	return head;
}

void show(ListNode *head)
{
	while(head)
	{
		cout << head->val << ",";
		head = head->next;
	}
	cout << "\n-------------------\n";
}

int main()
{
	Solution sol;
	ListNode *head;

	head = getList();
	show(head);
	head = sol.partition(head, 3);
	show(head);
	
	head = getList2();
	show(head);
	head = sol.partition(head, 3);
	show(head);
	
	head = getList3();
	show(head);
	head = sol.partition(head, 3);
	show(head);
	
}



