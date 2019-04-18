// given a set of number.
// to get all combination of number.
// which sum is given number N.

#include <stdio.h>
#include "../header.h"

int sum_solve(int dp[], int size, int set[], int num, int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;

	if (dp[n]!= -1)
		return dp[n];

	dp[n] = 0;
	for(int i = 0; i < num; i++)
	{
		if (n >= set[i])
		{
			int ret = sum_solve(dp, size, set, num, n-set[i]);
			dp[n] += ret;
		}
	}

	return dp[n];
}

// 以下结构可以使用queue即可
/*
struct space {
	Result *result;
	int size;
	int capability;
};
*/

int sum_sovle_result_space(int set[], int num, int n)
{
	Queue *result_space = getQueue();
	Queue *temp_space = getQueue();

	for(int i = 0; i < num; i++)
	{
		if (set[i] < n)
		{
			val_varry *result = getValVarry();
			printf("new: %p\n", result);
			insertValVarry(result, set[i]);
			queue_push_back(temp_space, (void *)result);
		}
		else if (set[i] == n)
		{
			val_varry *result = getValVarry();
			printf("%p\n", result);
			insertValVarry(result, set[i]);
			queue_push_back(result_space, (void *)result);
		}
	}
	while(queue_size(temp_space) > 0)
	{
		val_varry *temp = NULL;
		queue_pop_front(temp_space, (void **)&temp);
		int temp_sum = getSumValVarry(temp);
		int valid = 0;
		for(int i = 0; i < num; i++)
		{
			if (temp_sum + set[i] == n)
			{
				insertValVarry(temp, set[i]);
				queue_push_back(result_space, temp);
				valid = 1;
			} else if (temp_sum + set[i] < n) {
				val_varry *l_temp = copyValVarry(temp);
				insertValVarry(l_temp, set[i]);
				queue_push_back(temp_space, l_temp);
			}
		}
		if (valid != 1)
			releaseValVarry(temp);
	}
	while(queue_size(result_space) > 0)
	{
		val_varry *temp;
		queue_pop_front(result_space, (void **)&temp);
		for(int i = 0; i < sizeValVarry(temp); i++)
		{
			printf("%d ", dataValVarry(temp, i));
		}
		printf("\n");
		releaseValVarry(temp);
	}
	releaseQueue(result_space);
	releaseQueue(temp_space);
	return 0;
}

int test()
{
	int set[] = {1, 3, 5};
	int num = 3;

	int dp[36];
	int size = 36;
	for(int i = 0; i < size; i++)
		dp[i] = -1;

	int n = 6;
	printf("%d:%d\n", n,
			sum_solve(dp, size, set, num, n));

	sum_sovle_result_space(set, num, n);

	return 0;
}

int main()
{
	test();
}

