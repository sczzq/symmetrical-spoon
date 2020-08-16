#include "cpp_header.h"

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		vector<vector<int>> zo_nums(strs.size(), vector<int>(2, 0));
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

		int res = 0;
		for(int i = 0; i < zo_nums.size(); i++)
		{
			if(zo_nums[i][0] > m || zo_nums[i][1] > n)
				continue;

			int ires = findmax(i + 1, m, n, zo_nums);
			int jres = findmax(i + 1, m-zo_nums[i][0], n-zo_nums[i][1], zo_nums);

			res = max(res, max(ires, jres + 1));
		}

		return res;
	}

	int findmax(int j, int m, int n, vector<vector<int>>& zo_nums)
	{
		int res = 0;

		while(j < zo_nums.size())
		{
			if(zo_nums[j][0] <= m && zo_nums[j][1] <= n)
				break;
			j++;
		}

		if(j >= zo_nums.size())
			return 0;

		int ires = findmax(j + 1, m, n, zo_nums);
		int jres = findmax(j + 1, m-zo_nums[j][0], n-zo_nums[j][1], zo_nums);

		res = max(res, max(ires, jres + 1));

		return res;
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
	res = 10;
	casenum = 3;
	TESTCASE_p3(findMaxForm, strs, m, n, res, casenum);

}



