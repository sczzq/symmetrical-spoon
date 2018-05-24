/*************************************************************************
	> File Name: int.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 11 Dec 2017 11:34:18 PM CST
 ************************************************************************/

#include <stdio.h>

int main()
{
	printf("1: %d\n", 1);
	printf("1 & 0xff: %d\n", 1 & 0xff);
	printf("(1<<1) & 0xff: %d\n", (1<<1) & 0xff);
	printf("(1<<3) & 0xff: %d\n", (1<<3) & 0xff);
}
