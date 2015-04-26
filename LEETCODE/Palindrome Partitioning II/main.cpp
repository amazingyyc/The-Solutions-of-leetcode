#include <iostream>
#include <algorithm>

using namespace std;

/*int minCut(string s) 
{
	int n = s.size();

	bool** pal = new bool*[n];
	for (int i = 0; i < n; ++i)
		pal[i] = new bool[n];

	for (int i = 0; i < n; ++i)
	for (int j = i; j >= 0; --j)
	{
		if (i == j)
			pal[i][j] = true;
		else if (j == i - 1)
			pal[i][j] = (s[j] == s[i]);
		else
			pal[i][j] = (s[j] == s[i]) && pal[i - 1][j + 1];
	}

	int* step = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		step[i] = INT_MAX;

	step[0] = 0;

	for (int i = 1; i <= n; ++i)
	for (int j = i - 1; j >= 0; --j)
	{
		if (pal[i - 1][j])
			step[i] = min(step[i], step[j] + 1);
	}

	int re = step[n] - 1;

	return re;
}*/

int minCut(string s)
{
	int n = s.size();
	int len = 2 * n + 1;

	string str = "#";
	for (int i = 0; i < n; ++i)
		str = str + s[i] + "#";

	int* pal = new int[len];

	pal[0] = 0;
	int mid = 0;
	int end = 0;
	for (int i = 1; i < len; ++i)
	{
		if (i <= end)
			pal[i] = min(pal[2 * mid - i], end - i);
		else
			pal[i] = 0;

		for (int j = pal[i] + 1; (i + j) < len && (i - j) >= 0; ++j)
		{
			if (str[i - j] == str[i + j])
				pal[i]++;
			else
				break;
		}

		if ((i + pal[i]) > end)
		{
			mid = i;
			end = i + pal[i];
		}
	}

	int* step = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		step[i] = INT_MAX;

	step[0] = 0;

	for (int i = 1; i <= n; ++i)
	for (int j = i - 1; j >= 0; --j)
	{
		if (pal[j + i] >= (i - j - 1))
			step[i] = min(step[i], step[j] + 1);
	}

	int re = step[n] - 1;

	return re;
}


int main()
{
	minCut("aab");

	return 1;
}