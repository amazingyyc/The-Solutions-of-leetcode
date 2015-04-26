#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//每k个进行反转 最后不足k无需反转
ListNode *reverseKGroup(ListNode *head, int k) 
{
	if (0 == k || 1 == k)	return head;

	ListNode front(-1);
	front.next = head;
	head = &front;

	//每次反转k个 如果最后不足k个就再反转回来
	while (1)
	{
		ListNode* pre = head;
		ListNode* cur = pre->next;

		if (NULL == cur)	
			return front.next;

		ListNode* tail = cur;
		ListNode* next = cur->next;
		
		int index = k;

		while (index)
		{
			index--;

			cur->next = pre;

			pre = cur;
			cur = next;

			if (NULL == cur)
				break;

			next = next->next;
		}

		if (0 == index)
		{
			head->next = pre;
			tail->next = cur;
			head = tail;
		}
		else
		{
			//最后的再反转过来
			index = k - index;

			cur = pre;
			next = pre->next;
			pre = NULL;

			while (index--)
			{
				cur->next = pre;
				
				pre = cur;
				cur = next;
				next = next->next;
			}

			head->next = pre;

			return front.next;
		}
	}
}

int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	ListNode* x = reverseKGroup(node1, 3);

	return 1;
}