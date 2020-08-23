#include "cpp_header.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* first = head;
		ListNode* second = head;

		if(head == NULL)
			return head;

		while(second && n > 0)
		{
			second = second->next;
			n--;
		}

		if(second == NULL)
		{
			head = first->next;
			delete first;
			return head;
		}

		while(second && second->next)
		{
			first = first->next;
			second = second->next;
		}

		second = first->next;
		first->next = first->next->next;
		delete second;

		return head;
	}

};

void show_list(ListNode *head)
{
	while(head)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << "\n";
}

ListNode* constructList(int k)
{
	int i = 1;
	ListNode* head = new ListNode(i);
	ListNode* cur = head;

	while(i < k)
	{
		cur->next = new ListNode(++i);
		cur = cur->next;
	}

	return head;
}

void releaseList(ListNode * head)
{
	while(head)
	{
		ListNode * t = head->next;
		delete head;
		head = t;
	}
}

int main()
{
	Solution sol;
	ListNode *head;
	ListNode *after;

	head = constructList(5);
	show_list(head);
	after = sol.removeNthFromEnd(head, 1);
	show_list(after);
	cout << "----------------------------\n";
	releaseList(after);

	head = constructList(5);
	show_list(head);
	after = sol.removeNthFromEnd(head, 2);
	show_list(after);
	cout << "----------------------------\n";
	releaseList(after);

	head = constructList(5);
	show_list(head);
	after = sol.removeNthFromEnd(head, 3);
	show_list(after);
	cout << "----------------------------\n";
	releaseList(after);

	head = constructList(5);
	show_list(head);
	after = sol.removeNthFromEnd(head, 4);
	show_list(after);
	cout << "----------------------------\n";
	releaseList(after);

	head = constructList(5);
	show_list(head);
	after = sol.removeNthFromEnd(head, 5);
	show_list(after);
	cout << "----------------------------\n";
	releaseList(after);


}


