#include <iostream>
#include <stack>

using namespace std;

/************************************************************************/
/* 
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2   5
/ \   \
3   4   6
The flattened tree should look like:
1
\
2
\
3
\
4
\
5
\
6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/
/************************************************************************/


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void flatten(TreeNode *root)
{
	if (!root)	return;

	TreeNode* tail = new TreeNode(-1);
	TreeNode* temp = tail;

	stack<TreeNode*> stac;
	stac.push(root);

	while (!stac.empty())
	{
		TreeNode* top = stac.top();
		stac.pop();

		if (top->right) stac.push(top->right);
		if (top->left) stac.push(top->left);

		top->left = NULL;
		tail->right = top;
		tail = top;
	}

	delete  temp;
}


int main()
{
	return 1;
}