/*************************************************************************
    > File Name: cpuusage.c
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年10月06日 星期六 10时14分15秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <time.h>

inline void dosum(long int times)
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
		dosum(base * n);
		clock_gettime(CLOCK_REALTIME, &tv2);
		long long cosume = (tv2.tv_sec - tv1.tv_sec) * 1000000000;
		cosume += tv2.tv_nsec - tv1.tv_nsec ;
		cosume /= 1000000;
		if (cosume >= usec) {
			break;
		}
		n++;
	}
	long int time = (tv2.tv_sec - tv1.tv_sec) * 1000000000 + (tv2.tv_nsec - tv1.tv_nsec);

	printf("Done, %d usec is %d times.\n", usec, base * n);
	printf("its acturally time is %ld nanoseconds.\n", time);

	// usec.
	int a_usec = time / 1000000;
	// times per usec.
	long int times = base * n / a_usec;

	printf("actural usec: %d, times: %ld\n", a_usec, times);

	return times;
}

int cpuusage()
{
	// get times of 0.001 seconds.
	long int times1 = get_times(100000, 1);

	// get times of 1 seconds.
	long int times2 = get_times(times1 * 10000, 1000);

	int n = 10;
	while(1) {
		dosum(times2 * n);
		usleep((1000 - n) * 1000);
		if (n == 990) {
			n = 10;
			printf("n is begining\n");
		}
		n += 10;
	}

	return 0;
}

int main()
{
	cpuusage();
}
