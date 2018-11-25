/*************************************************************************
    > File Name: connection.cpp
    > Author: zhuziqiang
    > Mail: ziqiang_free@163.com 
    > Created Time: 2018年11月18日 星期日 21时09分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

class SocketHelper {
	static int netSetReuseAddr(int fd);
	static int netListen(int fd, );
};

/*
 * Network connection, based tcp protocol.
 *
 */

class Connection {
public:
	Connection(const string &source_addr, const string &dst_addr, const string &port)
		: saddr_(source_addr),
		  daddr_(dst_addr),
		  port_(port)
	{
		int s = -1, rv;

		struct addrinfo hints, *bservinfo, *p, *b;
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;

		if ( (rv = getaddrinfo(daddr_.c_str(), port.c_str(), &hints, &servinfo)) != 0) {
			throw ;
		}
		for (p = servinfo; p != NULL; p = p->ai_next) {
			if ((fd_ = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
				continue;
			if (setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &rv, sizeof(rv)) == -1)
				throw;

			if (saddr_.length() > 0) {
				int bound = 0;
				// bservinfo is local variable,
				// here is free it before throw exception.
				if ((rv = getaddrinfo(saddr_.c_str(), NULL, &hints, &bservinfo)) != 0)
					throw;
				for (b = bservinfo; b != NULL; b = b->ai_next) {
					if (bind(fd_, b->ai_addr, b->ai_addrlen) != -1) {
						bound = 1;
						break;
					}
				}
				freeaddrinfo(bservinfo);
				if (!bound)
					throw ;
			}
			if (connect(fd_, p->ai_addr, p->ai_addrlen) == -1) {
				throw;
			}
			break;
		}
		if (p == NULL)
			throw ;
		if (servinfo) {
			freeaddrinfo(servinfo);
			servinfo = NULL;
		}
	}

	Connection(string ipport) {

	}

	~Connection(){
		if (fd_ > 0) {
			close(fd_);
			fd_ = -1;
		}
		if (servinfo) {
			freeaddrinfo(servinfo);
			servinfo = NULL;
		}
	}

private:
	int fd_ = -1;
	string saddr_;
	string daddr_;
	string port_;

	struct addrinfo *servinfo = NULL;
};
