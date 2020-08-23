#include "cpp_header.h"


/*
101101 / 10 = 10110
101101 / 100 = 1011

101101 / 110 = 101101 / 11*10
= (101101 / 10) * (101101 / 11)
= 10110 * 

10 * 10 = 100
10 * 1 = 10

1010 / 11 = 11.1

10 * 1 = 10
1 * 1 = 1

11 = 10 + 1 = 10 * 1 + 1 * 1

100 + 10 = 10*10 + 10*1 = 10*11 = 11*10
*/

class Solution {
public:
	int divide(int dividend, int divisor)
	{
		if(dividend > 0 && divisor > 0)
		{
			int first = 0, second = 1;
			int i = divisor;
			while(1)
			{
				if((dividend >> 1) < i)
				{
				}

				if(dividend - i < divisor)

				i += i;
				first++;
				second++;
			}
		}
	}
};


