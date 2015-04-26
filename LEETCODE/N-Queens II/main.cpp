#include <iostream>

using namespace std;

int getNumbers(int n, int level, int* list, int* left, int* right)
{
	if (n == level)	return 1;

	int result = 0;

	for (int i = 0; i < n; ++i)
	{
		if (list[i] || left[n - 1 - level + i] || right[2 * n - 2 - level - i])
			continue;

		list[i] = 1;
		left[n - 1 - level + i] = 1;
		right[2 * n - 2 - level - i] = 1;

		result += getNumbers(n, level + 1, list, left, right);

		list[i] = 0;
		left[n - 1 - level + i] = 0;
		right[2 * n - 2 - level - i] = 0;
	}

	return result;
}

int totalNQueens(int n) 
{
	//list对应与列 left对应与左倾 right对应与右倾  (i,j) left[n-1-i+j] right[2n-2-i-j]
	int* list  = (int*)malloc(sizeof(int)*n);
	int* left  = (int*)malloc(sizeof(int)*(2 * n - 1));
	int* right = (int*)malloc(sizeof(int)*(2 * n - 1));

	for (int i = 0; i < n; ++i)
		list[i] = 0;

	for (int i = 0; i < 2 * n - 1; ++i)
		left[i] = right[i] = 0;

	int result = getNumbers(n, 0, list, left, right);

	free(list);
	free(left);
	free(right);

	return result;
}

int main()
{
	int result = totalNQueens(5);

	cout << result << endl;

	return 1;
}