#include <iostream>

using namespace std;

/************************************************************************/
/* 
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
¨K
c1 ¡ú c2 ¡ú c3
¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/
/************************************************************************/


struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
	int la = 0;
	int lb = 0;

	ListNode* ha = headA;
	ListNode* hb = headB;

	while (ha)
	{
		la++;
		ha = ha->next;
	}

	while (hb)
	{
		lb++;
		hb = hb->next;
	}

	ha = headA;
	hb = headB;

	if (la > lb)
	{
		int len = la - lb;

		while (len--)
		{
			ha = ha->next;
		}
	}
	else if (la < lb)
	{
		int len = lb - la;

		while (len--)
		{
			hb = hb->next;
		}
	}

	while (ha != hb)
	{
		ha = ha->next;
		hb = hb->next;
	}

	return ha;
}



int main()
{
	return 1;
}