#include "cpp_header.h"

class Solution {
public:
	int findComplement(unsigned int num)
	{
		int i = 31;
		for( ; i >= 0; i--)
		{
			if(num & (1u << i))
				break;
		}
		while(i >= 0)
		{
			num ^= (1u << i);
			i--;
		}

		return num;
	}
};

int main()
{
	int num;
	int res;
	int casenum;


	num = 5;
	res = 2;
	casenum = 1;
	TESTCASE_p1(findComplement, num, res, casenum);

	num = 1;
	res = 0;
	casenum = 2;
	TESTCASE_p1(findComplement, num, res, casenum);

	num = 2;
	res = 1;
	casenum = 3;
	TESTCASE_p1(findComplement, num, res, casenum);


}
