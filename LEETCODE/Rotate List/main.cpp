#include <iostream>

using namespace std;

/************************************************************************/
/* 
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
/************************************************************************/

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) 
{
	if (NULL == head || NULL == head->next || 0 == k)
		return head;

	ListNode temp(-1);
	temp.next = head;

	int len = 0;
	ListNode* tail = &temp;

	while (tail->next)
	{
		tail = tail->next;
		len++;
	}

	//长于链表长度
	if (k >= len)	k %= len;

	if (0 == k)	return head;

	int mov = len - k;
	ListNode* cur = &temp;
	while (mov--)
	{
		cur = cur->next;
	}

	tail->next = head;
	head = cur->next;
	cur->next = NULL;

	return head;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);

	n1->next = n2;
	n2->next = NULL;

	rotateRight(n1, 2);

	return 1;
}