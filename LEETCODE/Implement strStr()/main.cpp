#include <iostream>

using namespace std;

//字符串匹配
//使用kmp算法进行匹配

int KMP(char* text, char* target) 
{
	//得到长度
	int n = strlen(text);
	int m = strlen(target);

	if (n < m)	return -1;
	if (0 == m) return 0;

	//存储 前缀匹配的 最大大小
	//next[k]表示 前k个字符 前缀相等的最大个数 既0-k-1相等的最大个数
	int *next = (int*)malloc(sizeof(int)*m);
	next[0] = 0;

	for (int i = 1; i < m; ++i)
	{
		int j = next[i - 1];

		while (j >0 && target[j] != target[i])
		{
			j = next[j - 1];
		}

		if (target[j] == target[i])
			next[i] = j + 1;
		else
			next[i] = 0;
	}

	//进行匹配
	int index = 0;
	for (int i = 0; i < n;)
	{
		if (text[i] == target[index])
		{
			i++;
			index++;

			if (index == m)
				return i - m;
		}
		else if (0 == index)
			i++;
		else
			index = next[index - 1];
	}

	return -1;
}

int main()
{
	int index = KMP("bbaab", "aab");

	return 1;
}