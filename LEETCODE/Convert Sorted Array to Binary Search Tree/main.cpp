#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 TreeNode* getRoot(vector<int> &num, int l, int r)
 {
	 if (l > r)	return NULL;
	 if (l == r) return new TreeNode(num[l]);
	 
	 int mid = (l + r)/2;
	 TreeNode* root = new TreeNode(num[mid]);
	 root->left = getRoot(num, l, mid - 1);
	 root->right = getRoot(num, mid + 1, r);

	 return root;
 }

 TreeNode *sortedArrayToBST(vector<int> &num) 
 {
	 return getRoot(num, 0, num.size() - 1);
 }

 int main()
 {
	 vector<int> num;
	 num.push_back(3);
	 num.push_back(5);
	 num.push_back(8);

	 sortedArrayToBST(num);

	 return 1;
 }