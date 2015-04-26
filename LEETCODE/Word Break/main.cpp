#include <iostream>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) 
{
	int size = s.size();
	if (0 == size)	return true;
	if (0 == dict.size())	return false;

	//f[i]表示前[0, i]字符是否匹配
	bool* f = new bool[size];
	for (int i = 0; i < size; ++i)
		f[i] = false;
	
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j >= 0; --j)
		{
			if (0 == j || f[j - 1])
			{
				if (dict.find(s.substr(j, i - j + 1)) != dict.end())
				{
					f[i] = true;
					break;
				}
			}
		}
	}

	bool re = f[size - 1];

	delete[] f;

	return re;
}

int main()
{
	return 1;
}