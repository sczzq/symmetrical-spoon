/*************************************************************************
	> File Name: openmax.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 09 May 2018 10:55:38 AM CST
 ************************************************************************/

#include <stdio.h>

#include <limits.h>
#include <unistd.h>

int openmax()
{
	int openmax = 0;
	if((openmax = sysconf(_SC_OPEN_MAX)) < 0){
		fprintf(stderr, "sysconf error error for _SC_OPEN_MAX");
		openmax = 1024;
	}
	return openmax;
}

int main()
{
	printf("openmax %d\n", openmax());
}
