/*************************************************************************
	> File Name: getrusage.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 06 Jun 2017 06:45:42 PM CST
 ************************************************************************/

#include <sys/resource.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "getrusage.h"

int main()
{
	struct rusage rusage;

	int ret = getrusage(RUSAGE_SELF, &rusage);
	if(ret){
		perror("gerrusage");
		exit(EXIT_FAILURE);
	}

	show_rusage(&rusage);

	show_rusagehead();
	show_rusage2(&rusage);

	return 0;
}

