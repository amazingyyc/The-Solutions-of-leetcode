#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
利用unordered_map统计 L中字符串的个数 然后在S从每一个位置进行查找 直到 找完位置
*/
vector<int> findSubstring(string S, vector<string> &L)
{
	vector<int> result;

	int SSize = S.size();
	int LSize = L.size();

	if (0 == SSize || 0 == LSize)	return result;

	int LLen = L[0].size();

	if (SSize < LSize*LLen)	return result;

	//统计字符串的个数 也许有相等的字符串
	unordered_map<string, int> LIndexs;
	for (int i = 0; i < LSize; ++i)
		LIndexs[L[i]]++;

	for (int i = 0; i <= SSize - LSize*LLen; ++i)
	{
		//未被使用
		unordered_map<string, int> unused(LIndexs);

		for (int j = i; j <= (SSize - LLen); j += LLen)
		{
			//查找是否存在
			auto pos = unused.find(S.substr(j, LLen));

			if (pos == unused.end())
				break;

			if (--pos->second == 0)
				unused.erase(pos);
		}

		if (0 == unused.size())
			result.push_back(i);
	}

	return result;
}

int main()
{
	string S = "abaababbaba";
	vector<string> L;
	L.push_back("ab");
	L.push_back("ba");
	L.push_back("ab");
	L.push_back("ba");

	vector<int> result = findSubstring(S, L);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;

	return 1;
}