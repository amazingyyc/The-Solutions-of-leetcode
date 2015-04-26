#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void recoverTree(TreeNode *root) 
{
	if (NULL == root) return;

	vector<TreeNode*> num;

	stack<TreeNode*> stac;
	TreeNode* t = root;
	TreeNode* pre = NULL;

	while (t || !stac.empty())
	{
		while (t)
		{
			stac.push(t);
			t = t->left;
		}

		TreeNode* top = stac.top();
		stac.pop();

		num.push_back(top);

		t = top->right;
	}

	int maxI = -1;
	int minI = -1;
	int size = num.size();

	for (int i = 0; i < size - 1; ++i)
	{
			if (num[i]->val > num[i + 1]->val)
			{
				maxI = i;

				break;
			}

	}

	for (int i = size - 1; i > 0; --i)
	{
			if (num[i]->val < num[i-1]->val)
			{
				minI = i;
				break;
			}
	}

	
	swap(num[maxI]->val, num[minI]->val);
}


int main()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);

	t1.left = &t2;
	t1.right = &t3;

	recoverTree(&t1);

	return 1;
}