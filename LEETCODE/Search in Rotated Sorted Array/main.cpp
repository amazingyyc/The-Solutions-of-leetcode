#include <iostream>

using namespace std;

int search(int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m = (l + r) / 2;

		if (target == A[m])
			return m;

		if (A[l] <= A[m] && A[m] <= A[r])
		{
			if (target > A[m])
				l = m + 1;
			else
				r = m - 1;
		}

		if (A[r] <= A[l] && A[l] <= A[m])
		{
			if (target < A[m] && target >= A[l])
				r = m - 1;
			else
				l = m + 1;
		}

		if (A[m] <= A[r] && A[r] <= A[l])
		{
			if (target > A[m] && target <= A[r])
				l = m + 1;
			else
				r = m - 1;
		}
	}

	return -1;
}

int main()
{
	int A[7] = { 4, 5, 6, 7, 0, 1, 2 };

	int index = search(A, 7, 52);

	return 1;
}