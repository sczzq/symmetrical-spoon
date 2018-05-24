/*************************************************************************
	> File Name: test_client3.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 09:42:54 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <thread>

#define MYPORT  7008
#define BUFFER_SIZE 1024

int exited = 0;
void receive(int sock_fd)
{
    char buffer[BUFFER_SIZE];
	int len;
	while(exited == 0){
		memset(buffer, 0, sizeof(buffer));
		len = recv(sock_fd, buffer, sizeof(buffer),0); ///接收
		printf("server: %s", buffer);
        if(strlen(buffer)==0 || strncmp(buffer,"exit", strlen("exit"))==0)
            break;
	}
//	printf("recv thread is exiting...\n");
	exited = 1;
}

void my_send(int sock_fd)
{
    char buffer[BUFFER_SIZE];
    while (exited==0 && fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        send(sock_fd, buffer, strlen(buffer),0); ///发送
        if(strncmp(buffer,"exit", strlen("exit"))==0){
            break;
		}
        memset(buffer, 0, sizeof(buffer));
//		printf("my: ");
//		fflush(NULL);
    }
//	printf("send thread is exiting....");
	exited = 1;
	return ;
}

int main()
{
    ///定义sockfd
    int sock_cli = socket(AF_INET,SOCK_STREAM, 0);

    ///定义sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(MYPORT);  ///服务器端口
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///服务器ip

    //连接服务器，成功返回0，错误返回-1
    if (connect(sock_cli, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

	std::thread t_recv(receive, sock_cli);
	std::thread t_send(my_send, sock_cli);

	t_send.join();
	t_recv.join();

	printf("exiting....\n");

    close(sock_cli);
    return 0;
}
