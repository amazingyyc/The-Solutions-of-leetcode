#include <iostream>

using namespace std;

/************************************************************************/
/* '?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false                                                                     */
/************************************************************************/

//使用递归 时间复杂度太高
bool isMatch(const char *s, const char *p) 
{
	const char* str = s;
	const char *ptr = p;

	bool star = false;	//是否有*

	while ('\0' != *str)
	{
		if ('?' == *ptr || *str == *ptr)
		{
			str++;
			ptr++;
		}
		else if ('*' == *ptr)
		{
			star = true;

			while ('*' == *ptr)	ptr++;

			if ('\0' == *ptr)	return true;

			s = str;
			p = ptr;

			//str++;
		}
		else
		{
			if (!star)	return false;

			s++;

			str = s;
			ptr = p;
		}
	}

	while ('*' == *ptr) ptr++;

	return '\0' == *ptr;
}

int main()
{
	bool i1 = isMatch("c", "*?*");
	/*bool i2 = isMatch("aa", "aa");
	bool i3 = isMatch("aaa", "aa");
	bool i4 = isMatch("aa", "*");
	bool i5 = isMatch("aa", "a*");
	bool i6 = isMatch("ab", "?*");
	bool i7 = isMatch("aab", "c*a*b");

	cout << i1 << endl;
	cout << i2 << endl;
	cout << i3 << endl;
	cout << i4 << endl;
	cout << i5 << endl;
	cout << i6 << endl;*/
	cout << i1 << endl;

	return 1;
}