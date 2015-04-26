#include <iostream>

using namespace std;

/*
‘ –Ì÷ÿ∏¥
*/

bool search(int A[], int n, int target)
{
	int l = 0;
	int r = n - 1;

	while (l <= r)
	{
		int m = (l + r) / 2;

		if (target == A[m])
			return true;

		if (A[l] < A[m])
		{
			if (target >= A[l] && target < A[m])
				r = m - 1;
			else
				l = m + 1;
		}
		else if (A[l] > A[m])
		{
			if (target > A[m] && target <= A[r])
				l = m + 1;
			else
				r = m - 1;
		}
		else
			l++;
	}

	return false;
}

int main()
{
	int A[5] = { 1, 3, 1, 1, 1 };

	bool re = search(A, 5, 5);

	return 1;
}