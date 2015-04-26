#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/
/************************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int start, int end)
{
	vector<TreeNode*> result;

	if (start > end)
	{
		result.push_back(NULL);

		return result;
	}

	for (int i = start; i <= end; ++i)
	{
		vector<TreeNode*> left  = generateTrees(start, i - 1);
		vector<TreeNode*> right = generateTrees(i + 1, end);

		for (auto l : left)
		{
			for (auto r : right)
			{
				TreeNode* root = new TreeNode(i);
				root->left = l;
				root->right = r;

				result.push_back(root);
			}
		}
	}

	return result;
}

vector<TreeNode *> generateTrees(int n) 
{
	vector<TreeNode*> result;

	if (0 >= n)
	{
		result.push_back(NULL);

		return result;
	}

	return generateTrees(1, n);
}


int main()
{
	generateTrees(1);

	return 1;
}