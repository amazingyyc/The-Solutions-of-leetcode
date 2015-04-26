#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

/************************************************************************/
/* 第n个 字符序列 一定是 “(” + i + “)” + n-i-1组成的 所以只需要将之前的字符序列和 进行组合即可                                                                     */
/************************************************************************/
vector<string> generateParenthesis(int n)
{
	vector<vector<string>> strs;
	strs.push_back(vector<string>(1, ""));	//n = 0时
	strs.push_back(vector<string>(1, "()"));	//n = 1时

	if (0 == n)return strs[0];
	if (1 == n)return strs[1];

	for (int index = 2; index <= n; ++index)
	{
		vector<string> curer;

		for (int i = 0; i < index; ++i)
		{
			vector<string> inner = strs[i];
			vector<string> outer = strs[index - i - 1];

			int iSize = inner.size();
			int oSize = outer.size();

			for (int m = 0; m < iSize; ++m)
			for (int n = 0; n < oSize; ++n)
				curer.push_back("(" + inner[m] + ")" + outer[n]);
		}

		strs.push_back(curer);
	}

	return strs[n];
}

int main()
{
	vector<string> strs = generateParenthesis(3);

	return 1;
}