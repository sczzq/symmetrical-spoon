/*************************************************************************
	> File Name: client_tcp.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Sun 04 Jun 2017 12:18:03 PM CST
 ************************************************************************/

#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <strings.h>
#include <stdlib.h>

void setnonblocking(int sock)
{
	int opts;
	opts=fcntl(sock,F_GETFL);
	if(opts<0)
	{
		perror("fcntl(sock,GETFL)");
		exit(EXIT_FAILURE);
	}
	opts = opts|O_NONBLOCK;
	if(fcntl(sock,F_SETFL,opts)<0)
	{
		perror("fcntl(sock,SETFL,opts)");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char * argv[])
{
	int portnumber;
	if ( 2 == argc )
	{
		if( (portnumber = atoi(argv[1])) < 0 )
		{
			fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
			return 1;
		}
	}
	else
	{
		fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]);
		return 1;
	}

	struct sockaddr_in serveraddr;
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	char *local_addr = "127.0.0.1";
	inet_aton(local_addr, &(serveraddr.sin_addr));
	serveraddr.sin_port = htons(portnumber);

	if(-1 == connect(fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr))){
		printf("connect error %d\n", errno);
		printf("EISCONN %d\n", EISCONN);
		perror("connect");
		close(fd);
		exit(EXIT_FAILURE);
	}

	int epfd;
	struct epoll_event event;
	//生成用于处理accept的epoll专用的文件描述符
	epfd=epoll_create(256);
	setnonblocking(fd);
	event.data.fd=fd;
	event.events = EPOLLIN | EPOLLOUT | EPOLLET;
	epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);

	char *filepath = "test.txt";
	FILE *pf = fopen(filepath, "r");
	if(pf == NULL){
		perror("fopen: ");
		return -1;
	}
#define MAXLINE (1024*16)
	char buffer[MAXLINE], read_buffer[MAXLINE];
	int write_size = 0, filesize;
	struct stat st;
	stat(filepath, &st);
	filesize = st.st_size;
	int i, n, sockfd, nfds;
	printf("file %s size is %d\n", filepath, filesize);

	for ( ; ; ) {
		printf("total write size is %d\n", write_size);
		nfds = epoll_wait(epfd, &event, 1, 500);

		//处理所发生的所有事件
		for(i=0; i<nfds; ++i)
		{

			if ( (sockfd = event.data.fd) < 0)
				continue;
			if(event.events & EPOLLIN)
			{
				printf("EPOLLIN\t");
				if ( (n = read(sockfd, read_buffer, MAXLINE)) < 0) {
					if (errno == ECONNRESET) {
						close(sockfd);
						event.data.fd = -1;
					} else
						printf("socket %d readline error\n", sockfd);
				} else if (n == 0) {
					close(sockfd);
					event.data.fd = -1;
				}
				printf("read %d bytes from socket %d\n", n, sockfd);
				event.data.fd = sockfd;
				event.events = EPOLLOUT;
				epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&event);
			}
			if(event.events & EPOLLOUT) // 如果有数据发送
			{
				n = fread(buffer, 1, MAXLINE, pf);
				printf("read %d bytes from file %s\n", n, filepath);
				if(n > 0){
					write_size += n;
					n = write(sockfd, buffer, n);
					if(n < 0){
						if (errno == ECONNRESET) {
							close(sockfd);
							event.data.fd = -1;
						} else{
							printf("socket %d write error\n", sockfd);
							write_size = filesize;
							break;
						}
					}
					printf("write %d bytes to socket %d\n", n, sockfd);
				} else {
					write_size = filesize;
				}
				event.data.fd = sockfd;
				event.events = EPOLLIN | EPOLLET;
				epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&event);
			}
			if(write_size >= filesize){
				printf("write whole file, change events\n");
				event.data.fd = sockfd;
				event.events = EPOLLIN | EPOLLET;
				epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&event);
			}
		}
		if(write_size >= filesize){
			printf("write whole file, exit\n");
			break;
		}
	}
	printf("total write size is %d\n", write_size);
	close(epfd);
	fclose(pf);
	close(fd);

	return 0;
}

