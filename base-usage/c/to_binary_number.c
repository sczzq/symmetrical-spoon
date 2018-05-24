/*************************************************************************
	> File Name: binary_number.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 16 Apr 2017 11:42:27 AM CST
 ************************************************************************/

#include <stdio.h> // printf
#include <stdint.h> // INT_MIN, INT_MAX, UINT_MAX
#include <stdlib.h> // atoi

void print2(int);
void print3(int);

void print2v(void *, int);
void print3v(void *, int);

void print2(int a)
{
	int i, j;
	for(i = sizeof(a)-1; i >= 0; i--){
		for(j = 7; j >= 0; j--){
			if(a & (1<<(8*i+j))) printf("1");
			else printf("0");
		}
		printf(" ");
	}
	printf("\n");
}

void print2v(void *a, int size)
{
	int i, j;
	char c;
	char *p = (char *)a;
	for(i = size-1; i >= 0; i--){
		c = p[i];
		for(j = 7; j >= 0; j--){
			if(c & (1<<j)) printf("1");
			else printf("0");
		}
		printf(" ");
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int a = 0;
	if(argc >= 2)
		a = atoi(argv[1]);
	printf("%d(d) = ", a);
	print2v(&a, sizeof(a));
	printf("%d(d) = ", a);
	print3(a);

	return 0;
}

void print3(int a){
	int b[512] ;
	int i = 0;
	while(a){
		if(a%2) b[i++] = 1;
		else b[i++] = 0;
		a >>= 1;
	}
	while(i)
		printf("%d", b[--i]);
	printf("\n");
}

