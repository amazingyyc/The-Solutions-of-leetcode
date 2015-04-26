#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> &inorder, int iS, int iE, vector<int> &postorder, int pS, int pE)
{
	if (iS > iE)	return NULL;

	int val = postorder[pE];
	int m;
	for (int i = iS; i <= iE; ++i)
	{
		if (inorder[i] == val)
		{
			m = i;
			break;
		}
	}

	int len = iE - m;

	TreeNode* root = new TreeNode(val);
	root->left = buildTree(inorder, iS, m - 1, postorder, pS, pE - len - 1);
	root->right = buildTree(inorder, m + 1, iE, postorder, pE - len, pE - 1);

	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
{
	int size = inorder.size();
	if (0 == size || inorder.size() != postorder.size())
		return NULL;

	return buildTree(inorder, 0, size - 1, postorder, 0, size - 1);
}

int main()
{
	return 1;
}