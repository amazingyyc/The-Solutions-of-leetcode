#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

//翻转m-n

ListNode *reverseBetween(ListNode *head, int m, int n)
{
	if (m == n)
		return head;

	ListNode* pre  = nullptr;
	ListNode* cur  = head;
	ListNode* nex = cur->next;

	int index = 1;
	
	while (index < m)
	{
		pre = cur;
		cur = cur->next;
		nex = cur->next;
		index++;
	}

	//存储第m-1个 可能为nullptr
	ListNode* h = pre;
	ListNode* mNode = cur;

	while (index < n)
	{
		cur->next = pre;
		pre  = cur;
		cur  = nex;
		nex = nex->next;

		index++;
	}

	cur->next = pre;

	mNode->next = nex;

	if (nullptr == h)
		return cur;
	else
	{
		h->next = cur;

		return head;
	}
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

	ListNode* head = reverseBetween(n1, 3, 4);

	return 1;
}