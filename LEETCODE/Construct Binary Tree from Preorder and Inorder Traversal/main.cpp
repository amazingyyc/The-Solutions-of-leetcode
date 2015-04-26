#include <iostream>
#include <vector>

using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> &preorder, int pS, int pE, vector<int> &inorder, int iS, int iE)
{
	if (pS > pE)	return NULL;

	int val = preorder[pS];
	int m;
	for (int i = iS; i <= iE; ++i)
	{
		if (inorder[i] == val)
		{
			m = i;
			break;
		}
	}

	int len = m - iS;

	TreeNode* root = new TreeNode(val);
	root->left = buildTree(preorder, pS + 1, pS + len, inorder, iS, m - 1);
	root->right = buildTree(preorder, pS + len + 1, pE, inorder, m + 1, iE);

	return root;
}


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
{
	int size = preorder.size();
	if (0 == size || preorder.size() != inorder.size())
		return NULL;

	return buildTree(preorder, 0, size - 1, inorder, 0, size - 1);
}


int main()
{
	return 1;
}