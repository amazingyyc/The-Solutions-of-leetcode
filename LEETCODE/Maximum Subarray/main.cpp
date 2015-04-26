#include <iostream>
#include <algorithm>

using namespace std;

/*int maxSubArray(int A[], int n) 
{
	if (0 == n)	return 0;

	int maxSum = A[0];
	for (int i = 1; i < n; ++i)
	if (A[i] > maxSum)
		maxSum = A[i];

	for (int i = 0; i < n;)
	{
		if (A[i] <= 0)
		{
			i++;
			continue;
		}

		int index = i;
		int max = A[i];
		int sum = max;
		for (int j = i + 1; j < n; ++j)
		{
			sum += A[j];

			if (sum >= max)
			{
				max = sum;
				index = j;
			}
		}

		sum = A[i];
		int min = sum;
		for (int j = i + 1; j <= index; ++j)
		{
			sum += A[j];

			if (sum < min)
				min = sum;
		}

		if (min < 0)
			max -= min;

		if (max > maxSum)
			maxSum = max;

		i = index + 1;
	}

	return maxSum;
}*/

/************************************************************************/
/* 最大连续子序列和，非常经典的题。
当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它有几种选择呢？它只有两种
选择： 1、加入之前的 SubArray； 2. 自己另起一个 SubArray。那什么时候会出现这两种情况呢？
如果之前 SubArray 的总体和大于 0 的话，我们认为其对后续结果是有贡献的。这种情况下我们
选择加入之前的 SubArray
如果之前 SubArray 的总体和为 0 或者小于 0 的话，我们认为其对后续结果是没有贡献，甚至是
有害的（小于 0 时）。这种情况下我们选择以这个数字开始，另起一个 SubArray。
设状态为 f[j] ，表示以 S[j] 结尾的最大连续子序列和，则状态转移方程如下：
f [ j ] = max {f [j − 1] + S [j ], S [j ]} , 其中 1 ≤ j ≤ n
target = max {f [j ]} , 其中 1 ≤ j ≤ n
解释如下：
• 情况一， S[j] 不独立，与前面的某些数组成一个连续子序列，则最大连续子序列和为
f [j − 1] + S [j ]。
• 情况二， S[j] 独立划分成为一段，即连续子序列仅包含一个数 S[j]，则最大连续子序列和为
S [j ]。                                                                     */
/************************************************************************/

int maxSubArray(int A[], int n)
{
	int preSum = A[0];	//preSum表示 i之前的最大子序列之和
	int maxSum = preSum;

	for (int i = 1; i < n; ++i)
	{
		if (preSum > 0)
			preSum += A[i];
		else
			preSum = A[i];

		if (preSum > maxSum)
			maxSum = preSum;
	}

	return maxSum;
}

int main()
{
	int A[9] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	int sum = maxSubArray(A, 9);

	cout << sum << endl; 

	return 1;
}