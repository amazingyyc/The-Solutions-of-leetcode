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

int kthSmallest(TreeNode* root, int k) 
{
	stack<TreeNode*> sta;

	TreeNode* t = root;

	while (!sta.empty() || t)
	{
		while (t)
		{
			sta.push(t);
			t = t->left;
		}

		TreeNode* top = sta.top();
		sta.pop();

		k--;

		if (0 == k)
			return top->val;

		t = top->right;
	}

	return -1;
}


int main()
{
	return 0;
}