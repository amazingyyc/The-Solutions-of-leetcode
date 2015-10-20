#include <iostream>

using namespace std;


struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head)
{
	ListNode dummy(-1);
	ListNode* temp;
	
	while (head)
	{
		temp = head->next;

		head->next = dummy.next;
		dummy.next = head;

		head = temp;
	}

	return dummy.next;
}

int main()
{
	return 0;
}