#include <stdio.h>
#include "utility.h"
#include <sys/time.h>
#include <string.h>

int fib1(int n)
{
	if (n <= 1)
		return n;
	return fib1(n-1) + fib1(n-2);
}

int fib2(int n)
{
	int f[n];
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

int test1(int n)
{
	START_TIME;
	int f1 = fib1(n);
	END_TIME;
	printf("f1:%d\n", f1);
	return 0;
}

int test2(int n)
{
	START_TIME;
	int f2 = fib2(n);
	END_TIME;
	printf("f2:%d\n", f2);
}

int main()
{
	int n = 10;
	test1(n);
	test2(n);

	n = 50;
	test1(n);
	test2(n);

	n = 100;
	test1(n);
	test2(n);

}

