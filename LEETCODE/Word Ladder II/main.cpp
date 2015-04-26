#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
void findLadders(unordered_map<string, vector<string>> &father, vector<string> &re, vector<vector<string>> &result, const string& word, const string &start)
{
	re.push_back(word);

	if (word == start)
	{
		result.push_back(re);
		reverse(result.back().begin(), result.back().end());
	}
	else
	{
		for (auto str : father[word])
		{
			findLadders(father, re, result, str, start);
		}
	}

	re.pop_back();
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
{
	unordered_map<string, vector<string>> father;	//´æ´¢×Ö·û¶ÔÓ¦µÄÇ°Çý
	unordered_set<string> cur;	//´æ´¢µ±Ç°²ãµÄ×Ö·û´®
	unordered_set<string> next;	//´æ´¢ÏÂÒ»²ãµÄ×Ö·û´®

	int n = start.size();

	bool find = false;

	cur.insert(start);

	while (!cur.empty() && !find)
	{
		//É¾³ýÒÑ¾­´æ´¢µÄ
		for (auto a : cur)
			dict.erase(a);

		for (auto top : cur)
		{
			for (int i = 0; i < n; ++i)
			for (char j = 'a'; j <= 'z'; ++j)
			{
				string temp = top;

				if (temp[i] != j)
				{
					temp[i] = j;

					if (temp == end)	
						find = true;

					if (dict.find(temp) != dict.end() || temp == end)
					{
						next.insert(temp);
						father[temp].push_back(top);
					}
				} 
			}
		}

		cur.clear();
		swap(cur, next);
	}

	vector<vector<string>> result;

	if (cur.empty()) return result;

	vector<string> re;

	findLadders(father, re, result, end, start);

	return result;
}

int main()
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dog");
	dict.insert("tot");
	dict.insert("hog");
	dict.insert("hop");
	dict.insert("pot");
	dict.insert("dot");

	findLadders("hot", "dog", dict);

	return 1;
}