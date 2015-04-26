#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//连续子串的最大乘积
int maxProduct(vector<int>& nums)
{
	int n = nums.size();

	if (0 == n)	return 0;
	int pos = INT_MIN;	//存储0-i-1最大的整数乘积绝对值
	int neg = INT_MIN;	//存储最大的复数乘积绝对值
	int maxPro = nums[0];

	for (int i = 0; i < n; ++i)
	{
		if (0 == nums[i])
		{
			pos = INT_MIN;
			neg = INT_MIN;

			maxPro = max(maxPro, 0);
			continue;
		}
		else if (0 < nums[i])
		{
			pos = (INT_MIN == pos) ? nums[i] : pos*nums[i];
			neg = (INT_MIN == neg) ? INT_MIN : neg*nums[i];
		}
		else
		{
			int temp = pos;
			pos = (INT_MIN == neg) ? INT_MIN : neg*nums[i];
			neg = (INT_MIN == temp) ? nums[i] : temp*nums[i];
		}

		maxPro = max(maxPro, max(pos, neg));
	}

	return maxPro;
}

int main()
{
	int A[4] = { -4, -3 };

	maxProduct(A, 2);

	return 1;
}