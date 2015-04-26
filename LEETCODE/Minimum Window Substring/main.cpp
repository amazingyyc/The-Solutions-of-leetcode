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
	deque<int> index;	//������������Ҫ���ҵ��ַ���λ��
	unordered_map<char, int> nums;	//�������е��������ַ��ĸ���
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
		//����T
		if (test.find(S[i]) != test.end())
		{
			index.push_back(i);	//������Ҫ�뵽������
			nums[S[i]]++;	//������һ

			multiset <char>::iterator pos = box.find(S[i]);
			if (pos != box.end())
				box.erase(pos);

			//���Ϊ��˵�� nums �� index�Ѿ����������е�T���ַ� 
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

	//������������ ��ʾasic��ֵ ��Ӧ�ĸ���
	int expect[256];	//�洢T�������ַ��ĸ���
	int appear[256];	//�ڴ����� �Ѿ����ڵ��ַ���������Ϣ

	for (int i = 0; i < 256; ++i)
		expect[i] = appear[i] = 0;

	for (int i = 0; i < T.size(); ++i)
		expect[T[i]]++;

	int start = 0;	//���ڵ���ʼλ��
	int number = 0;	//���������ڵ�T���ַ�����  
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