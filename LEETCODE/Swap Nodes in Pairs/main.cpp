#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

/*
毗邻的两个进行交换
*/

ListNode *swapPairs(ListNode *head)
{
	if (nullptr == head || nullptr == head->next)
		return head;

	bool first = true;	//是否第一次执行
	ListNode* index = head;

	while (nullptr != index)
	{
		ListNode* p = index;

		if (nullptr == p)
			return head;

		ListNode* q = p->next;

		if (nullptr == q)
			return head;

		ListNode* r = q->next;

		q->next = p;

		if (nullptr == r)
			p->next = nullptr;
		else if (nullptr == r->next)
			p->next = r;
		else
			p->next = r->next;

		if (first)
		{
			head = q;

			first = false;
		}

		index = r;
	}

	return head;
}

int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	ListNode* head = swapPairs(n1);

	return 1;
}