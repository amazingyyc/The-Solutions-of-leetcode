#include <iostream>
#include <stack>

using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getLeftDepth(TreeNode* root)
{
	int depth = 0;

	while (root)
	{
		depth++;
		root = root->left;
	}

	return depth;
}

int countNodes(TreeNode* root) 
{
	int l, r;
	int sum = 0;

	while (root)
	{
		l = getLeftDepth(root->left);
		r = getLeftDepth(root->right);

		if (l == r)
		{
			sum += (1 << l);
			root = root->right;
		}
		else
		{
			sum += (1 << r);
			root = root->left;
		}
	}

	return sum;
}

int main()
{
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(4);

	n1.left = &n2;
	n1.right = &n3;

	int num = countNodes(&n1);

	return 0;
}