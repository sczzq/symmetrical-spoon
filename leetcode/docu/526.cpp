#include "cpp_header.h"

class Solution {
public:
	int countArrangement(int N)
	{
		if(N < 4) return N;

		vector<vector<int>> marks(N+1); 

		cout << "---------------------\n";

		for(int i = 1; i <= N; i++)
		{
			vector<int> mark;
			for(int j = 1; j <= N; j++)
			{
				if(i < j)
				{
					if(j % i == 0)
					{
						mark.push_back(j);
					}
				}
				else
				{
					if(i % j == 0)
					{
						mark.push_back(j);
					}
				}
			}
			marks[i] = mark;
		}

		/*
		for(int i = 1; i < marks.size(); i++)
		{
			cout << i << " : ";
			for(auto x : marks[i])
			{
				cout << x << "  ";
			}
			cout << "\n";
		}
		*/

		//cout << "---------------------------------\n";

		vector<int> res(N+1, 0);
		for(int i = 0; i < marks[1].size(); i++)
		{
			res[1] = marks[1][i];

			findout(marks, 2, res, N);
		}

		return count;
	}

	int count = 0;

	void findout(vector<vector<int>> & marks, int j, vector<int> & res, int N)
	{
		if(res.back() != 0)
		{
			count++;
			return;
		}
		for(auto x : marks[j])
		{
			if(res[j] == 0)
			{
				if(find(res.begin(), res.end(), x) == res.end())
				{
					res[j] = x;
					findout(marks, j+1, res, N);
					res[j] = 0;
				}
			}
		}
	}
};

void testcase(int N, int res, int casenum)
{
	Solution sol;
	if(sol.countArrangement(N) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << "detail: \n";
		cout << N << "\n";
	}
}

int main()
{
	Solution sol;
	sol.countArrangement(3);
	sol.countArrangement(4);
	sol.countArrangement(5);
	sol.countArrangement(6);

	testcase(1, 1, 1);
	testcase(2, 2, 2);
	testcase(3, 3, 3);
	testcase(4, 8, 4);
	testcase(5, 10, 5);
	testcase(6, 36, 6);
	testcase(7, 41, 7);
	testcase(8, 132, 8);
	testcase(9, 250, 9);
	testcase(10, 700, 10);
	testcase(11, 750, 11);
	testcase(12, 4010, 12);
	testcase(13, 4237, 13);
	testcase(14, 10680, 14);
	testcase(15, 24679, 15);
}

