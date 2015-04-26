#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//三个数相加等于target  num已经排好序 在left right之间
vector<vector<int>> threeSum(vector<int> &num, int left, int right, int target)
{
	vector<vector<int>> result;

	for (int i = left; i < right - 1; ++i)
	{
		//两边向中间 
		if (i > 0 && num[i] == num[i - 1])		
			continue;

		int l = i + 1;
		int r = right;

		while (l < r)
		{
			int sum = num[i] + num[l] + num[r];

			if (sum == target)
			{
				vector<int> re;
				re.push_back(num[i]);
				re.push_back(num[l]);
				re.push_back(num[r]);

				result.push_back(re);

				while (num[++l] == num[l - 1]);
				while (num[--r] == num[r + 1]);
			}
			else if (sum < target)
				while (num[++l] == num[l - 1]);
			else
				while (num[--r] == num[r + 1]);
		}
	}

	return result;
}

vector<vector<int> > fourSum(vector<int> &num, int target) 
{
	vector<vector<int>> result;
	int size = num.size();

	if (size < 4)	return result;

	//排序
	sort(num.begin(), num.end());
	
	for (int i = size - 1; i > 2; --i)
	{
		if (i < size - 1 && num[i] == num[i+1])
			continue;

		vector<vector<int>> temp = threeSum(num, 0, i - 1, target - num[i]);

		int tempSize = temp.size();
		for (int j = 0; j < tempSize; ++j)
		{
			temp[j].push_back(num[i]);

			result.push_back(temp[j]);
		}
	}

	return result;
}

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);

	fourSum(num, 0);

	return 1;
}