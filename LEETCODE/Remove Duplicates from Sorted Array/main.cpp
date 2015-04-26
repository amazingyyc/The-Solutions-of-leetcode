#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
	/*
	三个指针 
	fr只想当前重复的数的第一个位置 
	se只想当前重复的下一个位置
	th指向从开始的所有不重复的最后一个 位置 如果se th只包含一个表示 存在重复或者 只有一个不重复
	*/
	/*if (0 == n)
		return 0;

	int fr = 0;
	int se = 1;
	int th = 1;

	while (se < n)
	{
		while ((se + 1) < n && A[se + 1] == A[se])
		{
			se++;
		}

		th = se;

		while ((th + 1) < n && A[th + 1] != A[th])
		{
			th++;
		}

		if ((fr + 1) != se)
		{
			for (int k = se; k <= th; ++k)
				A[++fr] = A[k];
		}

		se++;
	}

	return fr + 1;*/

	if (0 == n)
		return 0;

	int index = 0;

	for (int i = 1; i < n; ++i)
	{
		if (A[index] != A[i])
		{
			if ((index + 1) != i)
				A[++index] = A[i];
			else
				index++;
		}
	}

	return index + 1;
}

int main()
{


	return 1;
}