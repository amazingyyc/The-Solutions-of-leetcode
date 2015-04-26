#include <iostream>

using namespace std;

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Related problem: Reverse Words in a String II

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

void rotate(int nums[], int l, int k, int r)
{
	if (l + 1 >= r || k == r || l == k)	return;

	if (r - k > k - l)
	{
		int x = r - k + l;

		for (int i = l, j = x; i < k&& j < r; ++i, ++j)
		{
			swap(nums[i], nums[j]);
		}

		rotate(nums, l, k, x);
	}
	else
	{
		int x = r - k + l;

		for (int i = l, j = k; i < x&& j < r; ++i, ++j)
		{
			swap(nums[i], nums[j]);
		}

		rotate(nums, x, k, r);
	}
}

/*void rotate(int nums[], int n, int k) 
{
	k = k % n ;

	rotate(nums, 0, n - k, n);
}*/

void rotate(int nums[], int n, int k)
{
	k = k % n;

	reverse(nums, nums + n - k);
	reverse(nums + n - k, nums + n);
	reverse(nums, nums + n);
}

int main(void)
{
	int nums[6] = { 1, 2, 3, 4, 5, 6 };

	rotate(nums, 6, 2);

	return 0;
}