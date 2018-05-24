/*************************************************************************
	> File Name: socket.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 24 May 2017 04:21:06 PM CST
 ************************************************************************/

#include "socket.h"

/*
 * AF_UNIX, AF_LOCAL
 * AF_INET
 * AF_INEXT6
 * AF_IPX
 * AF_NETLINK
 * AF_X25
 * AF_AX25
 * AF_ATMPVC
 * AF_APPLETALK
 * AP_PACKET
 *
 * SOCK_STREAM
 * SOCK_DGRAM
 * SOCK_SEQPACKET
 * SOCK_RAW
 * SOCK_RDM
 * SOCK_PACKET
 *
 * SOCK_NONBLOCK
 * SOCK_CLOEXEC
 *
 */

int getsocket(int domain, int type)
{
	int protocol = 0;
	return socket(domain, type, protocol);
}

