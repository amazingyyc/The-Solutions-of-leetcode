#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* Write a function to find the longest common prefix string amongst an array of strings.                                                                     */
/************************************************************************/
//找出最大前缀
string longestCommonPrefix(vector<string> &strs) 
{
	int size = strs.size();

	if (0 == size)	return "";

	string preStr = strs[0];
	int preLen = preStr.size();

	for (int i = 1; i < size; ++i)
	{
		int j = 0;
		for (; j < preLen && j < strs[i].size(); ++j)
		{
			if (preStr[j] != strs[i][j])
				break;
		}

		preLen = j;
	}

	return preStr.assign(preStr, 0, preLen);
}

int main()
{
	vector<string> strs;

	string preStr = longestCommonPrefix(strs);

	return 1;
}