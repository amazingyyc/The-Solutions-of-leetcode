#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

static bool compare(const int &a, const int &b)
{
	stringstream ss1;
	ss1 << a << b;
	stringstream ss2;
	ss2 << b << a;

	string s1 = ss1.str();
	string s2 = ss2.str();

	return s1 > s2;
}

string largestNumber(vector<int>& nums) 
{
	if (0 == nums.size())	return "";

	sort(nums.begin(), nums.end(), compare);

	if (0 == nums[0]) return "0";

	stringstream ss;
	for (int i = 0; i < nums.size(); ++i)
	{
		ss << nums[i];
	}

	return ss.str();
}

int main()
{
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(30);
	nums.push_back(34);
	nums.push_back(5);
	nums.push_back(9);
	largestNumber(nums);


	return 1;
}