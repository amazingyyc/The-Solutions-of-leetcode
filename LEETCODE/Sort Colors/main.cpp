#include <iostream>

using namespace std;

/************************************************************************/
/* Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?                                                                     */
/************************************************************************/

//使用一个指针进行遍历 为0放到左边 为2放到右边 使用两个指针作为边界
void sortColors(int A[], int n) 
{
	if (0 == n || 1 == n)	return;

	int r = 0;
	int w = 0;
	int b = n - 1;
	
	while (w <= b)
	{
		if (0 == A[w])
			swap(A[r++], A[w++]);
		else if (2 == A[w])
			swap(A[w], A[b--]);
		else
			w++;
	}
}

int main()
{
	int A[2] = { 1, 0 };

	sortColors(A, 2 );

	return 1;
}