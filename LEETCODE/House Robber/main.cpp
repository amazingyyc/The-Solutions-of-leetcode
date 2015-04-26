#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/

/*int rob(vector<int> &num) 
{
	int size = num.size();

	if (0 == size)	return 0;

	int* ro = new int[size];
	int* no = new int[size];

	ro[0] = num[0];
	no[0] = 0;

	for (int i = 1; i < size; ++i)
	{
		ro[i] = num[i] + no[i - 1];
		no[i] = max(ro[i - 1], no[i - 1]);
	}

	int temp = max(ro[size - 1], no[size - 1]);

	delete[] ro;
	delete[] no;

	return temp;
}*/

int rob(vector<int> &num)
{
	int size = num.size();

	if (0 == size)	return 0;

	int r = num[0];
	int n = 0;
	int temp;

	for (int i = 1; i < size; ++i)
	{
		temp = r;

		r = n + num[i];
		n = max(temp, n);
	}

	return max(r, n);
}

int main()
{
	return 1;
}