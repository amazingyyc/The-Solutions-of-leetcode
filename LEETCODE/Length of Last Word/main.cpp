#include <iostream>

using namespace std;

/************************************************************************/
/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.                                                                     */
/************************************************************************/


/*int lengthOfLastWord(const char *s) 
{
	int len = 0;
	while ('\0' != s[len]) len++;

	int r = len - 1;
	while (r >= 0 && ' ' == s[r])	r--;

	if (r < 0)	return 0;

	int l = r - 1;
	while (l >= 0 && ' ' != s[l]) l--;

	return r - l;
}*/

int lengthOfLastWord(const char *s)
{
	int len = 0;

	for (; '\0' != *s; s++)
	{
		if (' ' != *s)
			len++;
		else if (*(s + 1) && ' ' != *(s + 1))
			len = 0;
	}

	return len;
}

int main()
{
	int len = lengthOfLastWord("a ");

	return 1;
}