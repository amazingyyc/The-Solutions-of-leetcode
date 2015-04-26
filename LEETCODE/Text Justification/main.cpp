#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/
/************************************************************************/


vector<string> fullJustify(vector<string> &words, int L) 
{
	vector<string> result;
	
	int size = words.size();
	for (int i = 0; i < size;)
	{
		int len = 0;	//遍历过的字符串的总长度 不包括空格
		int j = i;
		for (j = i; j < size; ++j)
		{
			if ((j - i) + len + words[j].size() <= L)
				len += words[j].size();
			else
				break;
		}

		j--;//向前到一位

		if (i == j)
		{
			result.push_back(words[i] + string(L - len, ' '));

			i = j + 1;

			continue;
		}

		//空格个数
		int spa = L - len;
		int first = 0;	//第一部分的长度
		int fSpa = 0;	//第一部分空格
		int sSpa = 0;	//第二部分空格 个数
		int lSpa = 0;

		if (j == size - 1)
		{
			fSpa = 1;
			sSpa = 1;
			lSpa = spa - (j - i);
		}
		else
		{
			first = spa % (j - i);
			sSpa = spa / (j - i);
			fSpa = sSpa + 1;
			lSpa = 0;
		}

		string str = "";
		for (int k = i; k < j; ++k)
		{
			if (k <= i + first - 1)
				str = str + words[k] + string(fSpa, ' ');
			else
				str = str + words[k] + string(sSpa, ' ');
		}
		
		str = str + words[j] + string(lSpa, ' ');

		result.push_back(str);

		i = j + 1;
	}

	return result;
}

int main()
{
	vector<string> words;
	words.push_back("My");
	words.push_back("momma");
	words.push_back("always");
	words.push_back("said,");
	words.push_back("Life");
	words.push_back("was");
	words.push_back("like");
	words.push_back("a");
	words.push_back("box");
	words.push_back("of");
	words.push_back("chocolates.");
	words.push_back("You");
	words.push_back("never");
	words.push_back("know");
	words.push_back("what");
	words.push_back("you're");
	words.push_back("gonna");
	words.push_back("get.");

	vector<string> result = fullJustify(words, 20);

	for (int i = 0; i < result.size(); ++i)
		cout << result[i].c_str() << endl;

	return 1;
}