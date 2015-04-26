#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
/************************************************************************/

//动态规划 仔细思考
//找出两个字符串的最长子序列的字符个数 比如abcd 与ambn最长子序列的个数为2
int minDistance(string word1, string word2)
{
	int size1 = word1.size();
	int size2 = word2.size();

	if (0 == size1 || 0 == size2)
		return max(size1, size2);

	int** subs = new int*[size1+1];
	for (int i = 0; i <= size1; ++i)
		subs[i] = new int[size2+1];

	for (int i = 0; i <= size1; ++i)
	{
		for (int j = 0; j <= size2; ++j)
		{
			if (0 == i)
				subs[i][j] = j;
			else if (0 == j)
				subs[i][j] = i;
			else if (word1[i - 1] == word2[j - 1])
				subs[i][j] = subs[i - 1][j - 1];
			else
				subs[i][j] = min(subs[i - 1][j - 1] + 1, min(subs[i - 1][j] + 1, subs[i][j - 1] + 1));
		}
	}

	int result = subs[size1][size2];

	//清理内存
	for (int i = 0; i <= size1; ++i)
		delete[] subs[i];

	delete[] subs;

	return result;
}

int main()
{
	int step = minDistance("prosperity", "properties");

	cout << step << endl;

	return 1;
}