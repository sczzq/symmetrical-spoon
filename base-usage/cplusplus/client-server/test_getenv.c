/*************************************************************************
	> File Name: test_getenv.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 10 May 2017 04:53:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int getallenv()
{

	char buffer[1024];
	char *p;
	p = getenv("COLUMNS");
	if(p)
		printf("COLUMNS = %s\n", p);
	p = getenv("DATEMSK");
	if(p)
		printf("DATEMSK = %s\n", p);
	p = getenv("HOME");
	if(p)
		printf("HOME = %s\n", p);
	p = getenv("LANG");
	if(p)
		printf("LANG = %s\n", p);
	p = getenv("LC_ALL");
	if(p)
		printf("LC_ALL = %s\n", p);
	p = getenv("LC_COLLATE");
	if(p)
		printf("LC_COLLATE = %s\n", p);
	p = getenv("LC_CTYPE");
	if(p)
		printf("LC_CTYPE = %s\n", p);
	p = getenv("LC_MESSAGES");
	if(p)
		printf("LC_MESSAGES = %s\n", p);
	p = getenv("LC_NUMERIC");
	if(p)
		printf("LC_NUMERIC = %s\n", p);
	p = getenv("LC_TIME");
	if(p)
		printf("LC_TIME = %s\n", p);
	p = getenv("LINES");
	if(p)
		printf("LINES = %s\n", p);
	p = getenv("MSGVERB");
	if(p)
		printf("MSGVERB = %s\n", p);
	p = getenv("NLSPATH");
	if(p)
		printf("NLSPATH = %s\n", p);
	p = getenv("PATH");
	if(p)
		printf("PATH = %s\n", p);
	p = getenv("PWD");
	if(p)
		printf("PWD = %s\n", p);
	p = getenv("SHELL");
	if(p)
		printf("SHELL = %s\n", p);
	p = getenv("TERM");
	if(p)
		printf("TERM = %s\n", p);
	p = getenv("TMPDIR");
	if(p)
		printf("TMPDIR = %s\n", p);
	p = getenv("TZ");
	if(p)
		printf("TZ = %s\n", p);
	return 0;
}

int main()
{
	getallenv();
}
