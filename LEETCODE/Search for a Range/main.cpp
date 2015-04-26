#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(int A[], int n, int target) 
{
	int l = 0;
	int r = n - 1;
	int index = -1;

	while (l <= r)
	{
		int m = (l + r) / 2;

		if (target == A[m])
		{
			index = m;

			break;
		}
		else if (target > A[m])
			l = m + 1;
		else
			r = m - 1;
	}

	vector<int> re;

	if (-1 == index)
	{
		re.push_back(-1);
		re.push_back(-1);

		return re;
	}

	l = r = index;

	while (l - 1 >= 0 && A[l - 1] == target)
		l--;
	while (r + 1 < n && A[r + 1] == target)
		r++;

	re.push_back(l);
	re.push_back(r);

	return re;
}

int main()
{
	return 1;
}