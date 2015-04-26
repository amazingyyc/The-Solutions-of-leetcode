#include <iostream>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits) 
{
	vector<string> result;

	if (0 == digits.size())
		return result;

	string strs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int size = digits.size();

	result.push_back("");

	for (int i = 0; i < size; ++i)
	{
		if (digits[i] < '0' || digits[i] > '9')
			continue;

		int index = digits[i] - '0';

		vector<string> temp = result;
		result.clear();

		for (int m = 0; m < temp.size(); ++m)
		{
			for (int n = 0; n < strs[index].size(); ++n)
				result.push_back(temp[m] + strs[index][n]);
		}
	}

	return result;
}

int main()
{
	letterCombinations("23");

	return 1;
}