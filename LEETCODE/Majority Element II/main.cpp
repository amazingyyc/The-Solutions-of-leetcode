#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
最多会有两个结果*/
vector<int> majorityElement(vector<int>& nums) 
{
	int res1;
	int res2;

	int count1 = 0;
	int count2 = 0;

	for (int i : nums)
	{
		if (0 != count1 && i == res1)
			count1++;
		else if (0 != count2 && i == res2)
			count2++;
		else if (0 == count1)
		{
			res1 = i;
			count1++;
		}
		else if (0 == count2)
		{
			res2 = i;
			count2++;
		}
		else 
		{
			count1--;
			count2--;
		}
	}

	vector<int> res;

	if (0 < count1)
	{
		count1 = 0;

		for (int i : nums)
		{
			count1 += (res1 == i) ? 1 : 0;
		}

		if (count1 > nums.size() / 3)
			res.push_back(res1);
	}

	if (0 < count2)
	{
		count2 = 0;

		for (int i : nums)
		{
			count2 += (res2 == i) ? 1 : 0;
		}

		if (count2 > nums.size() / 3)
			res.push_back(res2);
	}

	return res;
}

/*vector<int> majorityElement(vector<int>& nums) {
	int cnt1 = 0, cnt2 = 0;
	int a, b;

	for (int n : nums) {
		if (cnt1 == 0 || n == a) {
			cnt1++;
			a = n;
		}
		else if (cnt2 == 0 || n == b) {
			cnt2++;
			b = n;
		}
		else {
			cnt1--;
			cnt2--;
		}
	}

	cnt1 = cnt2 = 0;
	for (int n : nums) {
		if (n == a)   cnt1++;
		else if (n == b) cnt2++;
	}

	vector<int> result;
	if (cnt1 > nums.size() / 3)   result.push_back(a);
	if (cnt2 > nums.size() / 3)   result.push_back(b);
	return result;
}*/

int main()
{
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(1);

	majorityElement(nums);

	return 0;
}