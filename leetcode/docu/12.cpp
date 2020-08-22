#include "cpp_header.h"

class Solution {
public:
	string intToRoman(int num)
	{
		string res;
		if(num / 1000 > 0)
		{
			int q = num / 1000;
			while(q > 0)
			{
				res += 'M';
				q--;
			}
			num %= 1000;
		}
		if(num / 100 > 0)
		{
			int q = num / 100;
			if(q == 9)
			{
				res += "CM";
			} else if(q == 4)
			{
				res += "CD";
			} else
			{
				if(q > 4)
				{
					res += 'D';
					q -= 5;
				}
				while(q > 0)
				{
					res += 'C';
					q--;
				}
			}
			num %= 100;
		}
		if(num / 10 > 0)
		{
			int q = num / 10;
			if(q == 9)
			{
				res += "XC";
			}
			else if(q == 4)
			{
				res += "XL";
			}
			else
			{
				if(q > 4)
				{
					res += 'L';
					q -= 5;
				}
				while(q > 0)
				{
					res += 'X';
					q--;
				}
			}
			num %= 10;
		}
		if(num > 0)
		{
			int q = num;
			if(q == 9)
			{
				res += "IX";
			}
			else if(q == 4)
			{
				res += "IV";
			}
			else
			{
				if(q > 4)
				{
					res += 'V';
					q -= 5;
				}
				while(q > 0)
				{
					res += 'I';
					q--;
				}
			}
		}

		return res;
		
	}
};

int main()
{
	int num;
	string res;
	int casenum;

	num =3;
	res = "III";
	casenum = 1;
	TESTCASE_p1(intToRoman, num, res, casenum);

	num = 4;
	res = "IV";
	casenum = 2;
	TESTCASE_p1(intToRoman, num, res, casenum);

	num = 9;
	res = "IX";
	casenum = 3;
	TESTCASE_p1(intToRoman, num, res, casenum);

	num = 58;
	res = "LVIII";
	casenum = 4;
	TESTCASE_p1(intToRoman, num, res, casenum);

	num = 1994;
	res = "MCMXCIV";
	casenum = 5;
	TESTCASE_p1(intToRoman, num, res, casenum);

	num = 8;
	res = "VIII";
	casenum = 6;
	TESTCASE_p1(intToRoman, num, res, casenum);

	num = 18;
	res = "XVIII";
	casenum = 7;
	TESTCASE_p1(intToRoman, num, res, casenum);



}
