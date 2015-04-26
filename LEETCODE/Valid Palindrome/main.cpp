#include <iostream>

using namespace std;

/*
回文串 只考虑字母和数值字符= 
*/

//是否为数值或者字母字符
bool isChar(char c)
{
	if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return true;

	return false;
}

bool isPalindrome(string s)
{
	int size = s.size();

	if (0 == size || 1 == size)
		return true;

	int l = 0;
	int r = size - 1;

	while (l < r)
	{
		if (!isChar(s[l]))
			l++;
		else if (!isChar(s[r]))
			r--;
		else if (s[l] == s[r] || ('A' - 'a' == s[l] - s[r]) || ('A' - 'a' == s[r] - s[l]))
		{
			l++;
			r--;
		}
		else
			return false;
	}

	return true;
}

int main()
{
	bool t = isPalindrome("race a car");

	return 1;
}