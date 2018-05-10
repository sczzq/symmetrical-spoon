/*************************************************************************
	> File Name: xmalloc.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 10 May 2018 10:33:53 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xmalloc.h"

void * xmalloc(size_t size)
{
	void * data = malloc(size);
	if(!data){
		fprintf(stderr, "malloc error\n");
		exit(EXIT_FAILURE);
	}
	memset(data, 0, size);
	return data;
}

