#include <iostream>

using namespace std;

/************************************************************************/
/* 
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
/************************************************************************/



struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool pathSum(TreeNode* node, int pre, int sum)
{
	if (NULL == node)	
		return false;

	int temp = pre + node->val;

	if (NULL == node->left && NULL == node->right)
		return temp == sum;

	return pathSum(node->left, temp, sum) || pathSum(node->right, temp, sum);
}

bool hasPathSum(TreeNode *root, int sum) 
{
	return pathSum(root, 0, sum);
}


int main()
{
	return 1;
}