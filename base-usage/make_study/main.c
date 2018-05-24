/*************************************************************************
	> File Name: main.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 29 May 2017 12:31:12 PM CST
 ************************************************************************/

#include <stdio.h>

#include "defs.h"

int main(int argc, char *argv[])
{
	printf("This is in main, VERSION=%s, min version=%d, major version=%d\n",
			VERSION, MIN_VERSION, MAJOR_VERSION );
	help();
	while(kbd())
	{
	}

	return 0;
}
