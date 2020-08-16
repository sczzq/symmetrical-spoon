#include "cpp_header.h"

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M)
	{
		vector<vector<int>> mark(M.size(), vector<int>(M[0].size(), 0));

		int count = 0;

		while(innerUpdate(M, mark))
		{
			count++;
		}

		return count;
	}

	bool innerUpdate(vector<vector<int>>& M, vector<vector<int>>& mark)
	{
		bool has_update = false;

		for(int i = 0; i < mark.size(); i++)
		{
			for(int j = 0; j < mark[i].size(); j++)
			{
				if(mark[i][j] == 0 && M[i][j] == 1)
				{
					update(M, i, j, mark);
					has_update = true;
				}
			}

		}

		return has_update;
	}

	void update(vector<vector<int>>& M, int x, int y, vector<vector<int>>& mark)
	{
		mark[x][y] = 1;
		if((x-1) >= 0 && M[x-1][y] == 1 && mark[x-1][y] == 0)
		{
			update(M, x-1, y, mark);
		}
		if((x+1)<mark.size() && M[x+1][y] == 1 && mark[x+1][y] == 0)
		{
			update(M, x+1, y, mark);
		}
		if((y-1) >= 0 && M[x][y-1] == 1 && mark[x][y-1] == 0)
		{
			update(M, x, y-1, mark);
		}
		if((y+1)<mark[x].size() && M[x][y+1] == 1 && mark[x][y+1] == 0)
		{
			update(M, x, y+1, mark);
		}
	}
};

