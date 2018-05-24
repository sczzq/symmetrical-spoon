/*************************************************************************
	> File Name: test_client3.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 09:42:54 PM CST
 ************************************************************************/

#include <iostream>
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

#include "message.hpp"
#include "custom.hpp"

using namespace std;
using namespace Anomynous;

#define MYPORT  7008
#define BUFFER_SIZE 1024

int exited = 0;
void receive(int sock_fd)
{
	Message* msg = new Message();
	int len;
	while(exited == 0){
		len = recv(sock_fd, (void *)msg, sizeof(msg),0); ///接收
        if(len == 0)
            break;
	}
	exited = 1;
	delete msg;
}

void help()
{
	cout << "Format need here: " << endl;
	cout << "	type:message" << endl;
	cout << "	1 targetname msg    using anomynous to send to another" << endl;
	cout << "	2 yourname		register the name on server" << endl;
	cout << "	3 aothername		query another name is on or not" << endl;
	cout << "	4 groupname			query group is existing or not" << endl;
	cout << "	5 yourname			using yourname to connect to server" << endl;
	cout << "	6					disconnect to server" << endl;
	cout << "	7 targetname msg	send the message to targetname" << endl;
	cout << "	8 groupname			join in group by groupname" << endl;
	cout << "	9 groupname			leave group by groupname" << endl;
	cout << "First step to input the type: 2, 3, 4, 6, 7, 8, 9" << endl;
	cout << "Second step to enter its characters, and you need enter more time in type 7" << endl;
	cout << "	Tips: you need input a number and some character by its means." << endl;
} 

void my_send(int sock_fd)
{
	string stype;
	char name[1000];
	char message[1000];
	char buffer[1024];
	help();
    while (exited==0 && cin >> stype )
    {
		string s;
		int type;
		cout << stype << endl;
		type = std::stoi(stype);
		if(type == 1 || type == 7){
			cin >> name;
			cin >> message;
			if( strlen(message) == 0 ){
				cout << "the input of message is null, again..." << endl;
				continue;
			}
			sprintf(buffer, "%d:%s:%s", type, name, message);
		} else if(type == 6){
			sprintf(buffer, "%d:", type);
		} else if(type == 2 || type == 3 || type == 4 || type == 5 || type == 8 || type == 9){
			cin >> name;
			sprintf(buffer, "%d:%s", type, name);
		} else {
			cout << "type unrecognize, again..." << endl;
			continue;
		}

        int len = send(sock_fd, buffer, strlen(buffer),0); ///发送
		if(len == 0){
			cout << "send error" << endl;
			break;
		}
		if( type == 6 ){
			cout << "exit..." << endl;
			break;
		}
		if( strlen(buffer)==strlen("6:") && strncmp(buffer, "6:", strlen("6:"))){
			cout << "exit..." << endl;
			break;
		}
//		help();
    }
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

//	std::thread t_recv(receive, sock_cli);
	std::thread t_send(my_send, sock_cli);

	t_send.join();
//	t_recv.join();

    close(sock_cli);
    return 0;
}
