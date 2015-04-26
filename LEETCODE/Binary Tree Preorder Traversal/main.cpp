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

//œ»–Ú±È¿˙
vector<int> preorderTraversal(TreeNode *root) 
{
	vector<int> result;

	if (!root)	return result;

	stack<TreeNode*> stac;
	stac.push(root);

	while (!stac.empty())
	{
		TreeNode* top = stac.top();
		stac.pop();

		result.push_back(top->val);

		if (top->right)	stac.push(top->right);
		if (top->left)	stac.push(top->left);
	}

	return result;
}

int main()
{
	return 1;
}