#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxPathSum(TreeNode *root, int *maxSum)
{
	if (NULL == root)	return 0;

	int left = maxPathSum(root->left, maxSum);
	int right = maxPathSum(root->right, maxSum);

	int sum = root->val + left + right;

	*maxSum = max(sum, *maxSum);

	return max(root->val + max(left, right), 0);
}

int maxPathSum(TreeNode *root) 
{
	if (NULL == root)
		return 0;

	int maxSum = INT_MIN;

	maxPathSum(root, &maxSum);

	return maxSum;
}


int main()
{
	return 1;
}