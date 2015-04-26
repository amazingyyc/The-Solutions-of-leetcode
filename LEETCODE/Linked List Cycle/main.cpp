#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) 
{
	if (!head) return false;

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast)
	{
		if (fast == slow || slow == fast->next)	
			return true;

		if (NULL == fast->next)
			return false;

		slow = slow->next;
		fast = fast->next->next;
	}

	return false;
}

int main()
{
	return 1;
}