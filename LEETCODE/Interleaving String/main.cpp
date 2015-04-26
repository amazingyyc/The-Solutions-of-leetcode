#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*bool isInterleave(string s1, string s2, string s3)
{
	int l1 = s1.size();
	int l2 = s2.size();
	int l3 = s3.size();

	if ((l1 + l2) != l3)	return false;
	if (0 == l3)	return true;

	vector<vector<vector<bool>>> b(l3 + 1, vector<vector<bool>>(l1 + 1, vector<bool>(l2 + 1, false)));
	b[0][0][0] = true;

	for (int k = 1; k <= l3; ++k)
	{
		for (int i = max(0, k - l2); i <= k && i <= l1; ++i)
		{
			if ((0 != i && b[k - 1][i - 1][k - i] && s3[k - 1] == s1[i - 1]) ||
				(0 != (k - i) && b[k - 1][i][k - i - 1] && s3[k - 1] == s2[k - i - 1]))
				b[k][i][k - i] = true;
		}
	}

	bool re = b[l3][l1][l2];

	return re;
}*/


bool isInterleave(string s1, string s2, string s3)
{
	int l1 = s1.size();
	int l2 = s2.size();
	int l3 = s3.size();

	if ((l1 + l2) != l3)	return false;
	if (0 == l3)	return true;

	//b[i][j] ¶ÔÓ¦Óë s3[0-i+j]
	vector<vector<bool>> b(l1 + 1, vector<bool>(l2 + 1, false));
	
	for (int i = 0; i <= l1; ++i)
	for (int j = 0; j <= l2; ++j)
	{
		if (0 == i && 0 == j)
			b[i][j] = true;
		else if (0 == i)
			b[i][j] = b[i][j - 1] && s2[j-1] == s3[i + j-1];
		else if (0 == j)
			b[i][j] = b[i - 1][j] && s1[i - 1] == s3[i + j - 1];
		else
			b[i][j] = (b[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
					  (b[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
	}

	return b[l1][l2];
}

int main()
{
	isInterleave("aabcc", "dbbca", "aadbbbaccc");

	return 1;
}