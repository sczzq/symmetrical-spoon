#include "cpp_header.h"

class Solution {
public:
	int max_choosable_integer, desired_total;
	map<unsigned int, bool> mp;
	unsigned int one = 1;

	bool dfs (int total_sum, unsigned int visited)
	{
		if(total_sum >= desired_total)
		{
			return true;
		}

		if(mp.find(visited) != mp.end() )
		{
			return mp[visited];
		}

		bool ret = true;
		for(int i = 1; i <= max_choosable_integer; i++)
		{
			if(visited & (one << i)) continue;

			unsigned int visited_cur = visited;
			visited_cur |= (one << i);

			if(dfs(total_sum + i, visited_cur))
			{
				ret = false;
				break;
			}
		}

		return mp[visited] = ret;
	}

	bool canIWin(int maxChoosableInteger, int desiredTotal)
	{
		max_choosable_integer = maxChoosableInteger;
		desired_total = desiredTotal;

		if(maxChoosableInteger <= desiredTotal) return true;

		if((maxChoosableInteger+1) * maxChoosableInteger / 2 < desiredTotal) return false;

		for(int i = 1; i <= max_choosable_integer; i++)
		{
			unsigned int visited = 0;
			visited |= (one << i);
			if(dfs(i, visited)) return true;
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

