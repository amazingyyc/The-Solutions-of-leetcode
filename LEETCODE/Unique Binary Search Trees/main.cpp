#include <iostream>

using namespace std;

/************************************************************************/
/* 

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/
/************************************************************************/

int numTrees(int n) 
{
	if (0 == n || 1 == n)	return 1;

	int *nums = new int[n + 1];
	nums[0] = 1;
	nums[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		nums[i] = 0;

		for (int j = 0; j < i; ++j)
		{
			nums[i] += nums[j] * nums[i - 1 - j];
		}
	}

	int re = nums[n];

	delete[] nums;

	return re;
}

int main()
{
	numTrees(2);

	return 1;
}