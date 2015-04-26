#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/
/************************************************************************/

//共有n层 level当前层
void subs(int n, int level, vector<int> &S, vector<int> cur, vector<vector<int>> &result)
{
	result.push_back(cur);

	if (level >= n)	return;

	for (int i = level; i < n; ++i)
	{
		cur.push_back(S[i]);

		subs(n, i + 1, S, cur, result);

		cur.pop_back();
	}
}

vector<vector<int> > subsets(vector<int> &S)
{
	//首先排序
	sort(S.begin(), S.end());

	vector<vector<int>> result;

	subs(S.size(), 0, S, vector<int>(), result);

	return result;
}

int main()
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);

	subsets(S);

	return 1;
}