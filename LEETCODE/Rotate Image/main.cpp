#include <iostream>
#include <vector>

using namespace std;

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

void rotate(vector<vector<int> > &matrix) 
{
	int N = matrix.size();

	//��ת90�Ⱦ��������� ��ת Ȼ�� ���������� ��ת
	for (int i = 0; i < N / 2; ++i)
	for (int j = 0; j < N; ++j)
		swap(matrix[i][j], matrix[N - 1 - i][j]);
	
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < i; ++j)
		swap(matrix[i][j], matrix[j][i]);
}

int main()
{
	return 1;
}