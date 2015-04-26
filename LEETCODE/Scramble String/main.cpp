#include <iostream>
#include <vector>

using namespace std;


bool isScramble(string s1, string s2) 
{
	const int n = s1.size();
	if (n != s2.size())return false;
	if (0 == n) return true;

	bool*** b = new bool**[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		b[i] = new bool*[n];
		for (int j = 0; j < n; ++j)
			b[i][j] = new bool[n];
	}

	for (int len = 1; len <= n; ++len)
	{
		for (int i = 0; i <= n - len; ++i)
		{
			for (int j = 0; j <= n - len; ++j)
			{
				if (1 == len)
					b[1][i][j] = (s1[i] == s2[j]);
				else
				{
					for (int k = 1; k < len; ++k)
					{
						if ((b[k][i][j] && b[len - k][i + k][j + k]) ||
							(b[k][i][j + len - k] && b[len - k][i + k][j]))
						{
							b[len][i][j] = true;
							break;
						}
					}
				}
			}
		}
	}

	return b[n][0][0];
}

int main()
{
	bool b = isScramble("aa","aa");
	
	cout << b << endl;

	return 1;
}