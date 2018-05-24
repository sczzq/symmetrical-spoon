/*************************************************************************
	> File Name: test_client.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 08:07:18 PM CST
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

class Client{
public:
	Client()
		: sock_fd(-1), domain(AF_INET), type(SOCK_STREAM), protocol(0)
	{ buffer_size = 1024; }
	Client(int d, int t, int p)
		: sock_fd(-1), domain(d), type(t), protocol(p)
	{ buffer_size = 1024; }
	// first set socket parameter.
	void set_parameter(int domain, int type, int protocol, int family);
	// second set server paramter.
	void set_server_parameter(string addr, int port);
	// third init resource
	void init_resource(); 
	// fourth init input resource.
	void init_input_resource();
	// fifth to connect to server.
	void to_connect();
	// check is connected.
	bool is_connected();
	// re-connect.
	void reconnect();

	// listen its connection to check whether has message.
	bool listen();

	~Client() {
		// close socket decriptor.
		close(sock_fd);
	}
private:
	int sock_fd;
	int domain;
	/* socket, to see man socket */
	int type;
	int protocol;
	int family;

	string ipaddr;
	int port;

	struct sockaddr_in servaddr;

	int is_connect;

    fd_set rfds; /* file descriptor 0 */

	int buffer_size;

	int maxfd;
};

void Client::set_parameter(int dm = AF_INET, int ty=SOCK_RAW, int pro=0, int fa=AF_INET)
{
	domain = dm; type = ty; protocol = pro; family = fa;
}

void Client::set_server_parameter(string addr="127.0.0.1", int por=7000)
{
	ipaddr = addr;
	port = por;
}

void Client::init_resource()
{
	sock_fd = socket(domain, type, protocol);

    servaddr.sin_family = family;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ipaddr.c_str());
}

void Client::to_connect()
{
    int ret = connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	if(ret < 0){
		is_connect = false;
		cout << "connect to " << ipaddr << ":" << port << " error\n";
	}
}

void Client::reconnect()
{
	if(is_connect == false){
		to_connect();
	}
}

bool Client::is_connected()
{
	return is_connect;
}

void Client::init_input_resource()
{
	/*把可读文件描述符的集合清空*/
	FD_ZERO(&rfds);
	/*把标准输入的文件描述符加入到集合中*/
	FD_SET(0, &rfds);
	maxfd = 0;
	/*把当前连接的文件描述符加入到集合中*/
	FD_SET(sock_fd, &rfds);
	/*找出文件描述符集合中最大的文件描述符*/    
	if(maxfd < sock_fd)
		maxfd = sock_fd;
}

bool Client::listen()
{ 
	cout << "int listern\n";
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;
	/*等待聊天*/
	int retval;
	retval = select(maxfd, &rfds, NULL, NULL, &tv);
	if(retval == -1){
		printf("select出错，客户端程序退出\n");
		return false;
	}else if(retval == 0){
		printf("客户端没有任何输入信息，并且服务器也没有信息到来，waiting...\n");
		return true;
	}else{
		cout << "has message\n";
		/*服务器发来了消息*/
		if(FD_ISSET(sock_fd,&rfds)){
			char recvbuf[buffer_size];
			int len;
			len = recv(sock_fd, recvbuf, sizeof(recvbuf),0);
			printf("%s", recvbuf);
			memset(recvbuf, 0, sizeof(recvbuf));
		}
		/*用户输入信息了,开始处理信息并发送*/
		if(FD_ISSET(0, &rfds)){
			char sendbuf[buffer_size];
			fgets(sendbuf, sizeof(sendbuf), stdin);
			send(sock_fd, sendbuf, strlen(sendbuf),0); //发送
			memset(sendbuf, 0, sizeof(sendbuf));
		}
	}
	return true;
}

int main()
{
	Client client;
	string server_addr = "127.0.0.1";
	int server_port = 7000;
	// first
	client.set_parameter();
	// second
	client.set_server_parameter();
	// third
	client::init_resource();
	cout << "after set server parameter\n";
    while(!client.is_connected()){
		// fourth
		client.to_connect();
		cout << "connect error, reconnect\n";
    }
	cout << "after connect\n";
	while(client.is_connected()){
		// fifth
		if(!client.listen())
			break;
	}

    return 0;
}

