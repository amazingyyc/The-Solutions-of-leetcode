#include <iostream>
#include <set>
#include <deque>
#include <unordered_map>

using namespace std;


/************************************************************************/
/* 
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
/************************************************************************/
/*string minWindow(string S, string T) 
{
	if (S.size() < T.size())	return "";
	
	multiset<char> box;
	deque<int> index;	//所有遇到的需要查找的字符的位置
	unordered_map<char, int> nums;	//保存所有的遇到的字符的个数
	unordered_map<char, int> test;

	for (int i = 0; i < T.size(); ++i)
	{
		box.insert(T[i]);
		nums[T[i]] = 0;
		test[T[i]]++;
	}

	string re = "";
	int len = INT_MAX;

	for (int i = 0; i < S.size(); ++i)
	{
		//属于T
		if (test.find(S[i]) != test.end())
		{
			index.push_back(i);	//将坐标要入到队列中
			nums[S[i]]++;	//个数加一

			multiset <char>::iterator pos = box.find(S[i]);
			if (pos != box.end())
				box.erase(pos);

			//如果为空说明 nums 和 index已经包含了所有的T的字符 
			if (box.empty())
			{
				while (1)
				{
					int begin = index.front();
					index.pop_front();
					int l = i - begin + 1;

					if (l < len)
					{
						re = S.substr(begin, l);
						len = l;
					}

					nums[S[begin]]--;

					if (test[S[begin]] > nums[S[begin]])
					{
						box.insert(S[begin]);

						break;
					}
				}
			}
		}
	}

	return re;
}*/


string minWindow(string S, string T)
{
	if (0 == S.size() || S.size() < T.size())	return "";

	//申请两个数组 表示asic码值 对应的个数
	int expect[256];	//存储T包含的字符的个数
	int appear[256];	//在窗口内 已经存在的字符个数的信息

	for (int i = 0; i < 256; ++i)
		expect[i] = appear[i] = 0;

	for (int i = 0; i < T.size(); ++i)
		expect[T[i]]++;

	int start = 0;	//窗口的起始位置
	int number = 0;	//包含窗口内的T的字符个数  
	int tSize = T.size();

	int minStart = 0;
	int len = INT_MAX;

	int size = S.size();
	for (int i = 0; i < size; ++i)
	{
		if (expect[S[i]] > 0)
		{
			appear[S[i]]++;

			if (appear[S[i]] <= expect[S[i]])
				number++;
		}

		if (number == tSize)
		{
			while (appear[S[start]] > expect[S[start]] || 0 == expect[S[start]])
			{
				appear[S[start]]--;
				start++;
			}

			if (i - start + 1 < len)
			{
				minStart = start;
				len = i - start + 1;
			}

			appear[S[start]]--;
			start++;
			number--;

			while (0 == expect[S[start]])
				start++;
		}
	}

	if (len == INT_MAX)	return "";

	return S.substr(minStart, len);
}


int main()
{
	string re = minWindow("a", "aa");

	cout << re.c_str() << endl;

	return 1;
}