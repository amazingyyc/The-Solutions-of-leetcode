#include <iostream>
#include <vector>

using namespace std;


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head)
{
	if (NULL == head || NULL == head->next)	return;

	vector<ListNode*> vec;
	ListNode* tail = head;
	while (tail)
	{
		vec.push_back(tail);
		tail = tail->next;
	}

	int n = vec.size();
	int l = 0;
	int r = n - 1;
	while (l < r - 1)
	{
		vec[l]->next = vec[r];
		vec[r]->next = vec[l + 1];

		l++;
		r--;
	}

	vec[r]->next = NULL;
}


int main()
{
	return 1;
}