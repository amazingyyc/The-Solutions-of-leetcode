#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
/************************************************************************/

int findMin(vector<int> &num) 
{
	int l = 0;
	int r = num.size() - 1;

	while (l < r)
	{
		int m = (l + r)/2;

		if (num[m] > num[r])
			l = m + 1;
		else
			r = m;
	}

	return num[l];
}

int main()
{
	vector<int> num;
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);

	findMin(num);

	return 1;
}