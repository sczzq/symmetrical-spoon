#include "cpp_header.h"

class Solution {
public:
	int reverse2(int x)
	{
		long long min_int = 0 - (1lu << 31);
		long long max_int = (1lu << 31) - 1;

		long long res = 0;
		int negative = 0;

		long long xx = x;

		if(xx < 0)
		{
			negative = 1;
			xx = 0 - xx;
		}
		
		while(xx != 0)
		{
			res *= 10;
			res += (xx % 10);
			xx = xx / 10;
			if(res > max_int+1)
				return 0;
		}

		if(negative == 1)
			res = 0 - res;

		if(res < min_int)
			return 0;

		return (int)res;
	}

	int reverse(int x)
	{
		int res = 0;

		while(x != 0)
		{
			res *= 10;
			res += (x % 10);
			x = x / 10;
			if(res > INT_MAX/10 || res < INT_MIN/10)
				return 0;
		}

		return res;
	}
};

int main()
{
	int x;
	int res;
	int casenum;

	x = 123;
	res = 321;
	casenum = 1;
	TESTCASE_p1(reverse, x, res, casenum);

	x = -123;
	res = -321;
	casenum = 2;
	TESTCASE_p1(reverse, x, res, casenum);

	x = 120;
	res = 21;
	casenum = 3;
	TESTCASE_p1(reverse, x, res, casenum);

	x = -2147483648;
	res = 0;
	casenum = 4;
	TESTCASE_p1(reverse, x, res, casenum);

}


