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

 //���ص�ǰ�����߶� �����ǰ��������ƽ��ľͷ���-1
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