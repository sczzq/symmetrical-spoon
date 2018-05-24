/*************************************************************************
	> File Name: utils.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 29 May 2017 03:48:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include "defs.h"

int help(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
	printf("input 1, 2, 3, 4\n");
}


void get(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
}

void release(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
}

