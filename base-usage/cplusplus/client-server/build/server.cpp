/*************************************************************************
	> File Name: test_server3.cpp
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 08 May 2017 09:42:35 PM CST
 ************************************************************************/

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
#include <string>
#include <vector>

#include "info.hpp"
#include "parser.hpp"

using namespace std;
using namespace Anomynous;

#define PORT 7008
#define QUEUE 20

int connection_number = 0;


/*
void receive(int sock_fd)
{
	while(1){
		memset(buffer, 0 ,sizeof(buffer));
		len = recv(sock_fd, buffer, sizeof(buffer), 0);
		if( len == 0 ){
			sleep(2);
			continue;
		}
		if( len == strlen("exit") && strncmp(buffer, "exit", strlen("exit"))){
			break;
		}
		msg->deal();
//		cout << "hello \n";
//		cout << msg->toString() << endl;
	}
}*/



/*
 * parameters
 *		CustomerMap& custmap is all of the customer in the process,
 *		ConnectionMap& connmap is all of the connectoin in the process.
 */
void get_connect(Info info)
{
	Connection conn = info.getConnection();
	Customer cust {conn};
	ConnectionMap* connmap = info.getConnectionMap();
	CustomerMap* custmap = info.getCustomerMap();
	char buffer[1024];
	int sockfd = conn.getSockfd(); 
	sprintf(buffer, "hello\n");
	send(sockfd, buffer, strlen(buffer) , 0);

	custmap->add(cust);

	while(1){
		Message msg { cust.getID() };
		memset(buffer, 0 ,sizeof(buffer));
		int len = recv(sockfd, buffer, sizeof(buffer), 0);
		if( len == 0 ){
			sleep(2);
			continue;
		}
		if( len == strlen("exit") && strncmp(buffer, "exit", strlen("exit"))){
			break;
		}
		string s {buffer};
		cout << s << endl;
		parseToMsg(msg, s);
		msg.dealDebug();
		cout << msg.toString() << endl;
		if(msg.getType() == MessageType::Disconnect){
			cout << "sockfd=" << sockfd << " disconnected" << endl;
			break;
		}
	}

	connmap->del(conn.getID());
	connmap->show();

//	std::thread t_recv(receive, sock_fd);
//	t_recv.join();
}

int main() {
	int connfd;
	CustomerMap custmap;
	ConnectionMap connmap;
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(PORT);
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
	Info info{&custmap, &connmap};

	while(true){
		cout << "connectoin: " << connmap.size() << endl;
		///成功返回非负描述字，出错返回-1
		connfd = accept(ss, (struct sockaddr*)&client_addr, &length);
		if( connfd < 0 ) {
			perror("connect");
			exit(1);
		}
		Connection conn{client_addr.sin_addr.s_addr, client_addr.sin_port, connfd};
		connmap.add(conn.getID(), conn);
		cout << "connection " << to_string(connfd) << " coming..." << ", its id=" << to_string(conn.getID())<< endl;
		info.setConnection(conn);
		std::thread t(get_connect, info);
		t.detach();
	}

    close(ss);
    return 0;
}

