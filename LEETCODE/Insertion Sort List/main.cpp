#include <iostream>

using namespace std;


 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode *insertionSortList(ListNode *head) 
 {
	 ListNode temp(INT_MIN);
	 ListNode* cur = head;

	 while (cur)
	 {
		 ListNode* t = cur->next;
		 ListNode* pre = &temp;

		 while (NULL != pre->next && cur->val > pre->next->val)
		 {
			 pre = pre->next;
		 }

		 cur->next = pre->next;
		 pre->next = cur;

		 cur = t;
	 }
	 
	 return temp.next;
 }


int main()
{
	return 1;
}