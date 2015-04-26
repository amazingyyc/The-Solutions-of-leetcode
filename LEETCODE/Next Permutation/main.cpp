#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* 
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1                                                                     
*/
/************************************************************************/

/*
从后向前 遍历 会有4种情况 
1：一致递减， 只需要反转最后两个元素即可
2：递减会在某个地方停止 反转最后两个元素
3:已知递增 反转整个序列
4：递增在某个地方停止 比如num[i] < num[i+1] 只需要将num【i】与之后的大于num【i】最小的元素交换 然后反转 后续的数组 即可
*/
void nextPermutation(vector<int> &num) 
{
	int size = num.size();

	if (0 == size || 1 == size)	return;

	//去除相等的元素
	int i = size - 1;
	while (i >= 1 && num[i] == num[i - 1])	--i;

	//整个序列都相等
	if (0 == i)	return;

	//int r = i;

	if (num[i] > num[i - 1])
	{
		//属于从左向右的递减序列 只需要反转最后两个元素
		swap(num[i], num[i - 1]);
		return;
	}
		
	for (; i >= 1; --i)
	{
		if (num[i - 1] < num[i])
			break;
	}

	int l = i;
	int r = size - 1;

	if (0 != i)
	{
		int j;
		for (j = i; j < r; ++j)
		{
			if (num[j] >= num[i - 1] && num[j + 1] <= num[i - 1])
				break;
		}

		swap(num[i - 1], num[j]);
	}

	while (l < r)
	{
		swap(num[l++], num[r--]);
	}
}

int main()
{
	vector<int> num;
	num.push_back(5);
	num.push_back(1);
	num.push_back(1);

	nextPermutation(num);

	return 1;
}