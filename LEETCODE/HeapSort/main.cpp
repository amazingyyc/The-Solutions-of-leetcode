#include <iostream>

using namespace std;

/************************************************************************/
/*
堆排序
*/
/************************************************************************/

//修正堆  在数组A终修正k大堆
void fixDown(int A[], int k, int n)
{
	while (k + k <= n)
	{
		int j = k + k;

		if (j < n && A[j] < A[j + 1])	j++;
		if (A[k] >= A[j])	break;

		swap(A[k], A[j]);

		k = j;
	}
}

void heapSort(int A[], int N)
{
	A--;

	for (int i = N / 2; i >= 1; --i)
		fixDown(A, i, N);

	int num = N;

	while (num > 1)
	{
		swap(A[1], A[num]);

		fixDown(A, 1, --num);
	}
}

int main()
{
	int A[10] = {5, -6, 34, 34, 509, -90, 21, 405, 56, 12};

	heapSort(A, 10);

	return 1;
}