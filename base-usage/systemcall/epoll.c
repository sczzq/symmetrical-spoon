/*************************************************************************
	> File Name: epoll.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 31 May 2017 02:32:45 PM CST
 ************************************************************************/


/*
#define MAX_EVENTS 10
struct epoll_event ev, events[MAX_EVENTS];
int listen_sock, conn_sock, nfds, epollfd;

/// Code to set up listening socket, 'listen_sock',
//   (socket(), bind(), listen()) omitted

epollfd = epoll_create1(0);
if (epollfd == -1) {
	perror("epoll_create1");
	exit(EXIT_FAILURE);
}

ev.events = EPOLLIN;
ev.data.fd = listen_sock;
if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
	perror("epoll_ctl: listen_sock");
	exit(EXIT_FAILURE);
}

for (;;) {
	nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
	if (nfds == -1) {
		perror("epoll_wait");
		exit(EXIT_FAILURE);
	}

	for (n = 0; n < nfds; ++n) {
		if (events[n].data.fd == listen_sock) {
			conn_sock = accept(listen_sock,
					(struct sockaddr *) &addr, &addrlen);
			if (conn_sock == -1) {
				perror("accept");
				exit(EXIT_FAILURE);
			}
			setnonblocking(conn_sock);
			ev.events = EPOLLIN | EPOLLET;
			ev.data.fd = conn_sock;
			if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock,
						&ev) == -1) {
				perror("epoll_ctl: conn_sock");
				exit(EXIT_FAILURE);
			}
		} else {
			do_use_fd(events[n].data.fd);
		}
	}
}

*/
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

#define MAXLINE (1024*16)
#define LISTENQ 20

void setnonblocking(int sock)
{
    int opts;
    opts = fcntl(sock,F_GETFL);
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

int main(int argc, char* argv[])
{
    int i, maxi, listenfd, connfd, sockfd,epfd,nfds, portnumber;
    ssize_t n;
    char readline[MAXLINE], writeline[MAXLINE];
    socklen_t clilen;

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

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in clientaddr;
    struct sockaddr_in serveraddr;
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    char *local_addr = "127.0.0.1";
    inet_aton(local_addr, &(serveraddr.sin_addr));
    serveraddr.sin_port = htons(portnumber);
    bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    listen(listenfd, LISTENQ);
    maxi = 0;

    struct epoll_event ev,events[20];
    epfd = epoll_create(256);

    setnonblocking(listenfd);
    ev.data.fd = listenfd;
    ev.events = EPOLLIN | EPOLLET;
    //ev.events=EPOLLIN;

    epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev);

	int readsize = 0;

    for ( ; ; ) {
        //等待epoll事件的发生
        nfds = epoll_wait(epfd, events, 20, 500);

        //处理所发生的所有事件
        for(i = 0; i < nfds; ++i)
        {
            if(events[i].data.fd == listenfd)//如果新监测到一个SOCKET用户连接到了绑定的SOCKET端口，建立新的连接。
            {
                connfd = accept(listenfd,(struct sockaddr *)&clientaddr, &clilen);
                if(connfd<0){
                    perror("connfd<0");
                    exit(EXIT_FAILURE);
                }
                setnonblocking(connfd);
                char *str = inet_ntoa(clientaddr.sin_addr);
				printf("accapt a connection from %s, socket %d\n", str, connfd);
                ev.data.fd = connfd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev);
            }
            else if(events[i].events&EPOLLIN)//如果是已经连接的用户，并且收到数据，那么进行读入。
            {
				printf("EPOLLIN\t");
                if ( (sockfd = events[i].data.fd) < 0)
                    continue;
                if ( (n = read(sockfd, readline, MAXLINE)) < 0) {
                    if (errno == ECONNRESET) {
                        close(sockfd);
                        events[i].data.fd = -1;
                    } else
						printf("socket %d readline error\n", sockfd);
                } else if (n == 0) {
                    close(sockfd);
                    events[i].data.fd = -1;
                }
				readsize = n;
				printf("read %d bytes from socket %d\n", n, sockfd);
                ev.data.fd=sockfd;
                ev.events = EPOLLOUT;
                epoll_ctl(epfd,EPOLL_CTL_MOD,sockfd,&ev);
            }
            else if(events[i].events&EPOLLOUT) // 如果有数据发送
            {
                if ( (sockfd = events[i].data.fd) < 0 )
                    continue;
                n = write(sockfd, writeline, MAXLINE);
				printf("write %d bytes to socket %d\n", n, sockfd);
                ev.data.fd=sockfd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(epfd, EPOLL_CTL_MOD, sockfd, &ev);
            }
        }
    }
    return 0;
}

