/*************************************************************************
	> File Name: test_watchtime.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 08:03:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#include <stdio.h>        //printf()
#include <unistd.h>        //pause()
#include <signal.h>        //signal()
#include <string.h>        //memset()
#include <sys/time.h>    //struct itimerval, setitimer()

static int count = 0;

void printMes(int signo)
{
	printf("Get a SIGALRM, %d counts!\n", ++count);
}

int main()
{
	int res = 0;
	struct itimerval tick;

	signal(SIGALRM, printMes);
	memset(&tick, 0, sizeof(tick));

	tick.it_value.tv_sec = 1;
	tick.it_value.tv_usec = 0;

	tick.it_interval.tv_sec = 1;
	tick.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL, &tick, NULL);

	while(1)
	{
	}
	return 0;
}
