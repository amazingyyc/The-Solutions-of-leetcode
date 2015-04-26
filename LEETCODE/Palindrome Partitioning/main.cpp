#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void partition(string s, int size, int start, int* pal, vector<string> &cur, vector<vector<string>> &result)
{
	if (start >= size)
	{
		result.push_back(cur);

		return;
	}

	for (int i = start; i < size; ++i)
	{
		if (pal[start + i + 1] >= (i - start))
		{
			string temp = s.substr(start, i - start + 1);

			cur.push_back(temp);
			partition(s, size, i + 1, pal, cur, result);
			cur.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) 
{
	vector<vector<string>> result;
	vector<string> cur;

	int size = s.size();
	int len = 2*size + 1;
	if (0 == size)	return result;

	//存储回文串的信息 将#插入到s中 
	string str = "#";
	for (int i = 0; i < size; ++i)
		str = str + s[i] + "#";

	//存储pal存储str的回文信息 
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

	partition(s, size, 0, pal, cur, result);

	delete[] pal;

	return result;
}

int main()
{
	partition("abc");

	return 1;
}