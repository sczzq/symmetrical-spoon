/*************************************************************************
	> File Name: test_fork.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 10 May 2017 08:57:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
//#include <sleep.h>

pid_t 
make_process(pid_t *process, int number)
{
	pid_t p = fork();
	if(p != 0){
		process[number++] = p;
		return p;
	}
	int times = 0;
	while(1){
		sleep(1);
		times++;
		printf("in process %d\n", getpid());
		if(times == 2)
			break;
	}
	return p;
}

int
main()
{
	pid_t process[20] = {0};
	int number = 0;

	while(1){
		sleep(1);
		pid_t p = make_process(process, number++);
		printf("create process %d\n", p);
		if(number == 10)
			break;
	}

	while(1){
		int status = 0;
		sleep(1);
//		int p = wait(&status);
//		if( p == -1){
//			printf("all child process return\n");
//			break;
//		} else {
//			printf("process %d return\n", p);
//		}
	}

	return 0;
}

