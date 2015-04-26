#include <iostream>

using namespace std;

/************************************************************************/
/* 
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following is not:
1
/ \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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

bool isSame(TreeNode* l, TreeNode* r)
{
	if (NULL == l && NULL != r)return false;
	if (NULL != l && NULL == r)return false;

	if (NULL == l && NULL == r)return true;

	if (l->val != r->val)return false;

	return isSame(l->left, r->right) && isSame(l->right, r->left);
}

bool isSymmetric(TreeNode *root) 
{
	if (NULL == root)	return true;

	return isSame(root->left, root->right);
}


int main()
{
	return 1;
}