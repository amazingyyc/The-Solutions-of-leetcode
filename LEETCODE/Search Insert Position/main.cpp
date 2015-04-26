#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		if (target < A[l])
			return l;

		if (target > A[r])
			return r + 1;

		int m = (l + r) / 2;

		if (target == A[m])
			return m;
		else if (target < A[m])
			r = m - 1;
		else
			l = m + 1;
	}
}

int main()
{
	int A[] = { 1, 3, 5, 6 };

	int index = searchInsert(A, 4, 0);

	return 1;
}