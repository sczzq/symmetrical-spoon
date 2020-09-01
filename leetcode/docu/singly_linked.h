#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
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

void show(ListNode *head)
{
	while(head)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << "\n------------\n";
}


#endif
