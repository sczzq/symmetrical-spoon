/*************************************************************************
	> File Name: test_exit.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 10 May 2017 07:28:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void 
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status), 
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : "");
#else
				"" );
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}

int
main()
{
	pid_t pid;
	int status;

	if((pid = fork()) < 0){
		fprintf(stderr, "fork error");
		return 0;
	} else if(pid == 0)
		exit(7);

	if(wait(&status) != pid){
		fprintf(stderr, "wait error");
		return 0;
	}
	pr_exit(status);

	if((pid = fork() ) < 0){
		fprintf(stderr, "fork error");
		return 0;
	} else if(pid == 0){
		abort();
	}

	if(wait(&status) != pid){
		fprintf(stderr, "wait error");
		return 0;
	}
	pr_exit(status);

	if((pid = fork()) < 0){
		fprintf(stderr, "fork error");
		return 0;
	} else if(pid == 0){
		status /= 0;
	}

	if(wait(&status) != pid){
		fprintf(stderr, "wait error");
		return 0;
	}
	pr_exit(status);

	exit(0);
}
