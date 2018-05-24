/*************************************************************************
	> File Name: test_atexit.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 10 May 2017 04:26:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

static void firstexit(void)
{
	printf("%s, %d, %s\n", __FILE__, __LINE__, __func__);
}

static void secondexit(void)
{
	printf("%s, %d, %s\n", __FILE__, __LINE__, __func__);
}

int
main()
{
	if(atexit(firstexit) != 0){
		fprintf(stderr, "register first exit error\n");
		exit(1);
	}
	if(atexit(secondexit) != 0){
		fprintf(stderr, "register second exit error\n");
		exit(2);
	}
	if(atexit(firstexit) != 0){
		fprintf(stderr, "register first exit error\n");
		exit(3);
	}
	if(atexit(firstexit) != 0){
		fprintf(stderr, "register first exit error\n");
		exit(4);
	}

//	_exit(0);
	return 0;
//	exit(0);
}
