#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//´Ó
TreeNode* getThree(ListNode* node, int len)
{
	if (1 == len)
	{
		return new TreeNode(node->val);
	}
	
	if (2 == len)
	{
		TreeNode* root = new TreeNode(node->val);
		TreeNode* right = new TreeNode(node->next->val);

		root->right = right;

		return root;
	}

	ListNode* h1 = node;
	ListNode* h2 = NULL;
	ListNode* m = node;
	int half = len / 2;

	while (half--)
	{
		m = m->next;
	}

	h2 = m->next;

	TreeNode* root = new TreeNode(m->val);
	root->left = getThree(h1, len / 2);
	root->right = getThree(h2,len - len / 2 - 1);

	return root;
}

TreeNode *sortedListToBST(ListNode *head) 
{
	if (!head)	return NULL;

	ListNode* node = head;

	int len = 0;
	while (node)
	{
		len++;

		node = node->next;
	}

	return getThree(head, len);
}


int main()
{
	return 1;
}