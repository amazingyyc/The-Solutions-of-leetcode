#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

//移除从后向前第n个

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	if (nullptr == head)
		return head;

	//添加一个头部
	ListNode* node = new ListNode(0);
	node->next = head;

	ListNode* l = node;
	ListNode* r = head;

	int index = 1;

	while (nullptr != r->next)
	{
		if (index < n)
			index++;
		else
			l = l->next;

		r = r->next;
	}

	ListNode* t = l->next;
	l->next = t->next;

	delete t;

	return node->next;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	ListNode* head = removeNthFromEnd(n1, 4);

	return 1;
}