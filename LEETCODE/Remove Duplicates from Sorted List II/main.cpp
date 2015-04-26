#include <iostream>

using namespace std;

/************************************************************************/
/* 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
/************************************************************************/


 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode *deleteDuplicates(ListNode *head) 
 {
	 ListNode temp(0);
	 temp.next = head;

	 ListNode* pre = &temp;
	 ListNode* cur = head;

	 while (NULL != cur && NULL != cur->next)
	 {
		 if (cur->val != cur->next->val)
		 {
			 pre = cur;
			 cur = cur->next;

			 continue;
		 }

		 ListNode* pC = NULL;
		 do 
		 {
			 pC = cur;
			 cur = cur->next;
		 } while (NULL != cur && pC->val == cur->val);

		 pre->next = cur;
	 }

	 return temp.next;
 }

int main()
{
	return 1;
}