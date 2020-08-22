#include "cpp_header.h"

class Solution {
public:
	int myAtoi(string str)
	{
		int res = 0;

		int i = 0;
		while(str[i] == ' ')
			i++;

		int negative = 0;
		if(str[i] == '-')
		{
			negative = 1;
			i++;
		}
		else if(str[i] == '+')
			i++;

		while(i < str.length() && str[i] >= '0' && str[i] <= '9')
		{
			if(negative == 1)
			{
				if ((0-res) < INT_MIN/10)
				{
					return INT_MIN;
				}
				else if((0-res) == INT_MIN/10)
				{
					if(str[i] - '0' >= 8)
					{
						return INT_MIN;
					}
				}
			}
			else
			{
				if(res > INT_MAX/10)
				{
					return INT_MAX;
				}
				else if(res == INT_MAX/10)
				{
					if(str[i] - '0' >= (INT_MAX%10))
					{
						return INT_MAX;
					}
				}
			}
			res *= 10;
			res += (str[i] - '0');
			i++;
		}

		if(negative == 1)
			res = 0 - res;

		return res;
	}
};


int main()
{
	string str;
	int res;
	int casenum;

	str = "42";
	res = 42;
	casenum = 1;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = "   42";
	res = 42;
	casenum = 2;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = "-42";
	res = -42;
	casenum = 3;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = "+42";
	res = 42;
	casenum = 4;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = "  +42";
	res = 42;
	casenum = 5;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	
	str = "  -42";
	res = -42;
	casenum = 6;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = "  -42   2";
	res = -42;
	casenum = 7;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = " w -42   2";
	res = 0;
	casenum = 8;
	TESTCASE_p1(myAtoi, str, res, casenum);
	
	str = "-11231213455556";
	res = -2147483648;
	casenum = 9;
	TESTCASE_p1(myAtoi, str, res, casenum);

	str = "-2147483648";
	res = -2147483648;
	casenum = 10;
	TESTCASE_p1(myAtoi, str, res, casenum);

	str = "2147483647";
	res = 2147483647;
	casenum = 11;
	TESTCASE_p1(myAtoi, str, res, casenum);

}


