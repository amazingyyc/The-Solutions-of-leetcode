#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> anagrams(vector<string> &strs) 
{
	unordered_map<string, int> mp;

	vector<string> result;

	int size = strs.size();
	for (int i = 0; i < size; ++i)
	{
		string str = strs[i];

		sort(str.begin(), str.end());

		if (mp.find(str) == mp.end())
			mp[str] = i;
		else
		{
			if (mp[str] >= 0)
			{
				result.push_back(strs[mp[str]]);
				mp[str] = -1;
			}
				
			result.push_back(strs[i]);
		}
	}
	
	return result;
}

int main()
{
	vector<string> strs;
	strs.push_back("tea");
	strs.push_back("ate"); 
	strs.push_back("and");
	strs.push_back("dan"); 
	strs.push_back("eat");

	vector<string> result = anagrams(strs);

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i].c_str() << endl;
	}

	return 1;
}