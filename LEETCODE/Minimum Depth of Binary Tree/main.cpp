#include <iostream>
#include <algorithm>

using namespace std;

/************************************************************************/
/* 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
/************************************************************************/


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void depth(TreeNode* node, int pre, int* minDep)
{
	if (!node)	return;

	pre++;

	if (!node->left && !node->right)
	{
		(*minDep) = min(pre, *minDep);
		
		return;
	}
	
	depth(node->left, pre, minDep);
	depth(node->right, pre, minDep);
}

int minDepth(TreeNode *root) 
{
	if (!root)	return 0;

	int minDep = INT_MAX;

	depth(root, 0, &minDep);

	return minDep;
}


int main()
{
	return 1;
}