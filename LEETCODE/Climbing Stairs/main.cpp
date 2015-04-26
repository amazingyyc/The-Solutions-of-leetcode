#include <iostream>

using namespace std;

/*
��¥�� ÿ��ֻ����1����2�� ����n�м��ַ���
*/

int climbStairs(int n)
{
	if (1 == n)
		return 1;

	if (2 == n)
		return 2;

	int left2 = 1;
	int left1 = 2;

	for (int i = 3; i < n; ++i)
	{
		int left = left2 + left1;

		left2 = left1;
		left1 = left;
	}

	return left1 + left2;
}

int main()
{


	return 1;
}