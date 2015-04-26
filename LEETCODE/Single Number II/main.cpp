#include <iostream>

using namespace std;

/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

//计算每一位上1的个数
int singleNumber(int A[], int n) 
{
	const int len = sizeof(int)* 8;
	int count[len] = {0};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			count[j] += (A[i] >> j) & 1;
		}
	}

	int result = 0;
	for (int i = 0; i < len; ++i)
	{
		count[i] %= 3;

		result += (1 << i)*count[i];
	}

	return result;
}

int main()
{
	int A[] = { 1 };

	singleNumber(A, 1);

	return 1;
}