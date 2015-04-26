#include <iostream>

using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*ListNode* sortList(ListNode *head, int len)
{
	if (0 == len) return NULL;
	if (1 == len)
	{
		head->next = NULL;
		return head;
	}

	ListNode* l = head;
	ListNode* r = head;

	int size = len / 2;
	while (size--)
	{
		r = r->next;
	}

	l = sortList(l, len / 2);
	r = sortList(r, len - len/2);

	ListNode node(-1);
	ListNode* tail = &node;

	for (; l || r;)
	{
		int LVal = l ? l->val : INT_MAX;
		int RVal = r ? r->val : INT_MAX;

		if (LVal <= RVal)
		{
			tail->next = l;
			l = l->next;
		}
		else
		{
			tail->next = r;
			r = r->next;
		}

		tail = tail->next;
	}

	tail->next = NULL;

	return node.next;
}

ListNode *sortList(ListNode *head) 
{
	if (NULL == head || NULL == head->next)
		return head;

	ListNode* node = head;
	int len = 0;

	while (node)
	{
		len++;

		node = node->next;
	}

	return sortList(head, len);
}*/

ListNode* splite(ListNode* head, int n)
{
	if (NULL == head)	return head;

	ListNode* cur = head;

	while (cur->next && --n)
	{
		cur = cur->next;
	}

	if (NULL == cur->next)
		return NULL;

	ListNode* node = cur->next;

	cur->next = NULL;

	return node;
}

ListNode* merge(ListNode* left, ListNode* right, ListNode* tail)
{
	ListNode* cur = tail;
	for (; left && right;)
	{
		if (left->val <= right->val)
		{
			cur->next = left;
			left = left->next;
		}
		else
		{
			cur->next = right;
			right = right->next;
		}

		cur = cur->next;
	}

	if (left)
	{
		cur->next = left;
		while (cur->next)
		{
			cur = cur->next;
		}
	}
	else
	{
		cur->next = right;
		while (cur->next)
		{
			cur = cur->next;
		}
	}

	return cur;
}

ListNode *sortList(ListNode *head)
{
	ListNode* node = head;
	int len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}

	ListNode fummy(-1);
	fummy.next = head;

	for (int i = 1; i < len; i = i << 1)
	{
		ListNode* tail = &fummy;
		ListNode* cur = tail->next;
		while (cur)
		{
			ListNode* left = cur;
			ListNode* right = splite(left, i);
			cur = splite(right, i);

			tail = merge(left, right, tail);
			tail->next = cur;
		}
	}

	return fummy.next;
}

int main()
{
	ListNode n1(1);
	ListNode n2(2);

	n1.next = &n2;

	sortList(&n1);

	return 1;
}