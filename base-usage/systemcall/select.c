/*************************************************************************
	> File Name: select.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 24 May 2017 03:51:28 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

#include "socket.h"

#undef max
#define max(a, b) ((a) > (b) ? (a) : (b))

bool empty(int* fds, fd_set* rfds, int n)
{
	for(int i=0; i<n; i++){
		// if has one fd in set, then the set is not empty.
		if(FD_ISSET(fds[i], rfds))
			return false;
	}

	// here, all of the fds is not in set, then set is empty.
	return true;
}

/*
 * issue: 
 * if fd_num equlas 1, then select() returns until timeout, and return value is -1,
 * if fd_num greater then 1, then select() return immidiately, and the last socket file desctiptor is not in set using FD_ISSET() to check.
 *
 */

int 
main(void)
{
	fd_set rfds;


	FD_ZERO(&rfds);
	int nfds = 1;
	int fd_num = 10*1000;
	int fds[10*1000];

	for(int i=0; i<fd_num; i++){
		int fd = getsocket(AF_INET, SOCK_STREAM);
		if(fd < 0){
			fd_num = i;
			break;
		}
		fds[i] = fd;
		FD_SET(fd, &rfds);
		nfds = max(nfds, fd);
	}

	printf("true=%d, false=%d\n", true, false);

	for(int i=0; i<fd_num; i++){
		printf("fd=%d is %d\n", fds[i], FD_ISSET(fds[i], &rfds));
	}

	while(!empty(fds, &rfds, fd_num)){

		struct timeval tv;
		tv.tv_sec = 5;
		tv.tv_usec = 0;

		int retval = select(nfds, &rfds, NULL, NULL, &tv);

		if(retval == -1)
			perror("select()");
		else if(retval){
			printf("data is available now.\n");
			for(int i=0; i<fd_num; i++){
//				printf("fd=%d is %d\n", fds[i], FD_ISSET(fds[i], &rfds));
			}
		}
		else
			printf("No data within five seconds.\n");

		break;
	}

	for(int i=0; i<fd_num; i++){
		if(fds[i] > 2)
			close(fds[i]);
	}

	exit(EXIT_SUCCESS);
}

