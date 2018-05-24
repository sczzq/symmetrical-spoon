/*************************************************************************
	> File Name: test_sscanf.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 10 May 2017 03:49:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int test(const char *str)
{
	int length = strlen(str);
	if(length > 1024)
		return 0;
	char path[1024] = {0};
	char port[1024] = {0};
	char addr[1024] = {0};
	char start[1024] = {0};
	char end[1024] = {0};

	sscanf(str, "http://%15s:%4s/%s/download.ts?from=%s&to=%s", path, port, addr, start, end);

	printf("%s\n", path);
	printf("%s\n", port);
	printf("%s\n", addr);
	printf("%s\n", start);
	printf("%s\n", end);
}

int foo()
{
	const char *a = "http://192.168.1.1:2001/a/b-d/b/download.ts?from=2012121212000-12102012&to=1020200200100-1020002002";
	test(a);
}

int main()
{
	foo();
}
