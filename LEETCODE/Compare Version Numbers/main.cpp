#include <iostream>

using namespace std;

int compareVersion(string version1, string version2) 
{
	int n1 = version1.size();
	int n2 = version2.size();

	int start1 = 0;
	int start2 = 0;

	while (start1 < n1 && start2 < n2)
	{
		int dot1 = start1;
		int dot2 = start2;

		while (dot1 < n1 && '.' != version1[dot1]) dot1++;
		while (dot2 < n2 && '.' != version2[dot2]) dot2++;

		int num1 = atoi(version1.substr(start1, dot1 - start1).c_str());
		int num2 = atoi(version2.substr(start2, dot2 - start2).c_str());

		if (num1 > num2) return 1;
		if (num1 < num2) return -1;

		start1 = (dot1 == n1) ? n1 : dot1 + 1;
		start2 = (dot2 == n2) ? n2 : dot2 + 1;
	}

	if (start1 < n1)
	{
		while (start1 < n1)
		{
			int dot1 = start1;

			while (dot1 < n1 && '.' != version1[dot1]) dot1++;

			int num1 = atoi(version1.substr(start1, dot1 - start1).c_str());

			if (num1 > 0)	return 1;

			start1 = (dot1 == n1) ? n1 : dot1 + 1;
		}

		return 0;
	}
	if (start2 < n2)
	{
		while (start2 < n2)
		{
			int dot2 = start2;

			while (dot2 < n2 && '.' != version2[dot2]) dot2++;

			int num2 = atoi(version2.substr(start2, dot2 - start2).c_str());

			if (num2 > 0)	return -1;

			start2 = (dot2 == n2) ? n2 : dot2 + 1;
		}

		return 0;
	}

	return 0;
}

int main()
{
	compareVersion("1.0", "1");

	return 1;
}