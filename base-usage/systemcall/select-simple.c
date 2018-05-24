/*************************************************************************
	> File Name: select-simple.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 25 May 2017 10:56:11 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/select.h>
#include <time.h>

int main(int argc, char * argv[])
{
	struct timeval tv;

	tv.tv_sec = 10;
	tv.tv_usec = 0;

	select(1, NULL, NULL, NULL, &tv);

	return 0;
}
