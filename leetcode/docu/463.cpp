#include "cpp_header.h"

class Solution {
public:
	int islandPermeter(vector<vector<int>>& grid)
	{
		int count = 0;
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); j++)
			{
				if(grid[i][j] == 1)
				{
					count += 4;
					if(i - 1 >= 0 && grid[i-1][j] == 1)
						count--;
					if(i + 1 < grid.size() && grid[i+1][j] == 1)
						count--;
					if(j - 1 >= 0 && grid[i][j-1] == 1)
						count--;
					if(j + 1 < grid[i].size() && grid[i][j+1] == 1)
						count--;
				}
			}
		}

		return count;
	}
};

int main()
{
	vector<vector<int>> grid;
	int res;
	int casenum;

	grid = {{0,1,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{1,1,0,0}};
	res = 16;
	casenum = 1;
	TESTCASE_p1(islandPermeter, grid, res, casenum);
	
}
