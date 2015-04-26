#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//连接两个链表
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
	ListNode head(-1);
	ListNode* tail = &head;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}

		tail = tail->next;
	}

	if (NULL == l1)
		tail->next = l2;
	else
		tail->next = l1;

	return head.next;
}

ListNode *mergeKLists(vector<ListNode *> &lists) 
{
	int size = lists.size();
	if (0 == size)	return NULL;

	for (int i = 1; i < size; i = i + i)
		for (int j = i; j < size; j += 2*i)
			lists[j - i] = mergeTwoLists(lists[j - i], lists[j]);

	return lists[0];
}

int main()
{
	return 1;
}