#include <iostream>
#include <unordered_map>

using namespace std;


struct RandomListNode 
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) 
{
	if (NULL == head) return NULL;

	RandomListNode* cur = head;
	while (cur)
	{
		RandomListNode* node = new RandomListNode(cur->label);

		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	cur = head;
	while (cur)
	{
		if (NULL != cur->random)
			cur->next->random = cur->random->next;
		
		cur = cur->next->next;
	}
	RandomListNode temp(-1);
	RandomListNode* tail = &temp;
	cur = head;
	
	while (cur)
	{
		tail->next = cur->next;
		tail = tail->next;

		cur->next = tail->next;
		cur = cur->next;
	}

	return temp.next;
}


int main()
{
	return 1;
}