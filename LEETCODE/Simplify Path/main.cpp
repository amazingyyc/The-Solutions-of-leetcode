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
��Ŀ��Ҫ�������Unix�µ����·����Unix�ļ��ĸ�Ŀ¼Ϊ"/"��"."��ʾ��ǰĿ¼��".."��ʾ�ϼ�Ŀ¼��
���磺
����1��
/../a/b/c/./..
���1��
/a/b
ģ���������̣�
1. "/" ��Ŀ¼
2. ".." ��ת�ϼ�Ŀ¼���ϼ�Ŀ¼Ϊ�գ��������ɴ��� "/"
3. "a" ������Ŀ¼a��Ŀǰ���� "/a"
4. "b" ������Ŀ¼b��Ŀǰ���� "/a/b"
5. "c" ������Ŀ¼c��Ŀǰ���� "/a/b/c"
6. "." ��ǰĿ¼�����������Դ��� "/a/b/c"
7. ".." �����ϼ�Ŀ¼������Ϊ "/a/b"
*/
/************************************************************************/

//��str����c start��ʼ���� ����޷��ҵ��򷵻�str.size
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
		//Խ��'/'
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