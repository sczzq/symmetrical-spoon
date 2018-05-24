/*************************************************************************
	> File Name: driver.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 23 Jan 2018 09:04:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include "number.h"

int main()
{
	int a = 30, b = 10;
	for(b = 10; b < a; b++)
		printf("a=%d, b=%d, gcf=%d\n", a, b, greatest_common_divisor(a,b));
	return 0;
}

