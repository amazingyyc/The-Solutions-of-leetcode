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

//n����ʹ�õ��ܸ��� k���ĸ��� pre��һ����ʹ�õ���ֵ level��ǰ�Ĳ���
//numbers����ļ��� cur��Ŀǰ�� ���еĽ��
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
��һ��˼·��
һ���б�Ϊ����Ϊn ��n-k��false k��true ��ô ֻ��Ҫ��������н������� Ȼ�� ���Ϊtrueȥ����� ���� ��ȡ��������� ����n��k����������
*/
/************************************************************************/

int main()
{
	combine(4, 2);

	return 1;
}