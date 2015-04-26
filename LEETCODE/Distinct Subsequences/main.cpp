#include <iostream>
#include <algorithm>

using namespace std;

/************************************************************************/
/* 
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
/************************************************************************/

int numDistinct(string S, string T) 
{
	int sLen = S.size();
	int tLen = T.size();

	if (sLen < tLen)	return 0;

	int **numbers = new int*[sLen];
	for (int i = 0; i < sLen; ++i)
		numbers[i] = new int[tLen];

	for (int i = 0; i < sLen; ++i)
	{
		for (int j = 0; j < tLen; ++j)
		{
			if (0 == i || 0 == j)
			{
				if (0 == i && 0 == j)
					numbers[i][j] = (S[i] == T[j]) ? 1 : 0;
				else if (0 == i)
					numbers[i][j] = 0;
				else
					numbers[i][j] = (S[i] == T[j]) ? numbers[i - 1][j] + 1 : numbers[i - 1][j];
			}
			else if (S[i] == T[j])
				numbers[i][j] = numbers[i - 1][j - 1] + numbers[i - 1][j];
			else
				numbers[i][j] = numbers[i - 1][j];
		}
	}

	int sum = numbers[sLen - 1][tLen - 1];

	for (int i = 0; i < sLen; ++i)
		delete[] numbers[i];

	delete[] numbers;

	return sum;
}


int main()
{
	numDistinct("ccc", "c");

	return 1;
}