#include <iostream>
#include <vector>
#include <hash_map>
#include <map>
#include <algorithm>

/************************************************************************/
/* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.                                                                     */
/************************************************************************/

using namespace std;

//map是基于红黑树的 当所有的数插进去后 是以重大到小排列的
int longestConsecutive(vector<int> &num)
{
	if (1 == num.size())	return 1;

	map<int, int> m;

	int size = num.size();
	for (int i = 0; i < size; ++i)
		m[num[i]] = 0;
	
	int max_len = 1;

	map<int, int>::iterator cur = m.begin();
	map<int, int>::iterator pre = cur;
	int last = cur->first;

	for (cur++; cur != m.end(); pre = cur, ++cur)
	{
		if (cur->first == pre->first + 1)
			max_len = max(max_len, cur->first - last + 1);
		else
			last = cur->first;
	}

	return max_len;
}

/*int longestConsecutive(vector<int> &num) 
{
	//存储int 和是否是连续的
	hash_map<int, bool> map;

	int size = num.size();
	for (int i = 0; i < size; ++i)
	{
		//初始 赋值为false表示未处理
		map[num[i]] = false;
	}

	int max_len = 0;

	for (int i = 0; i < size; ++i)
	{
		int t = num[i];

		if (map[t])	continue;

		int len = 1;
		map[t] = true;

		int left = t - 1;
		while (map.find(left) != map.end())
		{
			map[left] = true;
			left--;
			len++;
		}

		int right = t + 1;
		while (map.find(right) != map.end())
		{
			map[right] = true;
			right++;
			len++;
		}

		max_len = max(max_len, len);
	}

	return max_len;
}*/

int main()
{
	//100, 4, 200, 1, 3, 2
	vector<int> num;
	num.push_back(100);
	num.push_back(4);
	num.push_back(200);
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);

	int max_len = longestConsecutive(num);

	return 1;
}