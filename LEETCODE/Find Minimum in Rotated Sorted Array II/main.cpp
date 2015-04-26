#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/
/************************************************************************/

/*int getMin(vector<int> &num, int l, int r)
{
	if (l == r - 1)
		return min(num[l], num[r]);

	while (l < r)
	{
		int m = (l + r) / 2;

		if (num[m] > num[r])
			l = m + 1;
		else if (num[l] == num[m] && num[m] == num[r])
			return min(getMin(num, l, m - 1), getMin(num, m, r));
		else
			r = m;
	}

	return num[l];
}

int findMin(vector<int> &num) 
{
	return getMin(num, 0, num.size() - 1);
}*/

int finMin(vector<int> &num)
{
	int l = 0;
	int r = num.size() - 1;

	while (l < r)
	{
		int m = (l + r) >> 1;

		if (num[m] > num[r])
			l = m + 1;
		else if (num[l] == num[m] && num[m] == num[r])
			l++;
		else
			r = m;
	}

	return num[l];
}

int main()
{
	return 1;
}