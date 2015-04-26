#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/************************************************************************/
/* 
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.
*/
/************************************************************************/

/*int maximumGap(vector<int> &num) 
{
	int size = num.size();
	if (2 > size)	return 0;

	sort(num.begin(), num.end());

	int incre = 1;

	for (int i = 1; i < size; ++i)
	{
		incre = max(num[i] - num[i - 1], incre);
	}

	return incre;
}*/

//利用桶排序算法
int maximumGap(vector<int> &num)
{
	int n = num.size();
	if (2 > n)	return 0;

	int minNum = INT_MAX;
	int maxNum = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		minNum = min(minNum, num[i]);
		maxNum = max(maxNum, num[i]);
	}

	//最大的 gap>=len 所以 最大的gap一定在两个不同的桶内 
	int len = ceil((maxNum - minNum) / (n - 1));		//每个桶的大小
	len = (0 == len) ? 1 : len;
	int b = (maxNum - minNum) / len + 1;		//桶的个数

	int** buckets = new int*[3];
	for (int i = 0; i < 3; ++i)
		buckets[i] = new int[b];

	for (int i = 0; i < b; ++i)
	{
		buckets[0][i] = 0;
		buckets[1][i] = INT_MAX;
		buckets[2][i] = INT_MIN;
	}

	for (int i = 0; i < n; ++i)
	{
		int c = (num[i] - minNum) / len;

		buckets[0][c]++;
		buckets[1][c] = min(num[i], buckets[1][c]);
		buckets[2][c] = max(num[i], buckets[2][c]);
	}
	
	int gap = INT_MIN;
	int start = -1;
	for (int i = 0; i < b; ++i)
	{
		if (0 != buckets[0][i])
		{
			if (-1 == start)
				start = i;
			else
			{
				gap = max(gap, buckets[1][i] - buckets[2][start]);
				start = i;
			}
		}
	}

	for (int i = 0; i < 3; ++i)
		delete[] buckets[i];

	delete[] buckets;

	return gap;
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(1);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	num.push_back(5);
	//num.push_back(2);
	//num.push_back(1);
	//num.push_back(7);
	//num.push_back(8);
	//num.push_back(6);
	//num.push_back(6);
	//num.push_back(6);

	cout << maximumGap(num);

	

	return 1;
}