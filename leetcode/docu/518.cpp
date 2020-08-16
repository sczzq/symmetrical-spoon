#include "cpp_header.h"

class Solution {
public:
	int change(int amount, vector<int> coins)
	{
		vector<int> dp(amount+1, 0);
		dp[0] = 1;

		for(int coin : coins){
			for(int i = coin; i <= amount; i++)
			{
				dp[i] = dp[i] + dp[i-coin];
			}
		}

		return dp[amount];
	}
};

int main()
{
	int amount;
	vector<int> coins;
	int res;
	int casenum;

	amount = 5;
	coins = {1,2,5};
	res = 4;
	casenum = 1;

	TESTCASE_p2(change, amount, coins, res, casenum);

	amount = 10;
	coins = {10};
	res = 1;
	casenum = 2;

	TESTCASE_p2(change, amount, coins, res, casenum);

	amount = 6;
	coins = {1,2,3};
	res = 7;
	casenum = 3;

	TESTCASE_p2(change, amount, coins, res, casenum);


	amount = 500;
	coins = {1,2,5};
	res = 12701;
	casenum = 4;

	TESTCASE_p2(change, amount, coins, res, casenum);


}

