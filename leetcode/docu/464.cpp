#include "cpp_header.h"

class Solution {
public:
	bool visited[30];
	int max_choosable_integer, desired_total;

	bool dfs (int total_sum)
	{
		if(total_sum >= desired_total) return true;
		for(int i = 1; i <= max_choosable_integer; i++)
		{
			if(visited[i]) continue;
			visited[i] = true;
			if(dfs(total_sum + i))
			{
				visited[i] = false;
				return false;
			}
			visited[i] = false;
		}

		return true;
	}

	bool canIWin(int maxChoosableInteger, int desiredTotal)
	{
		max_choosable_integer = maxChoosableInteger;
		desired_total = desiredTotal;

		for(int i = 1; i <= max_choosable_integer; i++)
		{
			memset(visited, 0, sizeof(visited));
			visited[i] = true;
			if(dfs(i)) return true;
		}

		return false;
	}
};

int testcase(int maxChoosableInteger, int desiredTotal, bool res, int casenum)
{
	Solution sol;

	if(sol.canIWin(maxChoosableInteger, desiredTotal) == res)
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
	Solution sol;
	
	int maxChoosableInteger = 10;
	int desiredTotal = 40;
	bool res = false;
	int casenum = 1;

	testcase(maxChoosableInteger, desiredTotal, res, casenum);

	maxChoosableInteger = 10;
	desiredTotal = 11;
	res = false;
	casenum = 2;
	testcase(maxChoosableInteger, desiredTotal, res, casenum);


	maxChoosableInteger = 10;
	desiredTotal = 100;
	res = false;
	casenum = 3;
	testcase(maxChoosableInteger, desiredTotal, res, casenum);

	maxChoosableInteger = 10;
	desiredTotal = 12;
	res = true;
	casenum = 4;
	testcase(maxChoosableInteger, desiredTotal, res, casenum);

}


