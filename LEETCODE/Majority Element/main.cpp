#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/************************************************************************/
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
/************************************************************************/

/*int majorityElement(vector<int> &num) 
{
	unordered_map<int, int> map;

	int size = num.size();
	int time = size / 2;
	for (int i = 0; i < size; ++i)
	{
		map[num[i]]++;

		if (map[num[i]] >= time)
			return num[i];
	}


	return -1;
}*/

/*int majorityElement(vector<int> &num)
{
	sort(num.begin(), num.end());

	return num[num.size() / 2];
}*/

int majorityElement(vector<int> &num)
{
	int result = -1;
	int count = 0;
	int size = num.size();

	for (int i = 0; i < size; ++i)
	{
		if (0 == count)
		{
			result = num[i];
			count++;
		}
		else if (result != num[i])
			count--;
		else
			count++;
	}
}

int main()
{


	return 1;
}