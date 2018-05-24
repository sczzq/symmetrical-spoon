/*************************************************************************
	> File Name: feima.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 22 Jan 2018 09:37:14 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long *power_result = NULL;
int total_size = 128;
int max_index = 0;

/* 自然数的指数
 * 返回自然数
 */
inline long long power(int n, int p)
{
	if(n < 0)
		return 0;
	if(n == 0)
		return 1;
	if(power_result[n] > 0)
		return power_result[n];
	long long r = n;
	while(--p)
		r *= n;
	if(n >= total_size-2){
		printf("total_size: %d, sizeof(long long): %lu, mul: %lu \n", total_size, sizeof(long long), total_size * 2 * sizeof(long long));
		power_result = (long long *)realloc(power_result, sizeof(long long) * total_size * 2);
		memset(power_result+total_size, 0, total_size * sizeof(long long));
		total_size *= 2;
	}
//	printf("n: %d, power: %lld, total size: %d\n", n, r, total_size);
	return power_result[n] = r;
}

int main()
{
	power_result = (long long *)malloc(sizeof(long long) * total_size);
	memset(power_result, 0, sizeof(long long) * total_size);
	int a = 1, b = 1, c = 2;
	int p = 3;

	int i = 1000*1000*1000;
#if 0
	while(--i ){
		int ta = a;
		for( ; ta < c; ++ta){
			int tb = ta;
			for( ; tb < c; ++tb){
				check_feima(ta, tb, c, p);
				printf("a = %d, b = %d, c = %d\n", ta, tb, c);
			}
		}
		++c;
	}
#endif
	while(i--){
		int ta = a;
		for( ; ta < c; ++ta){
			int tb = ta;
			for( ; tb < c; ++tb){
				long long tap = power(ta, p);
				long long tbp = power(tb, p);
				long long cp = power(c, p);
				if(tap + tbp < cp){
//					printf("lower, a=%d, b = %d, c = %d, p = %d\n", ta, tb, c, p);
					continue;
				} else if (tap + tbp == cp){
					printf("result, a=%d, b = %d, c = %d, p = %d\n", ta, tb, c, p);
				}
				else {
//					printf("greater, a=%d, b = %d, c = %d, p = %d\n", ta, tb, c, p);
					break;
				}
			}
		}
		++c;
	}
}
