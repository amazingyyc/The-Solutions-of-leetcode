#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

	For example, given array S = {-1 2 1 -4}, and target = 1.

	The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).                                                                     */
/************************************************************************/

int threeSumClosest(vector<int> &num, int target) 
{
	//½øÐÐÅÅÐò
	sort(num.begin(), num.end());
	int size = num.size();
	int closeSum = num[0] + num[1] + num[2];

	for (int i = 0; i < size - 2; ++i)
	{
		int l = i + 1;
		int r = size - 1;

		while (l < r)
		{
			int sum = num[i] + num[l] + num[r];

			if (sum == target)
				return sum;
			else if (sum > target)
				r--;
			else
				l++;

			closeSum = abs(sum - target) < abs(closeSum - target) ? sum : closeSum;
		}
	}

	return closeSum;
}

int main()
{
	vector<int> num;
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-4);

	int closeSum = threeSumClosest(num, 1);

	return 1;
}