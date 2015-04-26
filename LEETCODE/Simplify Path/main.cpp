#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/************************************************************************/
/* 
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
/************************************************************************/

/************************************************************************/
/* 
题目的要求是输出Unix下的最简路径，Unix文件的根目录为"/"，"."表示当前目录，".."表示上级目录。
例如：
输入1：
/../a/b/c/./..
输出1：
/a/b
模拟整个过程：
1. "/" 根目录
2. ".." 跳转上级目录，上级目录为空，所以依旧处于 "/"
3. "a" 进入子目录a，目前处于 "/a"
4. "b" 进入子目录b，目前处于 "/a/b"
5. "c" 进入子目录c，目前处于 "/a/b/c"
6. "." 当前目录，不操作，仍处于 "/a/b/c"
7. ".." 返回上级目录，最终为 "/a/b"
*/
/************************************************************************/

//从str查找c start开始查找 如果无法找到则返回str.size
int indexOfChar(string str, int start, char c)
{
	int size = str.size();
	for (int i = start; i < size; ++i)
	if (str[i] == c)
		return i;

	return size;
}

string simplifyPath(string path) 
{
	vector<string> strs;

	int size = path.size();
	for (int i = 0; i < size;)
	{
		//越过'/'
		i++;

		int j = indexOfChar(path, i, '/');

		string temp = path.substr(i, j - i);
		if ("" != temp)
		{
			if (".." == temp)
			{
				if (!strs.empty())
					strs.pop_back();
			}
			else if ("." != temp)
				strs.push_back(temp);
		}

		i = j;
	}

	if (strs.empty())
		return "/";

	string result = "";
	for (auto str : strs)
		result = result + "/" + str;

	return result;
}

int main()
{
	string str = simplifyPath("/..");

	cout << str << endl;

	return 1;
}