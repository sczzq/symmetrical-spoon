/*************************************************************************
	> File Name: param.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 09 May 2018 11:10:41 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/param.h>

int main()
{
	printf("max path length: %d\n", MAXPATHLEN);
	printf("max open file: %d\n", NOFILE);
}
