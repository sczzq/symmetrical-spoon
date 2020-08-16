#include "cpp_header.h"

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M)
	{
		vector<set<int>> quans(M.size(), set<int>());

		for(int i = 0; i < M.size(); i++)
		{
			for(int j = i; j < M[0].size(); j++)
			{
				if(M[i][j] == 1)
				{
					quans[i].insert(j);
					quans[j].insert(i);
				}
			}
		}

		for(int i = 0; i < quans.size(); i++)
		{
			for(auto x : quans[i])
			{
				cout << x << " ";
			}
			cout << "\n";
		}
		cout << "------------------\n";

		sort(quans.begin(), quans.end());
		auto last = unique(quans.begin(), quans.end());
		quans.erase(last, quans.end());

		int count = -1;
		while(count != quans.size())
		{
			count = quans.size();
			for(int i = 0; i < quans.size(); i++)
			{
				for(auto &s : quans[i])
				{
					for(int j = i + 1; j < quans.size(); j++)
					{
						if(quans[j].find(s) != quans[j].end())
						{
							quans[i].insert(quans[j].begin(), quans[j].end());
							quans.erase(quans.begin() + j);
							j--;
						}
					}
				}
			}
		}

		for(auto it = quans.begin(); it != quans.end(); it++)
		{
			for(auto x : *it)
			{
				cout << x << " ";
			}
			cout << "\n";
		}

		return quans.size();
	}

};

int testcase(vector<vector<int>> M, int res, int casenum)
{
	Solution sol;

	if(sol.findCircleNum(M) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
		cout << res << "\n";
	}
	cout << "--------------------------------------\n";
}

int main()
{
	vector<vector<int>> M;
	int res;
	int casenum;

	M = {{1,1,0},
		 {1,1,0},
		 {0,0,1}};
	res = 2;
	casenum = 1;

	testcase(M, res, casenum);

	M = {{1,1,0},
		 {1,1,1},
		 {0,1,1}};
	res = 1;
	casenum = 2;

	testcase(M, res, casenum);

	M = {{1,0,0,1},
		 {0,1,1,0},
		 {0,1,1,1},
		 {1,0,1,1}};
	res = 1;
	casenum = 3;

	testcase(M, res, casenum);




}


