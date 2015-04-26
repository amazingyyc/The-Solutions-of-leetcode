#include <iostream>

using namespace std;

/*
从n的阶层中找出第k个 返回
*/

int getNumber(int number[], int n, int k)
{
	//从数组number中找到k小的数 从0开始计算
	int count = -1;

	for (int i = 0; i <= n; ++i)
	{
		if (0 == number[i])
		{
			count++;

			if (count == k)
				return i;
		}
	}

	return -1;
}

string getPermutation(int n, int k)
{
	int sum = 1;

	for (int i = 1; i <= n; ++i)
		sum *= i;

	if (0 >= k || k > sum)
		return "";

	//将k减一 从0开始 计算
	k--;

	int number[10] = {0};	//用这个数组存储当前得数是否被使用 例如如果5已经被使用这number[5] = 1 否则为0
	string str[10] = {"0","1","2","3","4","5","6","7","8", "9"};
	number[0] = 1;
	int d = n;
	string re = "";

	while (d > 0)
	{
		sum /= d;

		int s = k / sum;
		k = k % sum;

		int c = getNumber(number, n, s);

		if (-1 != c)
		{
			number[c] = 1;

			re += str[c];
		}
		else
			return "";

		d--;
	}

	return re;
}

int main()
{
	string re = getPermutation(5, 10);

	return 1;
}