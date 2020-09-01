#include "cpp_header.h"

#include "singly_linked.h"

class Solution {
public:
	// must be no delete
	ListNode* removeZeroSumSublists(ListNode* head)
	{
		cout << "---------------------------------------------\n";
		show(head);
		head = do_remove(head);
		cout << "result\n";
		show(head);
		cout << "---------------------------------------------\n";
		return head;
	}

	ListNode* do_remove(ListNode* head)
	{
		if(head == nullptr)
			return head;
		ListNode dummy_head(INT_MAX);
		dummy_head.next = head;

		ListNode *t1, *t2, *t3;
		t1 = &dummy_head;

		// delete initializing zero node.
		t2 = t1->next;
		while(t2)
		{
			if(t2->val == 0)
			{
				t1->next = t2->next;
				delete t2;
				t2 = t1;
				continue;
			}
			t1 = t2;
			t2 = t2->next;
		}

		if(dummy_head.next == nullptr)
			return nullptr;

		t1 = &dummy_head;
		t2 = t1->next;
		t3 = t2->next;

		// get prefix-sum
		while(t3)
		{
			t3->val += t2->val;
			t2 = t3;
			t3 = t3->next;
		}

		show(dummy_head.next);

		t1 = &dummy_head;
		t2 = t1->next;

		// delete
		while(t2)
		{
			t3 = t2->next;
			while(t3)
			{
				if(t3->val == 0)
				{
					ListNode *t = t3->next;
					delete_range(t2, t3);
					t1->next = t;
					t2 = t1;
					// then check from t1->next, t1->next=t3->next;
					break;
				}
				else if(t3->val == t2->val)
				{
					ListNode *t = t3->next;
					delete_range(t2->next, t3);
					t2->next = t;
					t2 = t1;
					// then check from t1->next, t1->next=t3->next.
					break;
				}
				t3 = t3->next;
			}
			t1 = t2;
			t2 = t2->next;
		}

		t1 = &dummy_head;
		t2 = t1->next;

		// undo prefix sum
		int sum = 0, last;
		while(t2)
		{
			last = t2->val;
			t2->val -= sum;
			t2 = t2->next;
			sum = last;
		}

		return dummy_head.next;
	}

	void delete_range(ListNode* start, ListNode* end)
	{
		if(start == nullptr) 
			return;
		ListNode * t;
		while(start != end)
		{
			t = start->next;
//			cout << "delete : " << start->val << "\n";
			delete start;
			start = t;
		}
		if(end){
//			cout << "delete : " << end->val << "\n";
			delete end;
		}
	}

	void show(ListNode *head)
	{
		while(head)
		{
			cout << head->val << ", ";
			head = head->next;
		}
		cout << "\n----------------\n";
	}
};

ListNode * get_list2()
{
	ListNode *head = new ListNode(1);
	ListNode *t = head;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(-3);
	t = t->next;
	t->next = new ListNode(1);
	return head;
}

ListNode * get_list3()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	t->next = new ListNode(0);
	t = t->next;
	t->next = new ListNode(0);
	t = t->next;
	t->next = new ListNode(0);
	t = t->next;
	t->next = new ListNode(0);
	return head;
}


ListNode * get_list4()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	t->next = new ListNode(1);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(-1);
	t = t->next;
	t->next = new ListNode(-2);
	return head;
}

ListNode * get_list5()
{
	ListNode *head = new ListNode(-8);
	ListNode *t = head;
	t->next = new ListNode(1);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(1);
	t = t->next;
	t->next = new ListNode(2);
	return head;
}


ListNode * get_list6()
{
	ListNode *head = new ListNode(-8);
	ListNode *t = head;
	t->next = new ListNode(-2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(2);
	return head;
}


ListNode * get_list7()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	t->next = new ListNode(-2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(2);
	return head;
}


ListNode * get_list8()
{
	ListNode *head = new ListNode(-2);
	ListNode *t = head;
	t->next = new ListNode(-2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(2);
	return head;
}



ListNode * get_list9()
{
	ListNode *head = new ListNode(-2);
	ListNode *t = head;
	t->next = new ListNode(-2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(2);
	return head;
}



ListNode * get_list10()
{
	ListNode *head = new ListNode(-1);
	ListNode *t = head;
	t->next = new ListNode(-2);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(3);
	t = t->next;
	t->next = new ListNode(-2);
	return head;
}


ListNode * get_list11()
{
	ListNode *head = new ListNode(-5);
	ListNode *t = head;
	t->next = new ListNode(-5);
	t = t->next;
	t->next = new ListNode(20);
	t = t->next;
	t->next = new ListNode(-5);
	t = t->next;
	t->next = new ListNode(-5);
	return head;
}


ListNode * get_list12()
{
	ListNode *head = new ListNode(-5);
	ListNode *t = head;
	t->next = new ListNode(-5);
	t = t->next;
	t->next = new ListNode(20);
	t = t->next;
	t->next = new ListNode(-5);
	t = t->next;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(-2);
	t = t->next;
	t->next = new ListNode(-5);
	return head;
}




ListNode * get_list13()
{
	ListNode *head = new ListNode(-1);
	ListNode *t = head;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(-3);
	t = t->next;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(-2);
	return head;
}

ListNode * get_list14()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(0);
	t = t->next;
	t->next = new ListNode(4);
	t = t->next;
	t->next = new ListNode(0);
	return head;
}

ListNode * get_list15()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	t->next = new ListNode(2);
	t = t->next;
	t->next = new ListNode(0);
	t = t->next;
	t->next = new ListNode(0);
	t = t->next;
	t->next = new ListNode(0);
	return head;
}









void release_list(ListNode *head)
{
	ListNode *t;
	while(head)
	{
		t = head->next;
		delete head;
		head = t;
	}
}

int main()
{
	ListNode *head = get_list2();

	Solution sol;

	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list3();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list4();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list5();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list6();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list7();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list8();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list9();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list10();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list11();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list12();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list13();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list14();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

	head = get_list15();
	head = sol.removeZeroSumSublists(head);
	release_list(head);

}

