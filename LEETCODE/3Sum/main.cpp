#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/*                                       
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)                               */
/************************************************************************/

//从一个排序的数组中查找是否存在 当前值 存在返回 指针 否则返回-1
/*bool findNumber(vector<int> &num, int l, int r, int target)
{
	while (l <= r)
	{
		int m = (l + r) / 2;

		if (num[m] == target)
			return true;
		else if (num[m] > target)
			r = m - 1;
		else
			l = m + 1;
	}

	return false;
}

vector<vector<int> > threeSum(vector<int> &num) 
{
	vector<vector<int>> re;

	//进行排序
	sort(num.begin(), num.end());
	int size = num.size();

	for (int i = 0; i < size - 2; ++i)
	{
		if (0 < i && num[i] == num[i - 1])
			continue;

		for (int j = i + 1; j < size - 1; ++j)
		{
			if (j > i + 1 && num[j] == num[j - 1])
				continue;

			int temp = 0 - num[i] - num[j];

			if (temp >= num[j] && findNumber(num, j + 1, size - 1, temp))
			{
				vector<int> r;
				r.push_back(num[i]);
				r.push_back(num[j]);
				r.push_back(temp);

				re.push_back(r);
			}
		}
	}

	return re;
}*/

vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int>> result;

	//进行排序
	sort(num.begin(), num.end());
	int size = num.size();

	for (int i = 0; i < size - 2; ++i)
	{
		//两边向中间 
		if (i > 0 && num[i] == num[i-1])		continue;

		int l = i + 1;
		int r = size - 1;

		while (l < r)
		{
			int target = num[i] + num[l] + num[r];

			if (0 == target)
			{
				vector<int> re;
				re.push_back(num[i]);
				re.push_back(num[l]);
				re.push_back(num[r]);

				result.push_back(re);

				while (num[++l] == num[l - 1]);
				while (num[--r] == num[r + 1]);
			}
			else if (0 > target)
				while (num[++l] == num[l - 1]);
			else
				while (num[--r] == num[r + 1]);
		}
	}

	return result;
}

int main()
{
	vector<int> num;
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(-4);
	num.push_back(-1);

	threeSum(num);

	return 1;
}