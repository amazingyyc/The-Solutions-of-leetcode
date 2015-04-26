#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/
/************************************************************************/

void subsetsWithDup(vector<int> &S, int size, int start, vector<int> &cur, vector<vector<int>> &result)
{
	result.push_back(cur);

	for (int i = start; i < size; ++i)
	{
		if (i > start && S[i] == S[i-1])
			continue;

		cur.push_back(S[i]);
		subsetsWithDup(S, size, i + 1, cur, result);
		cur.pop_back();
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S) 
{
	vector<vector<int>> result;
	vector<int> cur;

	int size = S.size();
	if (0 == size) return result;

	//≈≈–Ú
	sort(S.begin(), S.end());

	subsetsWithDup(S, size, 0, cur, result);

	return result;
}

int main()
{
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(2);

	subsetsWithDup(S);

	return 1;
}