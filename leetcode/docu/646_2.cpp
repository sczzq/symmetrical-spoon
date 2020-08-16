#include "cpp_header.h"

class Solution {
public:
	struct {
		bool operator()(const vector<int>& a, const vector<int>& b) const
		{
			return a[0] < b[0];
		}
	}customLess;

	int findLongestChain(vector<vector<int>>& pairs) 
	{
		int count = 0;
		vector<int> lens(pairs.size(), 1);

		sort(pairs.begin(), pairs.end(), customLess);

		for(int i = 0; i < pairs.size(); i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(pairs[i][0] > pairs[j][1])
				{
					lens[i] = max(lens[i], lens[j] + 1);
				}
			}
			if(count < lens[i])
				count = lens[i];
		}

		return count;
	}
};

int testcase(vector<vector<int>> pairs, int res, int casenum)
{
	Solution sol;
	if(sol.findLongestChain(pairs) == res)
	{
		cout << casenum << " pass\n";
	}
	else
	{
		cout << casenum << " no pass\n";
	}
}

int main()
{
	Solution s;
	vector<vector<int>> pairs{{1,2}, {2,3}, {3,4}};
	int res;
	int casenum;

	res = 2;
	casenum = 0;
	testcase(pairs, res, casenum);

	pairs = {{1,2}, {3,7}, {3,5}, {4,5}, {4,7}, {5,7}, {6,7}, {4, 6}};
	res = 3;
	casenum = 1;
	testcase(pairs, res, casenum);

	pairs = {{1,2}, {3,7}, {3,5}, {4,5}, {4,7}, {5,7}, {6,7}};
	res = 3;
	casenum = 2;
	testcase(pairs, res, casenum);

	pairs = {{1,2}, {3,7}, {3,5},{3,4}, {4,5}, {4,7}, {5,7}, {6,7}};
	res = 3;
	casenum = 3;
	testcase(pairs, res, casenum);

	pairs = {{1,2}};
	res = 1;
	casenum = 4;
	testcase(pairs, res, casenum);

	pairs =	{{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
	res = 3;
	casenum = 5;
	testcase(pairs, res, casenum);

}

