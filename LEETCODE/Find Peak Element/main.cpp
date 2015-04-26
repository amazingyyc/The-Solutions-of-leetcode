#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
/************************************************************************/

int findPeakElement(const vector<int> &num) 
{
	int size = num.size();

	if (0 == size) return -1;
	if (1 == size) return 0;

	if (num[0] > num[1])return 0;
	if (num[size - 1] > num[size - 2]) return size - 1;

	int l = 0;
	int r = size - 1;;

	while (l < r)
	{
		int m = (l + r) / 2;

		if (num[m] > num[m + 1])
			r = m;
		else
			l = m;
	}

	return l;
}

int main()
{
	return 1;
}