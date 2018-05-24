/*************************************************************************
	> File Name: file_flag_and_position.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Fri 15 Dec 2017 09:39:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDWR | O_APPEND);
	if(fd < 0){
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	printf("file content: \n");
	char rbuf[1024] = {0};
	while(read(fd, rbuf, sizeof(rbuf)) > 0){
		write(STDOUT_FILENO, rbuf, strlen(rbuf));
		printf("11111\n");
		sleep(1);
	}
	struct stat fst;
	if(fstat(fd, &fst)) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}

#if 1
	if(-1 == lseek(fd, fst.st_size/2, SEEK_SET)){
		perror("lseek");
		exit(EXIT_FAILURE);
	}
#endif
	char wbuf[512] = "12345678";
	if(write(fd, wbuf, strlen(wbuf)) != strlen(wbuf)){
		perror("write");
		char buf[512];
		if(read(fd, buf, sizeof(buf)) < 0){
			perror("read");
		} else {
			printf("%s\n", buf);
		}
		exit(EXIT_FAILURE);
	}

	printf("write %s from %d\n", wbuf, fst.st_size/2);
	memset(rbuf, 0, sizeof(rbuf));
	pread(fd, rbuf, sizeof(rbuf), 0);
	sleep(1);
	printf("22222\n");
	write(STDOUT_FILENO, rbuf, strlen(rbuf));

	size_t ws = write(fd, wbuf, strlen(wbuf));
	printf("write size: %lu\n", ws);
	lseek(fd, 0, SEEK_SET);
	memset(rbuf, 0, sizeof(rbuf));
	size_t rs = read(fd, rbuf, sizeof(rbuf));
	printf("read size: %lu\n", rs);
	printf("read content: %s\n", rbuf);
	close(fd);
	exit(EXIT_SUCCESS);
}

