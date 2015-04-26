#include <iostream>

using namespace std;


/************************************************************************/
/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/
/************************************************************************/

int titleToNumber(string s) 
{
	int sum = 0;
	int k = 1;
	int size = s.size();
	for (int i = size - 1; i >= 0; --i, k *= 26)
	{
		sum += k*(s[i] - 'A' + 1);
	}

	return sum;
}

int main()
{
	int num = titleToNumber("AB");

	cout << num << endl;

	return 1;
}