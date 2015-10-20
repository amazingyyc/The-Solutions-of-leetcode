#include <iostream>
#include <vector>
#include <string>
#include <strstream>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string> res;
	int size = nums.size();

	if (1 > nums.size())
		return res;

	int start;
	int end;

	start = nums[0];

	for (int i = 1; i < size; ++i)
	{
		if(nums[i] == nums[i-1] + 1)
			continue;

		end = nums[i - 1];

		if (start == end)
		{
			strstream ss;
			string s;

			ss << start;
			ss >> s;

			res.push_back(s);
		}
		else
		{
			strstream ss1;
			string s1;

			ss1 << start;
			ss1 >> s1;

			strstream ss2;
			string s2;

			ss2 << end;
			ss2 >> s2;

			res.push_back(s1 + "->" + s2);
		}

		start = nums[i];
	}

	end = nums[size - 1];

	if (start == end)
	{
		strstream ss;
		string s;

		ss << start;
		ss >> s;

		res.push_back(s);
	}
	else
	{
		strstream ss1;
		string s1;

		ss1 << start;
		ss1 >> s1;

		strstream ss2;
		string s2;

		ss2 << end;
		ss2 >> s2;

		res.push_back(s1 + "->" + s2);
	}

	return res;
}

int main()
{
	//[-2147483648,-2147483647,2147483647]
	vector<int> nums;
	nums.push_back(-2147483647 - 1);
	nums.push_back(-2147483647);
	nums.push_back(2147483647);

	summaryRanges(nums);

	return 0;
}