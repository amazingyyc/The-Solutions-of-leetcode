#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/************************************************************************/
/* Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".                                                                     */
/************************************************************************/

string shortestPalindrome(string s) 
{
	int size = s.size();
	char* str = (char*)malloc(2 * size + 1);

	str[0] = '#';

	for (int i = 0; i < size; ++i)
	{
		str[2 * i + 1] = s[i];
		str[2 * i + 2] = '#';
	}

	int str_size = 2 * size + 1;

	vector<int> arr(str_size, 1);	//arr[i]��ʾstr[i]Ϊ���ĵ������Ĵ��ĳ���
	int id = 0;	//��Ӧ��mx������
	int mx = 0;	//����ұ߽�
	int index = 0;

	for (int i = 1; i <= size; ++i)
	{
		if (mx > i)
			arr[i] = min(arr[2*id - i], mx - i + 1);
		
		while (0 <= (i - arr[i]) && str_size > (i + arr[i]) && str[i - arr[i]] == str[i + arr[i]])
			arr[i]++;

		if (mx < (i + arr[i] - 1))
		{
			mx = i + arr[i] - 1;
			id = i;
		}

		if (arr[i] >= i + 1)
		{
			index = i;
		}
	}

	free(str);

	string res = s.substr(index, size - index);
	reverse(res.begin(), res.end());

	return res + s;
}

int main()
{
	shortestPalindrome("abbac");

	return 0;
}