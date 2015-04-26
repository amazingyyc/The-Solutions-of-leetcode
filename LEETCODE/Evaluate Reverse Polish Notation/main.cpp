#include <iostream>
#include <vector>
#include <stack>
#include <stdlib.h>

using namespace std;

int nums(string s)
{
	int n = s.size();

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum = sum * 10 + (s[i] - '0');
	}

	return sum;
}

int evalRPN(vector<string> &tokens) 
{
	stack<int> stac;

	int n = tokens.size();
	for (int i = 0; i < n; ++i)
	{
		string s = tokens[i];

		if ("+" != s && "-" != s && "*" != s && "/" != s)
		{
			stac.push(atoi(s.c_str()));
		}
		else 
		{
			int se = stac.top();
			stac.pop();
			int fi = stac.top();
			stac.pop();

			int temp = 0;

			if ("+" == s)
				temp = fi + se;
			else if ("-" == s)
				temp = fi - se;
			else if ("*" == s)
				temp = fi * se;
			else if ("/")
				temp = fi / se;

			stac.push(temp);
		}
	}

	return stac.top();
}

int main()
{
	return 1;
}