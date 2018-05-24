/*************************************************************************
	> File Name: malloc.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 06 Jun 2017 10:16:01 PM CST
 ************************************************************************/

#include <stdlib.h>

int main(int argc, char *argv[])
{
	long long size = 1024*1024*100;
	char *p = (char *)malloc(size);
	free(p);

	return 0;
}
