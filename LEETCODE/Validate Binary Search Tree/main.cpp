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

 //ÅÐ¶ÏÒ»¸öÊ÷ÊÇ·ñ·ûºÏ¶þ²æËÑË÷Ê÷

 bool isValidBST(TreeNode *root) 
 {
	 if (NULL == root)	return true;

	 int first = true;
	 int pre = INT_MIN;
	 TreeNode* t = root;
	 stack<TreeNode*> stac;

	 while (t || !stac.empty())
	 {
		 while (t)
		 {
			 stac.push(t);
			 t = t->left;
		 }

		 TreeNode* top = stac.top();
		 stac.pop();

		 if (first || pre < top->val)
		 {
			 first = false;
			 pre = top->val;
		 }
		 else
			 return false;

		 t = top->right;
	 }

	 return true;
 }


int main()
{
	TreeNode t(0);

	isValidBST(&t);

	return 1;
}