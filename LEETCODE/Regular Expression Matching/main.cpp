#include <iostream>

using namespace std;

//������ʽƥ�� ʹ�õݹ�

bool isMatch(const char *s, const char *p) 
{
	if ('\0' == *p)
		return '\0' == *s;

	if ('*' == *(p + 1))
	{
		//��һ����ĸΪ'*'
		while (*p == *s || ('.' == *p && '\0' != *s))
		{
			if (isMatch(s, p + 2))
				return true;

			s++;
		}

		return isMatch(s, p + 2);
	}
	else
	{
		if (*p == *s || ('.' == *p && '\0' != *s))
			return isMatch(s + 1, p + 1);

		return false;
	}
}

int main()
{
	return 1;
}