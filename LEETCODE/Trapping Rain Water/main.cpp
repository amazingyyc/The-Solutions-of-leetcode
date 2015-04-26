#include <iostream>

using namespace std;

/*
存储最多的水
*/

int trap(int A[], int n)
{
	if (2 >= n)
		return 0;

	/*
	l存储左边的最大高度在的位置 lH为对应的高度
	r存储右边最大的高度 rH为对应的值 
	*/
	int l = 0;
	int r = 1;
	int maxH = r;	//存储中间遇到的最高值

	int sum = 0;	//总的容量

	while (r < n)
	{
		if (A[r] < A[l])
		{
			if (A[r] > A[maxH])
				maxH = r;

			r++;
		}
		else if ( (l+1) != r )
		{
			for (int k = l + 1; k < r; ++k)
			{
				sum += A[l] - A[k];
			}

			l = r;
			r++;

			maxH = r;
		}
		else
		{
			l++;
			r++;

			maxH = r;
		}
	}

	//这时l 存储一个最左边的数值 二maxH存储从l开始的最右面的最高值
	while (l < n - 1)
	{
		for (int k = l + 1; k < maxH; ++k)
			sum += A[maxH] - A[k];

		l = maxH;

		maxH = l + 1;
		for (int i = l + 1; i < n; ++i)
		{
			if (A[i] > A[maxH])
				maxH = i;
 		}
	}

	return sum;
}

int main()
{
	int A[12] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

	int sum = trap(A, 12);

	return 1;
}