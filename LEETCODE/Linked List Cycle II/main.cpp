#include <iostream>
#include <unordered_map>

using namespace std;

/************************************************************************/
/* 

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?*/
/************************************************************************/



struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*ListNode *detectCycle(ListNode *head) 
{
	ListNode* s = head;
	ListNode* f = head;

	while (1)
	{
		if (NULL == f || NULL == f->next)
			return NULL;

		f = f->next->next;
		s = s->next;

		if (f == s)	break;
	}

	ListNode* t = head;

	while (t != s)
	{
		f = s->next;

		while (f != s)
		{
			if (f == t) return t;

			f = f->next;
		}

		t = t->next;
	}

	return s;
}*/

/*ListNode *detectCycle(ListNode *head)
{
	unordered_map<ListNode*, int> map;
	
	ListNode* t = head;

	while (t)
	{
		if (map.find(t) != map.end())
			return t;

		map[t] = 1;
		t = t->next;
	}

	return NULL;
}*/

ListNode *detectCycle(ListNode *head)
{
	ListNode* s = head;
	ListNode* f = head;

	while (1)
	{
		if (NULL == f || NULL == f->next)
			return NULL;

		f = f->next->next;
		s = s->next;

		if (f == s)	break;
	}

	ListNode* t = head;

	while (t != s)
	{
		t = t->next;
		s = s->next;
	}

	return s;
}

int main()
{
	return 1;
}