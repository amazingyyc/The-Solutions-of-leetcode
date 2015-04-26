#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) { }
};

//小于x的放在前面 大于等于的放在后面

ListNode *deleteDuplicates(ListNode *head)
{
	if (nullptr == head)
		return head;

	ListNode* node = head;

	while (nullptr != node)
	{
		ListNode* nex = node->next;

		while (nullptr != nex && nex->val == node->val)
		{
			ListNode* temp = nex->next;

			delete nex;

			nex = temp;
		}

		node->next = nex;
		node = nex;
	}

	return head;
}

int main()
{
	ListNode* n1 = new ListNode(5);
	ListNode* n2 = new ListNode(5);
	ListNode* n3 = new ListNode(4);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	ListNode* head = deleteDuplicates(n1);

	return 1;
}