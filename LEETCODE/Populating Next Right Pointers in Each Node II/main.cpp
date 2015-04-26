#include <iostream>

using namespace std;

/************************************************************************/
/* 
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
1
/  \
2    3
/ \    \
4   5    7
After calling your function, the tree should look like:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL
*/
/************************************************************************/


struct TreeLinkNode 
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* getNext(TreeLinkNode* start)
{
	while (start)
	{
		if (start->left) return start->left;
		if (start->right) return start->right;

		start = start->next;
	}

	return NULL;
}

void connect(TreeLinkNode *root) 
{
	if (NULL == root)return;

	root->next = NULL;
	TreeLinkNode* start = root;

	while (start)
	{
		TreeLinkNode* nextStart = getNext(start);

		while (start)
		{
			TreeLinkNode* next = getNext(start->next);

			if (start->left)
				start->left->next = (NULL != start->right) ? start->right : next;

			if (start->right)
				start->right->next = next;

			start = start->next;
		}

		start = nextStart;
	}
}


int main()
{
	TreeLinkNode t(0);

	connect(&t);

	return 1;
}