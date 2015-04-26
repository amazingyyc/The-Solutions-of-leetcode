#include <iostream>
#include <vector>
#include <stack>

using namespace std;


 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 /************************************************************************/
 /*
 ÖÐÐò±éÀú
 */
 /************************************************************************/

 vector<int> inorderTraversal(TreeNode *root)
 {
	 vector<int> result;
	 stack<TreeNode*> stac;

	 TreeNode* t = root;

	 while (t || !stac.empty())
	 {
		 if (t)
		 {
			 stac.push(t);
			 t = t->left;
		 }
		 else
		 {
			 t = stac.top();
			 stac.pop();

			 result.push_back(t->val);
			 t = t->right;
		 }
	 }

	 return result;
 }

 /*vector<int> inorderTraversal(TreeNode *root) 
 {
	 vector<int> result;
	 stack<TreeNode*> stac;

	 if (NULL == root)	return result;

	 stac.push(root);

	 while (!stac.empty())
	 {
		 TreeNode* top = stac.top();
		 while (NULL != top->left)
		 {
			 top = top->left;
			 stac.push(top);
		 }

		 do 
		 {
			 top = stac.top();
			 stac.pop();

			 result.push_back(top->val);
		 } while (!stac.empty() && NULL == top->right);

		 if (NULL != top->right)
			 stac.push(top->right);
	 }

	 return result;
 }*/

int main()
{
	return 1;
}