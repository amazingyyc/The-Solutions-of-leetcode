#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

//小于x的放在前面 大于等于的放在后面

ListNode* partition(ListNode* head, int x)
{
	if (nullptr == head || nullptr == head->next)
		return head;

	ListNode* sH = nullptr;
	ListNode* sT = nullptr;
	ListNode* bH = nullptr;
	ListNode* bT = nullptr;

	ListNode* node = head;

	while (nullptr != node)
	{
		if (node->val < x)
		{
			if (nullptr == sH)
				sH = sT = node;
			else
			{
				sT->next = node;
				sT = node;
			}
		}
		else
		{
			if (nullptr == bH)
				bH = bT = node;
			else
			{
				bT->next = node;
				bT = node;
			}
		}

		node = node->next;
	}

	if (nullptr == sT)
		return bH;

	sT->next = bH;

	if (nullptr != bT)
		bT->next = nullptr;

	return sH;
}

int main()
{
	ListNode* n1 = new ListNode(5);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(1);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	ListNode* head = partition(n1, 2);

	return 1;
}