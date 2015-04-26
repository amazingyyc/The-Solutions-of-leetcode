#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/************************************************************************/
/* 
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
1            <---
/   \
2     3         <---
\     \
5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
*/
/************************************************************************/



struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*vector<int> rightSideView(TreeNode *root) 
{
	vector<int> result;

	if (!root)	return result;

	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		TreeNode* top = NULL;

		int size = que.size();
		while (size--)
		{
			top = que.front();
			que.pop();

			if (top->left)	que.push(top->left);
			if (top->right)	que.push(top->right);

			if (0 == size)	result.push_back(top->val);
		}
	}

	return result;
}*/

void view(TreeNode* node, int level, vector<int> &result)
{
	if (NULL == node)	return;

	if (level >= result.size())
		result.push_back(node->val);
	else
		result[level] = node->val;

	view(node->left, level + 1, result);
	view(node->right, level + 1, result);
}

vector<int> rightSideView(TreeNode *root)
{
	vector<int> result;

	view(root, 0, result);

	return result;
}


int main()
{
	return 1;
}