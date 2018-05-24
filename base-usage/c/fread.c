/*************************************************************************
	> File Name: fread.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 13 Dec 2017 09:30:47 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE   1024

int main()
{
	char buff[BUF_SIZE] = {0};

	while(fread(buff, 1, BUF_SIZE, stdin)){
		fwrite(buff, 1, strlen(buff), stdout);
		memset(buff, 0, BUF_SIZE);
	}
	exit(EXIT_SUCCESS);
}

