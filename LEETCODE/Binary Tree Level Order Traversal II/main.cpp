#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/************************************************************************/
/* 
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
/************************************************************************/



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*void searchNodes(TreeNode* node, int level, vector<vector<int>> &result)
{
	if (NULL == node)return;

	if (level >= result.size())
		result.insert(result.begin(), vector<int>());

	result[result.size() - 1- level].push_back(node->val);

	searchNodes(node->left, level + 1, result);
	searchNodes(node->right, level + 1, result);
}

vector<vector<int> > levelOrderBottom(TreeNode *root) 
{
	vector<vector<int>> result;

	searchNodes(root, 0, result);

	return result;
}*/

//利用队列进行广度优先搜索
vector<vector<int> > levelOrderBottom(TreeNode *root)
{
	vector<vector<int>> result;

	if (NULL == root)	return result;

	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		vector<int> temp;

		TreeNode* front = NULL;

		int size = que.size();
		while (size--)
		{
			front = que.front();
			que.pop();

			temp.push_back(front->val);

			if (front->left)		que.push(front->left);
			if (front->right)	que.push(front->right);
		}

		result.push_back(temp);
	}

	reverse(result.begin(), result.end());

	return result;
}


int main()
{
	return 1;
}