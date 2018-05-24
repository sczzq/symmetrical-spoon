#include "primer.h"

int test_FILE(void)
{
	FILE *fp = fopen("/home/zhu/source/11.c", "r");
	if(fp == NULL)
		return 1;
	fclose(fp);

	return 0;
}
