#include "cpp_header.h"

struct ListNode{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution {

	struct costumLess{
		bool operator()(const ListNode* l1, const ListNode* l2) const
		{
			return l1->val < l2->val;
		}
	} ;
public:
	ListNode * mergeKLists(vector<ListNode*>& lists)
	{
		clearNULL(lists);
		if(lists.size() == 0) return NULL;

		set<ListNode*, costumLess> slists(lists.begin(), lists.end());

		ListNode* head, *cur;
		head = *(slists.begin());
		cur = head;

		slists.erase(slists.begin());

		if(head->next)
			slists.insert(head->next);

		while(slists.size() > 1)
		{
			ListNode* node = *(slists.begin());
			cur->next = node;
			cur = cur->next;

			slists.erase(slists.begin());

			if(cur->next)
				slists.insert(cur->next);
		}

		if(slists.size() == 1)
			cur->next = *(slists.begin());

		return head;
	}



	ListNode * mergeKLists2(vector<ListNode*>& lists)
	{
		clearNULL(lists);
		if(lists.size() == 0) return NULL;

		int mi = findMinimum(lists);
		ListNode *head = lists[mi];
		lists[mi] = lists[mi]->next;

		if(lists[mi] == NULL)
			lists.erase(lists.begin() + mi);

		ListNode *cur = head;

		while(lists.size() > 1)
		{
			mi = findMinimum(lists);
			cur->next = lists[mi];
			lists[mi] = lists[mi]->next;
			cur = cur->next;

			if(lists[mi] == NULL)
				lists.erase(lists.begin() + mi);
		}

		if(lists.size() == 1)
		{
			cur->next = lists[0];
		}

		return head;
	}

	int findMinimum(vector<ListNode*> &lists)
	{
		int mi = 0;
		for(int i = 1; i < lists.size(); i++)
		{
			if(lists[i]->val < lists[mi]->val)
				mi = i;
		}

		return mi;
	}

	void clearNULL(vector<ListNode*> &lists)
	{
		for(int i = 0; i < lists.size(); i++)
		{
			if(lists[i] == NULL)
			{
				lists.erase(lists.begin() + i);
				i--;
			}
		}
	}
};



