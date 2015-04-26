#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
*/
/************************************************************************/

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sums(TreeNode* node, int pre, int sum, vector<int> &path, vector<vector<int>> &result)
{
	if (NULL == node)	return;

	pre += node->val;
	path.push_back(node->val);

	if (NULL == node->left && NULL == node->right)
	{
		if (pre == sum)
			result.push_back(path);

		path.pop_back();

		return;
	}

	sums(node->left, pre, sum, path, result);
	sums(node->right, pre, sum, path, result);

	path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum) 
{
	vector<vector<int>> result;
	vector<int> path;

	sums(root, 0, sum, path, result);

	return result;
}

int main()
{
	return 1;
}