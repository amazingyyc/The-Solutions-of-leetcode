#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

/************************************************************************/
/* 
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
/************************************************************************/

//利用队列进行广度优先搜索
/*int ladderLength(string start, string end, unordered_set<string> &dict) 
{
	if (start == end) return 0;

	int n = start.size();
	int num = 0;
	unordered_set<string> cur;
	queue<string> que;
	que.push(start);

	cur.insert(start);

	while (!que.empty())
	{
		num++;

		int size = que.size();
		while (size--)
		{
			string top = que.front();
			que.pop();

			for (int i = 0; i < n; ++i)
			for (char j = 'a'; j <= 'z'; ++j)
			{
				string temp = top;
				if (temp[i] != j)
				{
					temp[i] = j;

					if (temp == end)	return num + 1;

					if (dict.find(temp) != dict.end() && cur.find(temp) == cur.end())
					{
						cur.insert(temp);
						que.push(temp);
					}
				}
			}
		}
	}

	return 0;
}*/

//利用队列进行广度优先搜索
int ladderLength(string start, string end, unordered_set<string> &dict)
{
	if (start == end) return 0;

	int n = start.size();
	int num = 0;

	queue<string> que;
	que.push(start);

	while (!que.empty())
	{
		num++;

		int size = que.size();
		while (size--)
		{
			string top = que.front();
			que.pop();

			for (int i = 0; i < n; ++i)
			for (char j = 'a'; j <= 'z'; ++j)
			{
				string temp = top;
				if (temp[i] != j)
				{
					temp[i] = j;

					if (temp == end)	return num + 1;

					if (dict.find(temp) != dict.end())
					{
						dict.erase(temp);
						que.push(temp);
					}
				}
			}
		}
	}

	return 0;
}


int main()
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	int n = ladderLength("hit", "cog", dict);

	return 1;
}