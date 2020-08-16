#include "cpp_header.h"

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>  matrix)
	{
		while(true == innerUpdate(matrix))
		{
		}

		return matrix;
	}

	void showMatrix(vector<vector<int>> & matrix)
	{
		for(int i = 0; i < matrix.size(); i++)
		{
			for(int j = 0; j < matrix[i].size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "------------------------\n";
	}

	bool innerUpdate(vector<vector<int>> & matrix)
	{
		int has_update = false;
		showMatrix(matrix);
		for(int i = 0; i < matrix.size(); i++)
		{
			for(int j = 0; j < matrix[i].size(); j++)
			{
				if(matrix[i][j] != 0)
				{
					int lowest = INT_MAX;
					int last = matrix[i][j];
					if((i - 1) >= 0 && lowest > matrix[i-1][j])
					{
						lowest = matrix[i-1][j];
					}
					if((i+1) < matrix.size() && lowest > matrix[i+1][j])
					{
						lowest = matrix[i+1][j];
					}
					if((j-1) >= 0 && lowest > matrix[i][j-1])
					{
						lowest = matrix[i][j-1];
					}
					if((j+1) < matrix[i].size() && lowest > matrix[i][j+1])
					{
						lowest = matrix[i][j+1];
					}
					matrix[i][j] = lowest + 1;
					if(last != matrix[i][j])
					{
						has_update = true;
					}
				}
			}
		}
		return has_update;
	}
};

int testcase(vector<vector<int>> matrix, vector<vector<int>> res, int casenum)
{
	Solution sol;

	matrix = sol.updateMatrix(matrix);

	bool equal = true;
	for(int i = 0; i < matrix.size(); i++)
	{
		for(int j = 0; j < matrix[i].size(); j++)
		{
			if(matrix[i][j] != res[i][j])
			{
				equal = false;
				break;
			}
		}
		if(equal == false)
		{
			break;
		}
	}

	if(equal == false)
	{
		cout << casenum << " no pass\n";
		for(int i = 0; i < matrix.size(); i++)
		{
			for(int j = 0; j < matrix[i].size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << casenum << " pass\n";
	}
	cout << "--------------------------------\n";
}

int main()
{
	vector<vector<int>> matrix;
	vector<vector<int>> res;
	int casenum;

	matrix = {{0,0,0},
			  {0,1,0},
			  {0,0,0}};

	res =    {{0,0,0},
			  {0,1,0},
			  {0,0,0}};

	casenum = 1;
	testcase(matrix, res, casenum);

	matrix = {{0,0,0},
			  {0,1,0},
			  {1,1,1}};

	res =    {{0,0,0},
			  {0,1,0},
			  {1,2,1}};

	casenum = 2;
	testcase(matrix, res, casenum);

	matrix = {{0,0,0}};
	res =    {{0,0,0}};

	casenum = 3;
	testcase(matrix, res, casenum);

	matrix = {{0,1,0}};
	res =    {{0,1,0}};

	casenum = 4;
	testcase(matrix, res, casenum);

	matrix = {{0}};
	res =    {{0}};

	casenum = 5;
	testcase(matrix, res, casenum);

	matrix = {{1,0}};
	res =    {{1,0}};

	casenum = 6;
	testcase(matrix, res, casenum);

	matrix = {{0,1,0},
			  {0,1,0},
			  {0,1,0}};

	res =    {{0,1,0},
			  {0,1,0},
			  {0,1,0}};

	casenum = 7;
	testcase(matrix, res, casenum);

	matrix = {{0,1,0},
			  {1,1,0},
			  {1,1,0}};

	res =    {{0,1,0},
			  {1,1,0},
			  {2,1,0}};

	casenum = 8;
	testcase(matrix, res, casenum);

	matrix = {{0,0,0,1,0},
			  {1,0,1,0,1},
			  {1,1,1,1,0},
			  {1,1,1,1,0}};

	res =    {{0,0,0,1,0},
			  {1,0,1,0,1},
			  {2,1,2,1,0},
			  {3,2,2,1,0}};

	casenum = 9;
	testcase(matrix, res, casenum);


}


