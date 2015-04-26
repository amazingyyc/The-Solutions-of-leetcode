#include <iostream>

using namespace std;

/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

//一个单数 乘以 一个长数组
string oneMultiplyString(string str, char c)
{
	if ('0' == c)	return "0";
	if ('1' == c)	return str;

	string result = "";
	int multi = c - '0';
	int enter = 0;	//上次计算的进高位
	int size = str.size();
	for (int i = size - 1; i >= 0; --i)
	{
		int num = (str[i] - '0')*multi + enter;

		result = char(num%10 + '0') + result;

		enter = num / 10;
	}

	if (0 != enter)
		result = char(enter + '0') + result;

	return result;
}

//两个string 相加
string addString(string str1, string str2)
{
	int s1 = str1.size();
	int s2 = str2.size();

	string result = "";
	int enter = 0;
	while (0 < s1 || 0 < s2)
	{
		char c1 = (0 < s1) ? str1[--s1] : '0';
		char c2 = (0 < s2) ? str2[--s2] : '0';

		int num = (c1 - '0') + (c2 - '0') + enter;

		result = char(num % 10 + '0') + result;

		enter = num / 10;
	}

	if (0 != enter)
		result = char(enter + '0') + result;

	return result;
}

string multiply(string num1, string num2) 
{
	string result = "";
	int size2 = num2.size();

	for (int i = size2 - 1, k = 0; i >= 0; --i, ++k)
	{
		string temp = oneMultiplyString(num1, num2[i]);

		if (temp != "0")
		{
			for (int j = 0; j < k; ++j)
				temp += "0";
		}
		

		result = addString(result, temp);
	}

	return result;
}

int main()
{
	string str = multiply("0", "52");

	cout << str.c_str() << endl;

	return 1;
}