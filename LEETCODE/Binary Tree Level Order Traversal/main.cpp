#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/************************************************************************/
/* 
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
/************************************************************************/


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//广度优先搜索
vector<vector<int> > levelOrder(TreeNode *root) 
{
	vector<vector<int>> result;

	if (NULL == root)	return result;

	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		vector<int> temp;
		TreeNode* top = NULL;

		int size = que.size();
		while (size--)
		{
			top = que.front();
			que.pop();

			temp.push_back(top->val);

			if (top->left)que.push(top->left);
			if (top->right)que.push(top->right);
		}

		result.push_back(temp);
	}

	return result;
}




int main()
{
	return 1;
}