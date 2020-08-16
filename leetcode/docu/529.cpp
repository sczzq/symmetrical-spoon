#include "cpp_header.h"

class Solution {
	bool has_unrevealed(vector<vector<char>>& board)
	{
		bool has_un = false;
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
			{
				if(board[i][j] == 'E')
				{
					has_un = true;
					break;
				}
			}
			if(has_un == true)
			{
				break;
			}
		}

		return has_un;
	}

	void setAdjacent(vector<vector<char>>& board, int x, int y)
	{
		for(int i = x - 1; i <= x+1; i++)
		{
			for(int j = y - 1; j <= y + 1; j++)
			{
				if(x == i && y == j)
					continue;
				if(i >= 0 && i < board.size() && j >= 0 && j < board[i].size())
				{
					if(board[i][j] != 'E')
						continue;

					int adjacent_mine_num = countAdjacentMine2(board, i, j);
					if(adjacent_mine_num == 0)
					{
						board[i][j] = 'B';
						setAdjacent(board, i, j);
					}
					else
					{
						board[i][j] = adjacent_mine_num + '0';
					}
				}
			}
		}
	}

public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
	{
		// check adjacent whether is mine
		int x = click[0], y = click[1];

		// check whether is mine
		if(board[x][y] == 'M')
		{
			board[x][y] = 'X';
			return board;
		}

		if(has_unrevealed(board) == false)
		{
			return board;
		}

		int adjacent_mine_num = countAdjacentMine2(board, x, y);
		if(adjacent_mine_num > 0)
		{
			board[x][y] = adjacent_mine_num + '0';
			return board;
		}
		else
		{
			board[x][y] = 'B';
			setAdjacent(board, x, y);
		}

		return board;
	}

	int countAdjacentMine2(vector<vector<char>>& board, int x, int y)
	{
		int adjacent_mine_num = 0;
		for(int i = x-1; i <= x+1; i++)
		{
			for(int j = y-1; j <= y+1; j++)
			{
				if(i == x && j == y)
					continue;
				if(i >= 0 && i < board.size() && j >= 0 && j < board[i].size())
				{
					if(board[i][j] == 'M')
					{
						adjacent_mine_num++;
					}
				}
			}
		}

		return adjacent_mine_num;
	}

	int countAdjacentMine(vector<vector<char>>& board, vector<int>& click)
	{
		int adjacent_mine_num = 0;
		if(click[0] == 0) // upper boundary
		{
			if(click[1] == 0)
			{
				// click[0]+1, click[1]
				// click[0], click[1]+1
				// click[0]+1,click[1]+1
				if(board[click[0]+1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
			else if(click[1] > 0 && click[1] < board[click[0]].size() - 1)
			{
				// click[0]+1,click[1]
				// click[0], click[1]+1
				// click[0], click[1]-1
				// click[0]+1, click[1]+1
				// click[0]+1, click[1]-1
				if(board[click[0]+1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
			else if(click[1] == board[click[0]].size() - 1)
			{
				// click[0]+1,click[1]
				// click[0],click[1]-1
				// click[0]+1,click[1]-1
				if(board[click[0]+1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
		}
		else if (click[0] > 0 && click[0] < board.size() -1 )
		{
			if(click[1] == 0)
			{
				// click[0]-1,click[1]
				// click[0]+1,click[1]
				// click[0]-1,click[1]+1
				// click[0]+1,click[1]+1
				// click[0],click[1]+1
				if(board[click[0]-1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
			else if(click[1] > 0 && click[1] < board[click[0]].size() - 1)
			{
				// click[0]-1,click[1]-1
				// click[0]-1,click[1]
				// click[0]-1,click[1]+1
				// click[0],click[1]-1
				// click[0],click[1]+1
				// click[0]+1,click[1]-1
				// click[0]+1,click[1]
				// click[0]+1,click[1]+1
				if(board[click[0]-1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
			else if(click[1] == board[click[0]].size() - 1)
			{
				// click[0]-1,click[1]-1
				// click[0]-1,click[1]
				// click[0],click[1]-1
				// click[0]+1,click[1]-1
				// click[0]+1,click[1]
				if(board[click[0]-1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]+1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
			}
		}
		else if(click[0] == board.size() - 1) // lower boundary
		{
			if(click[1] == 0)
			{
				// click[0]-1,click[1]
				// click[0]-1,click[1]+1
				// click[0],click[1]+1
				if(board[click[0]-1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
			else if(click[1] > 0 && click[1] < board[click[0]].size() - 1)
			{
				// click[0]-1,click[1]-1
				// click[0]-1,click[1]
				// click[0]-1,click[1]+1
				// click[0],click[1]-1
				// click[0],click[1]+1
				if(board[click[0]-1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]+1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
			else if(click[1] == board[click[0]].size() - 1)
			{
				// click[0]-1,click[1]-1
				// click[0]-1,click[1]
				// click[0],click[1]-1
				if(board[click[0]-1][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]-1][click[1]] == 'M')
				{
					adjacent_mine_num++;
				}
				if(board[click[0]][click[1]-1] == 'M')
				{
					adjacent_mine_num++;
				}
			}
		}

		return adjacent_mine_num;
	}
};

int testcase(vector<vector<char>> & board, vector<int> click, int res)
{
	Solution sol;

	cout << "---------------\n";
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] == 'E')
				cout << ". ";
			else
				cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------\n";

	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			cout << sol.countAdjacentMine2(board, i, j) << " ";
		}
		cout << "\n";
	}
	cout << "----------------------------------------\n";
}

int testcase2(vector<vector<char>> & board, int x, int y, vector<vector<char>> & res, int casenum)
{
	Solution sol;

	vector<int> click{x, y};
	sol.updateBoard(board, click);

	bool equal = true;
	for(int i = 0; i < board.size(); i++)
	{
		for(int j = 0; j < board[i].size(); j++)
		{
			if(board[i][j] != res[i][j])
			{
				equal = false;
				break;
			}
		}
		if(equal == false)
			break;
	}
	if(equal == false)
	{
		cout << casenum << " no pass\n";
		cout << "details: \n";
		for(int i = 0; i < board.size(); i++)
		{
			for(int j = 0; j < board[i].size(); j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << casenum << " pass\n";
	}


}


int main()
{
	vector<vector<char>> board, res;
	vector<int> click;
	int casenum;

	board = {{'E', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'M', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			};
	testcase(board, click, 0);

	board = {{'M', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'M', 'E', 'E'},
			 {'E', 'M', 'E', 'E', 'E'},
			 {'E', 'M', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			};
	testcase(board, click, 0);

	board = {{'E', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'M', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			};
	res  =  {{'B', '1', 'E', '1', 'B'},
			 {'B', '1', 'M', '1', 'B'},
			 {'B', '1', '1', '1', 'B'},
			 {'B', 'B', 'B', 'B', 'B'},
			 {'B', 'B', 'B', 'B', 'B'},
			};
	casenum = 1;
	testcase2(board, 3, 0, res, 1);

	board = {{'M', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'M', 'E', 'E'},
			 {'E', 'M', 'E', 'E', 'E'},
			 {'E', 'M', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			};
	res   = {{'M', 'E', 'E', 'E', 'E'},
			 {'E', 'E', 'M', 'E', 'E'},
			 {'E', 'M', 'E', 'E', 'E'},
			 {'2', 'M', 'E', 'E', 'E'},
			 {'E', 'E', 'E', 'E', 'E'},
			};
	testcase2(board, 3, 0, res, 2);

	board = {{'M', 'E', 'E', 'E', 'E'}};
	res   = {{'M', '1', 'B', 'B', 'B'}};
	casenum = 3;
	testcase2(board, 0, 3, res, casenum);

	board = {{'M', 'E', 'E', 'E', 'E'}};
	res   = {{'M', '1', 'E', 'E', 'E'}};
	casenum = 4;
	testcase2(board, 0, 1, res, casenum);

	board = {{'M', 'E', 'E', 'E', 'E'}};
	res   = {{'X', 'E', 'E', 'E', 'E'}};
	casenum = 5;
	testcase2(board, 0, 0, res, casenum);

	board = {{'M', '1', 'E', 'E', 'E'}};
	res   = {{'M', '1', 'B', 'B', 'B'}};
	casenum = 6;
	testcase2(board, 0, 2, res, casenum);

	board = {{'M', 'E', 'E', 'E', 'E'}};
	res   = {{'M', '1', 'B', 'B', 'B'}};
	casenum = 7;
	testcase2(board, 0, 4, res, casenum);

	board = {{'M', 'E'}};
	res   = {{'M', '1'}};
	casenum = 8;
	testcase2(board, 0, 1, res, casenum);

	board = {{'M', 'E'}};
	res   = {{'X', 'E'}};
	casenum = 9;
	testcase2(board, 0, 0, res, casenum);

	board = {{'M'}, {'E'}};
	res   = {{'X'}, {'E'}};
	casenum = 10;
	testcase2(board, 0, 0, res, casenum);

	board = {{'M'}, {'1'}};
	res   = {{'M'}, {'1'}};
	casenum = 11;
	testcase2(board, 0, 1, res, casenum);

	board = {{'M'}};
	res   = {{'X'}};
	casenum = 12;
	testcase2(board, 0, 0, res, casenum);

	board = {{'E'}};
	res   = {{'B'}};
	casenum = 13;
	testcase2(board, 0, 0, res, casenum);

}

