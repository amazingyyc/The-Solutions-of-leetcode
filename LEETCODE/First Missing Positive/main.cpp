#include <iostream>
#include <unordered_map>

using namespace std;

/************************************************************************/
/* 
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
/************************************************************************/

int firstMissingPositive(int A[], int n) 
{
	unordered_map<int, int> maps;

	for (int i = 0; i < n; ++i)
		maps[A[i]]++;

	for (int i = 1;; ++i)
	{
		if (maps.find(i) == maps.end())
			return i;
	}
}

int main()
{
	return 1;
}