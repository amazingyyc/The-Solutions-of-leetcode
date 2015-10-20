#include <iostream>
#include <vector>

using namespace std;

/************************************************************************/
/* Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.                                                                     */
/************************************************************************/

void downHeap(vector<int>& heap, int n, int i)
{
	int j;

	while (i <= n / 2)
	{
		j = i;
		if (heap[j] > heap[2 * i])
			j = 2 * i;

		if ((2 * i + 1) <= n && heap[j] > heap[2 * i + 1])
			j = 2 * i + 1;

		if (i == j)
			break;

		swap(heap[i], heap[j]);

		i = j;
	}
}

int findKthLargest(vector<int>& nums, int k) 
{
	vector<int> heap(k + 1);	//Ð¡¶¥¶Ñ
	for (int i = 1; i <= k; ++i)
	{
		heap[i] = nums[i - 1];
	}

	for (int i = k / 2; i > 0; --i)
	{
		downHeap(heap, k, i);
	}

	int size = nums.size();
	for (int i = k; i < size; ++i)
	{
		if (nums[i] > heap[1])
		{
			heap[1] = nums[i];
			downHeap(heap, k, 1);
		}
	}

	return heap[1];
}

int main()
{
	return 0;
}