/*************************************************************************
	> File Name: command.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 29 May 2017 02:57:50 PM CST
 ************************************************************************/

#include <stdio.h>
#include "defs.h"
#include "command.h"

void command_add(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
	cadd();
}

void command_show(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
	display();
}

void command_search(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
	search();
}

void command_release(void)
{
	printf("%s, %s, %d\n", __FILE__, __func__, __LINE__);
	release();
}

