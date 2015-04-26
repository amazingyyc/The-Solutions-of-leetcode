#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


//ACGT
vector<string> findRepeatedDnaSequences(string s) 
{
	vector<string> results;
	unordered_map<int, int> maps;

	int n = s.size();
	int i = 0;
	int code = 0;

	while (i < 9)
	{
		code = (code << 3) | (s[i++] & 7);
	}

	while (i < n)
	{
		if (maps[code = ((code & 0x7FFFFFF) << 3) | (s[i++] & 7)]++ == 1)
			results.push_back(s.substr(i - 10, 10));
	}
	
	return results;
}

int main()
{
	findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	//KMP("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", "AAAAACCCyCC");

	return 1;
}