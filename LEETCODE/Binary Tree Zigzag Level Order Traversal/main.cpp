#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


vector<vector<int> > zigzagLevelOrder(TreeNode *root) 
{
	vector<vector<int>> result;

	if (NULL == root)	return result;

	bool direct = true;
	queue<TreeNode*> que;
	que.push(root);

	while (!que.empty())
	{
		int size = que.size();
		int index = 0;
		vector<int> temp(size);

		while (size--)
		{
			TreeNode* top = que.front();
			que.pop();

			if (direct)
				temp[index++] = top->val;
			else
				temp[size] = top->val;

			if (top->left) que.push(top->left);
			if (top->right) que.push(top->right);
		}

		direct = !direct;
		result.push_back(temp);
	}

	return result;
}


int main()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);

	t1.left = &t2;
	t1.right = &t3;

	zigzagLevelOrder(&t1);

	return 1;
}