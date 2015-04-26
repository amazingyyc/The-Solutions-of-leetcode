#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//����
bool isValidSudoku(vector<vector<char> > &board) 
{
	if (board.size() != 9 )	return false;

	//�ֱ�洢 ���ж�Ӧ�� �ַ��͸���
	unordered_map<char, int> map[3][9];

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if ('.' == board[i][j])
				continue;

			if (map[0][i][board[i][j]] || map[1][j][board[i][j]] || map[2][(j / 3) * 3 + i / 3][board[i][j]])
				return false;

			map[0][i][board[i][j]]++;
			map[1][j][board[i][j]]++;
			map[2][(j / 3) * 3 + i / 3][board[i][j]]++;
		}
	}

	return true;
}

int main()
{
	return 1;
}