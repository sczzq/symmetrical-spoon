/*************************************************************************
	> File Name: callstack.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 06 Jun 2017 10:30:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int dep = 0;

int foo(int a)
{
	usleep(100);
}

int h()
{
	printf("%d\t", ++dep);
	char *p = malloc(1024);
	foo(1);
	h();
	free(p);
}

int main()
{
	h();
}

