#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t) 
{
	if (s.size() != t.size())
		return false;

	int size = s.size();

	unordered_map<char, char> m1;
	unordered_map<char, char> m2;

	for (int i = 0; i < size; ++i)
	{
		if (m1.find(s[i]) != m1.end())
		{
			//查找到了
			if (m1[s[i]] != t[i])
				return false;

			//if (m2.find(t[i]) != m2.end() && m2[t[i]] != s[i])
				//return false;

		}
		else
		{
			if (m2.find(t[i]) != m2.end() && m2[t[i]] != s[i])
				return false;

			//没查找到了
			m1[s[i]] = t[i];
			m2[t[i]] = s[i];
		}
	}

	return true;
}

int main()
{
	cout << isIsomorphic("ab", "aa") << endl;
	cout << isIsomorphic("foo", "bar") << endl;
	cout << isIsomorphic("paper", "title") << endl;


	return 0;
}