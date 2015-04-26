#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

void wordBreak(string s, int n, int start, string cur, vector<bool> &f, vector<string> &result, unordered_set<string>& wordDict)
{
	if (start >= n)
	{
		result.push_back(cur);

		return;
	}

	for (int i = start; i < n; ++i)
	{
		string temp = s.substr(start, i - start + 1);

		if ((n - 1 == i || f[i + 1]) && wordDict.find(temp) != wordDict.end())
		{
			if ((n - 1) == i)
				wordBreak(s, n, i + 1, cur + temp, f, result, wordDict);
			else
				wordBreak(s, n, i + 1, cur + temp + " ", f, result, wordDict);
		}
	}
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
{
	int n = s.size();

	//存储[i, n-1]是否可以被wordDict组成
	vector<bool> f(n, false);

	for (int i = n - 1; i >= 0; --i)
	for (int j = i; j < n; ++j)
	{
		if (n - 1 == j || f[j + 1])
		{
			if (wordDict.find(s.substr(i, j - i + 1)) != wordDict.end())
			{
				f[i] = true;

				break;
			}
		}
	}

	vector<string> result;
	if (!f[0])	return result;

	wordBreak(s, n, 0, "", f, result, wordDict);

	return result;
}

int main()
{
	string s = "catsanddog";
	unordered_set<string> wordDict;
	wordDict.insert("cat");
	wordDict.insert("cats");
	wordDict.insert("and");
	wordDict.insert("sand");
	wordDict.insert("dog");

	wordBreak(s, wordDict);

	return 1;
}