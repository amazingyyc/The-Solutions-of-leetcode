#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
/************************************************************************/

vector<int> getRow(int rowIndex) 
{
	vector<int> pas(rowIndex + 1, 1);

	for (int i = 2; i <= rowIndex; ++i)
	{
		for (int j = i - 1; j > 0; --j)
			pas[j] = pas[j] + pas[j - 1];
	}

	return pas;
}

int main()
{
	return 1;
}