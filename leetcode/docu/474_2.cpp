#include "cpp_header.h"

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		vector<vector<int>> zo_nums(strs.size(), vector<int>(2, 0));
		vector<vector<int>> min_prefix(m+1, vector<int>(n+1,0));

		for(int i = 0; i < strs.size(); i++)
		{
			for(auto c : strs[i])
			{
				if(c == '0')
					zo_nums[i][0]++;
				else if(c == '1')
					zo_nums[i][1]++;
			}
		}

		for(int i = 0; i < zo_nums.size(); i++)
		{
			for(int zeroes = m; zeroes >= zo_nums[i][0]; zeroes--)
				for(int ones = n; ones >= zo_nums[i][1]; ones--)
					min_prefix[zeroes][ones] = max(1+min_prefix[zeroes-zo_nums[i][0]][ones-zo_nums[i][1]], min_prefix[zeroes][ones]);
		}

		return min_prefix[m][n];
	}
};


int  main()
{
	vector<string> strs;
	int m, n;
	int res;
	int casenum;

	strs = {"10", "0001", "111001", "1", "0"};
	m = 5;
	n = 3;
	res = 4;
	casenum = 1;

	TESTCASE_p3(findMaxForm, strs, m, n, res, casenum);

	strs = {"10", "0", "1"};
	m = 1;
	n = 1;
	res = 2;
	casenum = 2;

	TESTCASE_p3(findMaxForm, strs, m, n, res, casenum);

	strs = {"0","11","1000","01","0","101","1","1","1","0","0","0","0","1","0","0110101","0","11","01","00","01111","0011","1","1000","0","11101","1","0","10","0111"};
	m = 9;
	n = 80;
	res = 17;
	casenum = 3;
	TESTCASE_p3(findMaxForm, strs, m, n, res, casenum);

}



