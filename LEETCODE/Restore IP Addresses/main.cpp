#include <iostream>
#include <vector>
using namespace std;

//判断s是否为小于255的整数
bool valid(string s)
{
	int n = s.size();
	if (0 == n || 3 < n)	return false;

	if (1 < n && s[0] == '0')
		return false;

	int num = 0;
	for (int i = 0; i < n; ++i)
	{
		num *= 10;
		num += s[i] - '0';
	}

	if (0 <= num && num <= 255)
		return true;

	return false;
}

void restoreIpAddresses(string s, int start, int size, string cur, int pre, vector<string> &results)
{
	if (4 == pre)
	{
		results.push_back(cur);

		return;
	}

	for (int i = 1; i <= 3 && (start + i) <= size; ++i)
	{
		string temp = s.substr(start, i);

		if (valid(temp) && (size - start - i) <= 3 * (3 - pre) && (size - start - i) >= (3 - pre))
		{
			if (3 != pre)	temp = temp + ".";

			restoreIpAddresses(s, start + i, size, cur + temp, pre + 1, results);
		}
	}
}

vector<string> restoreIpAddresses(string s) 
{
	vector<string> results;

	restoreIpAddresses(s, 0, s.size(), "", 0, results);

	return results;
}

int main()
{
	restoreIpAddresses("010010");

	return 1;
}