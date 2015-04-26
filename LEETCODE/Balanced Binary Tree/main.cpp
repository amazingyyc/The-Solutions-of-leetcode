#include <iostream>
#include <algorithm>

using namespace std;

 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //返回当前子树高度 如果当前子树不是平衡的就返回-1
 int getDepth(TreeNode* node)
 {
	 if (NULL == node)	return 0;

	 int left = getDepth(node->left);
	 if (-1 == left)		return -1;

	 int right = getDepth(node->right);
	 if (-1 == right)	return -1;

	 int temp = left - right;

	 if (temp > 1 || temp < -1)
		 return -1;

	 return max(left, right) + 1;
 }

 bool isBalanced(TreeNode *root) 
 {
	 return getDepth(root) != -1;
 }

int main()
{
	return 1;
}