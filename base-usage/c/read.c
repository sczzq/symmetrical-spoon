/*************************************************************************
	> File Name: read.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 13 Dec 2017 09:26:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main()
{
	char buff[BUF_SIZE] = {0};
	while(read(STDIN_FILENO, buff, BUF_SIZE)){
		write(STDOUT_FILENO, buff, strlen(buff));
		memset(buff, 0, BUF_SIZE);
	}
	exit(EXIT_SUCCESS);
}
