#include "cpp_header.h"

class Solution {
public:
	bool isPalindrome(int x)
	{
		if(x < 0)
			return false;


		int xx = x;
		int i = 0;
//		int prefix = x, postfix = x;

		while(xx != 0)
		{
			i++;
			xx /= 10;
		}

		int pow10k[11];
		for(int j = 0; j < i; j++)
		{
			pow10k[j] = pow10(j);
		}

		while(i > 1)
		{
			if(x%10 != x/pow10k[i-1])
				return false;
			x %= pow10(i-1);
			x /= 10;
			i -= 2;
		}

		return true;
	}

	int pow10(int k)
	{
		int res = 1;
		while(k>0)
		{
			res *= 10;
			k--;
		}

		return res;
	}
};

int main()
{
	int x;
	bool res;
	int casenum;

	x = 121;
	res = true;
	casenum = 1;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = -121;
	res = false;
	casenum = 2;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = 10;
	res = false;
	casenum = 3;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = 101;
	res = true;
	casenum = 4;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = 1;
	res = true;
	casenum = 5;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = 0;
	res = true;
	casenum = 6;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = INT_MAX;
	res = false;
	casenum = 7;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = INT_MAX-1;
	res = false;
	casenum = 8;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = 123454321;
	res = true;
	casenum = 9;
	TESTCASE_p1(isPalindrome, x, res, casenum);

	x = 1221;
	res = true;
	casenum = 10;
	TESTCASE_p1(isPalindrome, x, res, casenum);

}
