#include <iostream>
#include <stack>

using namespace std;

/************************************************************************/
/* 
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
/************************************************************************/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator 
{
private:
	TreeNode* t = NULL;
	stack<TreeNode*> stac;

public:
	BSTIterator(TreeNode *root) 
	{
		t = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		return t || !stac.empty();
	}

	/** @return the next smallest number */
	int next() 
	{
		while (t)
		{
			stac.push(t);
			t = t->left;
		}

		TreeNode* top = stac.top();
		stac.pop();

		t = top->right;

		return top->val;
	}
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/

int main()
{
	return 1;
}