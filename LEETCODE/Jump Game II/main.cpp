#include <iostream>
#include <algorithm>

using namespace std;

int jump(int A[], int n) 
{
	//存储到step[k] 存储到k的最少步数
	int* step = (int *)malloc(sizeof(int)* n);
	for (int i = 0; i < n; ++i)
		step[i] = -1;

	step[0] = 0;

	int endStep = 1;	//用于加速

	for (int i = 0; i < n; ++i)
	{
		int end = i + A[i] + 1;

		int j = endStep;

		for (; j < end && j < n; ++j)
		{
			if (-1 == step[j])
				step[j] = step[i] + 1;

			if (j == n - 1)
			{
				int re = step[j];

				free(step);

				return re;
			}
		}

		if (j > endStep)
			endStep = j;
	}

	return step[n - 1];
}

int main()
{
	int A[5] = { 2, 3, 1, 1, 4 };

	int re = jump(A, 5);

	return 1;
}