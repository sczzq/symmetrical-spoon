/*************************************************************************
	> File Name: test_server3.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 09:42:35 PM CST
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
#include <iostream>

#define PORT 7008
#define QUEUE 20

void receive(int sock_fd)
{
	char buffer[1024];
	int len;
	while(1){
		memset(buffer, 0 ,sizeof(buffer));
		len = recv(sock_fd, buffer, sizeof(buffer), 0);
		printf("%d: %s", sock_fd, buffer);
		if(strlen(buffer)==0 || strncmp(buffer, "exit", strlen("exit")) == 0){
			send(sock_fd, "exit\n", strlen("exit\n") , 0);
			break;
		}
	}
}

void my_send(int sock_fd)
{
	char buffer[1024];
	while(fgets(buffer, sizeof(buffer),stdin)){
		send(sock_fd, buffer, strlen(buffer) , 0);
		if(strncmp(buffer, "exit", strlen("exit")) == 0) break;
		memset(buffer, 0 ,sizeof(buffer));
	}
}

void get_connect(int sock_fd)
{
	char buffer[1024];
	sprintf(buffer, "hello %d\n", sock_fd);
	send(sock_fd, buffer, strlen(buffer) , 0);
	std::thread t_recv(receive, sock_fd);
	std::thread t_send(my_send, sock_fd);

	t_send.join();
	t_recv.join();

	while(1){
		sleep(10);
	}

	close(sock_fd);
}

int main() {
	int conn;
    //printf("%d\n",AF_INET);
    //printf("%d\n",SOCK_STREAM);
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    //printf("%d\n",ss);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT);
    printf("%d\n",INADDR_ANY);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        perror("bind");
        exit(1);
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
	while(true){
		///成功返回非负描述字，出错返回-1
		conn = accept(ss, (struct sockaddr*)&client_addr, &length);
		if( conn < 0 ) {
			perror("connect");
			exit(1);
		}
		cout << "connection " << conn << " coming..." << endl;
		std::thread t(get_connect, conn);
		t.detach();
	}

    close(ss);
    return 0;
}
