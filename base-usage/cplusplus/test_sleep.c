/*************************************************************************
	> File Name: test_sleep.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 21 May 2017 04:24:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>

int foo(int sec)
{
	printf("sleep for %d\n", sec);
	sleep(sec);
	return sec;
}

int main()
{
	int times = 10;
	while(times--)
		foo(times);

	return 0;
}
