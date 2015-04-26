#include <iostream>
#include <stdlib.h>

using namespace std;

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/


int numDecodings(string s) 
{
	int n = s.size();
	if (0 == n)	return 0;

	int* nums = new int[n+1];
		
	nums[0] = 1;

	int temp = atoi(s.substr(0, 1).c_str());

	if (1 <= temp && temp <= 9)
		nums[1] = 1;
	else
		return 0;

	for (int i = 2; i <= n; ++i)
	{
		nums[i] = 0;

		temp = atoi(s.substr(i - 2, 2).c_str());
		if (10 <= temp && temp <= 26)
			nums[i] += nums[i - 2];

		temp = atoi(s.substr(i - 1, 1).c_str());
		if (1 <= temp && temp <= 9)
			nums[i] += nums[i - 1];

		if (0 == nums[i])
		{
			nums[n] = 0;
			break;
		}
			
	}

	int num = nums[n];

	delete[] nums;

	return num;
}

int main()
{
	numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253");

	return 1;
}