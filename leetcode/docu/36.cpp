#include "cpp_header.h"
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		for(int i = 0; i < board.size(); i++)
		{
			char mark[10] = {0};
			for(int j = 0; j < board[i].size(); j++)
			{
				if(board[i][j] == '.')
					continue;

				if(mark[board[i][j] - '0'] != 0)
				{
					return false;
				}
				mark[board[i][j] - '0'] = 1;

			}
		}

		for(int i = 0; i < 9; i++)
		{
			char mark[10] = {0};
			for(int j = 0; j < 9; j++)
			{
				if(board[j][i] == '.')
					continue;

				if(mark[board[j][i] - '0'] != 0)
				{
					return false;
				}
				mark[board[j][i] - '0'] = 1;
			}
		}

		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				char mark[10] = {0};
				for(int m = 0; m < 3; m++)
				{
					for(int n = 0; n < 3; n++)
					{
						int x = m + i * 3;
						int y = n + j * 3;
						if(board[x][y] == '.')
							continue;
						if(mark[board[x][y] - '0'] != 0)
							return false;
						mark[board[x][y] - '0'] = 1;
					}
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<vector<char>> board;
	int res;
	int casenum;

	board = {
			{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
			{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
			{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
			{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
			{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
			{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
			{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
			{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
			{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
			};
	res = true;
	casenum = 1;

	TESTCASE_p1(isValidSudoku, board, res, casenum);



}

