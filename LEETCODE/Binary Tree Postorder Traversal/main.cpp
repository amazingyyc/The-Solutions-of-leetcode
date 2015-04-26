#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/************************************************************************/
/* 
∫Û–Ú±È¿˙
*/
/************************************************************************/


 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<int> postorderTraversal(TreeNode *root) 
{
	vector<int> result;

	if (NULL == root)	return result;

	stack<TreeNode*> stac;
	stac.push(root);

	while (!stac.empty())
	{
		TreeNode* top = stac.top();

		if (NULL != top->left)
			stac.push(top->left);
		else if (NULL != top->right)
			stac.push(top->right);
		else
		{
			while (1)
			{
				top = stac.top();
				result.push_back(top->val);
				stac.pop();

				if (stac.empty())break;
				
				TreeNode* temp = stac.top();

				if (temp->left == top && NULL != temp->right)
				{
					stac.push(temp->right);

					break;
				}
			}
		}
	}

	return result;
}


int main()
{
	return 1;
}