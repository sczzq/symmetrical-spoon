/*************************************************************************
	> File Name: test_select.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 08:01:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
	while(1) {
		fd_set rd;
		struct timeval tv;
		int err;

		FD_ZERO(&rd);
		FD_SET(0, &rd);

		tv.tv_sec = 5;
		tv.tv_usec = 0;
		err = select(1, &rd, NULL, NULL, &tv);
		if(err == -1) {
			perror("select error()\n");
		}else if(err == 0) {
			printf("no data is avaliable now\n");
		}else{
			if(FD_ISSET(0, &rd)) {
				char buf[1024];
				fgets(buf, sizeof(buf), stdin);
				printf("%s",buf);
			}
		}
	}
	return 0;
}

