/*************************************************************************
	> File Name: test_zombie.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 19 Nov 2017 02:56:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigchld_handler(int arg)
{
	printf("child terminate\n");
}

int main()
{
	signal(SIGCHLD, sigchld_handler);
	int fd = fork();
	if(fd > 0){
		int a=0;
		printf("sleep 30 seconds now, can see its chile process is zombie status\n");
		sleep(30);
		printf("sleep one is interapted by signal, need another one\n");
		sleep(3);
		printf("waiting..");
		while(a++ < 10){
			sleep(1);
			printf(".");
			fflush(NULL);
		}
		printf("\n");
	} else if (fd == 0) {
		int a=0;
		printf("in child process, just exit, to become zombie process\n");
		while(a<10){
			sleep(1);
			printf("in child process %d\n", a);
			a++;
		}
		_exit(0);
	} else {
		printf("fork error");
	}
	printf("main process return\n");
	return 0;
}
