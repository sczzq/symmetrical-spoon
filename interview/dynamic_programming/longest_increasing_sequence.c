
#include "../header.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int lis_naive(int *src, int *dst, int num)
{
	int dp[num];
	for(int i = 0; i < num; i++)
	{
		dp[i] = 0;
	}

	int max = 0;
	for(int i = 0; i < num; i++)
	{
		for(int j = i+1; j < num; j++)
		{
			if(src[i] < src[j])
			{
				dp[i]++;
			}
		}
		if (max < dp[i])
			max = dp[i];
	}
	for(int i = 0; i < num; i++)
	{
	}
	printf("max: %d\n", max);
}

int longest_increasing_sequence(int *src, int *dst, int num)
{
	int last = 0, cur = 1, next = 2;
	int index = 0;
	for(int i = 1; i < num ; i++)
	{
		cur = i;
//		if (src[last] < src[cur] && src[last])
//		if (src[last] < src[cur] && src[cur] > src[next] && src[last] < src[next] )
		{
		}
	}
}

int lis_test()
{
#define INT_LENGTH 10
	int s1[INT_LENGTH];
	int s2[INT_LENGTH];
	int len = INT_LENGTH;

	random_integer(s1, len, 50);
	for(int i = 0; i < len; i++)
		printf("%d ", s1[i]);
	printf("\n");

	lis_naive(s1, s2, len);
}


int main()
{
	lis_test();
}
