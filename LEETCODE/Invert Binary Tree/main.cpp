#include <iostream>
#include <queue>

using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* invertTree(TreeNode* root) 
{
	if (NULL == root)	return NULL;

	swap(root->left, root->right);

	invertTree(root->left);
	invertTree(root->right);

	return root;
}

TreeNode* invertTreeUseQueue(TreeNode* root)
{
	if (NULL == root)	return NULL;

	queue<TreeNode*> que;
	que.push(root);

	TreeNode* top;

	while (!que.empty())
	{
		top = que.front();
		que.pop();

		swap(top->left, top->right);

		if (top->left)
			que.push(top->left);
		if (top->right)
			que.push(top->right);
	}

	return root;
}


int main()
{
	return 0;
}