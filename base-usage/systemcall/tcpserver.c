/*************************************************************************
    > File Name: tcpserver.c
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年11月18日 星期日 22时26分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

#include "anet.h"

int sfd = -1, cfd = -1;
int afd = -1;

char **buffer = NULL;
int buffer_size = 10;
int buff_used = 0;

int buff_size = 24;

int trv_size = 1024*1024;

int server(char *addr, int port)
{
	char err[1024] = {0};
	int bg = 1000;

	int fd = anetTcpServer(err, port, addr, bg);
	if (fd < 0) {
		printf("%d,%d,%s\n", fd, bg, err);
		return -1;
	}
	return fd;
}

void * server_accept(void * arg)
{
	while(buff_used < buffer_size) {
		char err[1024];
		char ip[256];
		int port;
		afd = anetTcpAccept(err, sfd, ip, 256, &port);
		printf("accept from %s:%d\n", ip, port);
	}
	printf("server_accept exit.\n");
}

void * server_read(void * arg)
{
	int nc = 1;
	while(buff_used < buffer_size) {
		char *buf = (char *)malloc(buff_size);
		if (buf == NULL) {
			break;
		}
		memset(buf, 0, sizeof(buff_size));
		anetRead(afd, buf, buff_size);
		buffer[buff_used++] = buf;
		printf("server read one, buff_used:%d\n", buff_used);

		sleep(1);
	}
	buff_used++;
	printf("server_read exit.\n");
}

void * server_write(void * arg)
{
	while(buff_used <= buffer_size) {
		int size = buff_size;
		char *buf = (char *)malloc(size);
		for(int i = 0; i < size; i++){
			char a = 's' + i % 10;
			buf[i] = a;
		}
		buf[size - 1] = 0;
		anetWrite(afd, buf, size);
		free(buf);
		sleep(1);
	}
	printf("server_write exit.\n");
}

int client_connect(char *addr, int port)
{
	char err[1024];
	return anetTcpConnect(err, addr, port);
}

void * client_read(void * arg)
{
	int nc = 1;
	while(buff_used < buffer_size) {
		char *buf = (char *)malloc(buff_size);
		if (buf == NULL) {
			break;
		}
		memset(buf, 0, sizeof(buff_size));
		anetRead(cfd, buf, buff_size);
		buffer[buff_used++] = buf;
		printf("client read one, buff_used:%d\n", buff_used);

		sleep(1);
	}
	buff_used++;
	printf("client_read exit.\n");
}

void * client_write(void * arg)
{
	while(buff_used <= buffer_size) {
		int size = buff_size;
		char * buf = (char *)malloc(size);
		for(int i = 0; i < size; i++){
			char a = 'c' + i % 10;
			buf[i] = a;
		}
		buf[size - 1] = 0;
		anetWrite(cfd, buf, size);
		free(buf);

		sleep(1);
	}
	printf("client_write exit.\n");
}

int main()
{
	buffer = (char **)malloc((buffer_size + 1) * sizeof(char *));
	if (buffer == NULL) {
		printf("buffer malloc error\n");
		return -1;
	}

	pthread_t s_r_pid, s_w_pid, c_r_pid, c_w_pid, a_pid;

	char *saddr = "192.168.199.227";
	int sport = 20180;
	sfd = server(saddr, sport);

	if (sfd < 0) {
		printf("server error\n");
		return -1;
	}
	pthread_create(&a_pid, NULL, server_accept, NULL);

	cfd = client_connect(saddr, sport);
	char err[1024];
	anetTcpKeepAlive(err, cfd);

	if (cfd < 0) {
		printf("client error\n");
		return -1;
	}

	printf("waiting connection...\n");
	sleep(1);

	pthread_create(&s_r_pid, NULL, server_read, NULL);
	pthread_create(&c_r_pid, NULL, client_read, NULL);

	sleep(1);

	pthread_create(&s_w_pid, NULL, server_write, NULL);
	pthread_create(&c_w_pid, NULL, client_write, NULL);

	pthread_join(c_r_pid, NULL);
	pthread_join(c_w_pid, NULL);

	pthread_join(s_r_pid, NULL);
	pthread_join(s_w_pid, NULL);

	pthread_cancel(a_pid);

	pthread_join(a_pid, NULL);

	if (buff_used > 0) {
		for (int i = 0; i < buff_used && i < buffer_size; i++) {
			printf("%d:%s\n", i, buffer[i]);
			free(buffer[i]);
		}
	}

	if (afd > 0)
		close(afd);
	if (sfd > 0)
		close(sfd);
	if (cfd > 0)
		close(cfd);
}

