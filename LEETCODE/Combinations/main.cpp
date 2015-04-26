#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/
/************************************************************************/

//n可以使用的总个数 k最大的个数 pre上一层所使用的数值 level当前的层数
//numbers结果的集合 cur到目前层 所有的结果
void com(int n, int k, int pre, int level, vector<int> cur, vector<vector<int>> &numbers)
{
	if (level > k)
	{
		numbers.push_back(cur);

		return;
	}

	for (int i = pre + 1; i <= n -k + level; ++i)
	{
		cur.push_back(i);

		com(n, k, i, level + 1, cur, numbers);

		cur.pop_back();
	}
}

vector<vector<int>> combine(int n, int k) 
{
	vector<vector<int>> result;

	if (n < k)	return result;

	vector<int> cur;

	com(n, k, 0, 1, cur, result);

	return result;
}

/************************************************************************/
/*
另一个思路：
一个列表为长度为n 有n-k个false k个true 那么 只需要对这个数列进行排列 然后 如果为true去这个数 否则 不取这个数这样 就是n到k的所有排列
*/
/************************************************************************/

int main()
{
	combine(4, 2);

	return 1;
}