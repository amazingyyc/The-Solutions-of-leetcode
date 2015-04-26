#include <iostream>

using namespace std;

void reverseWords(string &s) 
{
	string str(s);

	int n = str.size();
	int l = 0;
	int r = n - 1;
	int cur = 0;
	bool f = true;

	while (0 <= r)
	{
		while (0 <= r && ' ' == str[r])	r--;
			
		if (r < 0)	break;

		l = r - 1;
		while (0 <= l && ' ' != str[l])	l--;

		if (f) f = false;
		else s[cur++] = ' ';

		for (int i = l + 1; i <= r; ++i)
			s[cur++] = str[i];

		r = l;
	}

	s = s.substr(0, cur);
}

int main()
{
	string s = "a";

	reverseWords(s);

	cout << s.c_str() << endl;

	return 1;
}