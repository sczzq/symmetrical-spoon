/*************************************************************************
    > File Name: cpuusage.c
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年10月06日 星期六 10时14分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <time.h>

void dosum(long int times)
{
	while(times--)
		;
}

long int get_times(int base, int usec)
{
	struct timespec tv1, tv2;
	int n = 1;
	printf("get times of %d usec. 1 usec = 0.001 second.\n", usec);
	while(1) {
		clock_gettime(CLOCK_REALTIME, &tv1);
		dosum((long int)base * n);
		clock_gettime(CLOCK_REALTIME, &tv2);
		long long cosume = (tv2.tv_sec - tv1.tv_sec) * 1000000000;
		cosume += tv2.tv_nsec - tv1.tv_nsec ;
		cosume /= 1000000;
		if (cosume >= usec) {
			break;
		}
		n++;
	}
	long long int time = (tv2.tv_sec - tv1.tv_sec) * 1000000000 + (tv2.tv_nsec - tv1.tv_nsec);

	printf("Done, %d usec is %lld times.\n", usec, base * n);
	printf("its acturally time is %ld nanoseconds.\n", time);

	// usec.
	int a_usec = time / 1000000;
	// times per usec.
	long int times = base * n / a_usec;

	printf("actural usec: %d, times: %ld\n", a_usec, times);
	printf("----------------------------\n");

	return times;
}

int linear_add()
{
	// get times of 0.001 seconds.
	long int times1 = get_times(100000, 1);

	// get times of 1 seconds.
	long int times2 = get_times(times1 * 10000, 1000);

	int n = 10, step = 10;
	int precision = 1000;
	printf ("cpu load usage linear add\n");
	while(1) {
		dosum((long int)times2 * n);
		usleep((precision - n) * precision);
		if (n > precision) {
			n = step;
			printf("n is begining\n");
		}
		n += step;
	}

	return 0;
}

int cpuusage(int usage)
{
	// get times of 0.001 seconds.
	long int times1 = get_times(100000, 1);

	// get times of 1 seconds.
	long int times2 = get_times(times1 * 10000, 1000);

	int n = 10, step = 10;
	int precision = 1000;
	printf ("cpu load usage: %d\n", usage);

	long int cacl_times = usage * times2 / 100;
	printf("cacl times %ld every second\n", cacl_times);
	long long int temp = 1000000 * (times2 - cacl_times) / times2;
	int sleep_time = temp;
	printf("sleep time %d us every second\n", sleep_time);

	while(1) {
		dosum(cacl_times);
		usleep(sleep_time);
		n += step;
		printf(".");
	}

	return 0;
}

int main(int argc, char *argv[])
{

	int usage = 20;
	if (argc == 2)
	{
		usage = atoi(argv[1]);
	}
	cpuusage(usage);
}
