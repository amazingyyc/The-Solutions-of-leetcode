#include <iostream>
#include <algorithm>

using namespace std;

/************************************************************************/
/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
/************************************************************************/

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int maxDepth(TreeNode *root)
{
	if (NULL == root)	return 0;

	return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
}


int main()
{
	return 1;
}