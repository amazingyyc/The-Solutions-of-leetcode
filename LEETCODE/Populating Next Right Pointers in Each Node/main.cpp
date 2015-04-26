#include <iostream>

using namespace std;

struct TreeLinkNode 
{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

/*void addNext(TreeLinkNode* cur, TreeLinkNode* next)
{
	if (NULL == cur)	return;

	cur->next = next;

	addNext(cur->left, cur->right);
	addNext(cur->right, (NULL == next) ? NULL : next->left);
}

void connect(TreeLinkNode *root) 
{
	addNext(root, NULL);
}*/

//一层一层的添加 当前层可以
void connect(TreeLinkNode* root)
{
	root->next = NULL;
	TreeLinkNode* cur = root;

	while (cur)
	{
		TreeLinkNode* nextSart = cur->next;

		while(cur)
		{
			if (cur->left)
				cur->left->next = cur->right;
			if (cur->right)
				cur->right->next = (cur->next) ? cur->next->left : NULL;

			cur = cur->next;
		}

		cur = nextSart;
	}
}

int main()
{
	return 1;
}