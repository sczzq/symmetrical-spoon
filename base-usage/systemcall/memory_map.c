/*************************************************************************
	> File Name: memory_map.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Thu 25 May 2017 10:07:33 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int a;
int b = 0;
static int c = 1;

int foo(int);
int h(int);

int foo(int arg)
{
	printf("function address: %p\n", &foo);
	printf("in function foo, argument address %p\n", &arg);
	char a[100] = {0};
	printf("in function foo, local variable address %p\n", a);
	char* p = (char *)malloc(100);
	printf("in function foo, malloc address %p\n", p);
	free(p);
	h(1);

	return 0;
}

int h(int arg)
{
	printf("function address: %p\n", &h);
	printf("in function h, argument address %p\n", &arg);
	char a[100] = {0};
	printf("in function h, local variable address %p\n", a);
	char* p = (char *)malloc(100);
	printf("in function h, malloc address %p\n", p);
	free(p);

	static int hha = 0;
	printf("in function h, static variable address %p\n", &hha);

	return 0;
}

int main(int argc, char* argv[])
{
	printf("main function address %p\n", &main);
	printf("in main, argument address %p, %p\n", &argc, argv);
	printf("global variable address %p\n", &a);
	printf("global variable address %p\n", &b);
	printf("global variable address %p\n", &c);

	foo(1);
	h(1);
}


