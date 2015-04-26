#include <iostream>

using namespace std;

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void totalSum(TreeNode* node, int pre, int* sum)
{
	pre = pre * 10 + node->val;

	TreeNode* left = node->left;
	TreeNode* right = node->right;

	if (NULL == left && NULL == right)
	{
		(*sum) += pre;

		return;
	}

	if (NULL == left)
		totalSum(right, pre, sum);
	else if (NULL == right)
		totalSum(left, pre, sum);
	else
	{
		totalSum(left, pre, sum);
		totalSum(right, pre, sum);
	}
}

int sumNumbers(TreeNode *root) 
{
	if (NULL == root)
		return 0;

	int sum = 0;

	totalSum(root, 0, &sum);

	return sum;
}


int main()
{
	return 1;
}