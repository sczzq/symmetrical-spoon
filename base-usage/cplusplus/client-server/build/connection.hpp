#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include "random.hpp"

namespace Anomynous{

class Connection {
	uint64_t id {123456789 }; // custom id.
	uint32_t ip {0};
	uint32_t port {0};
	uint64_t time {0};
	int sockfd;
public:
	Connection() { 
		id = Anomynous::RandomUint64_t();
	}
	/*
	 * parameter: id, ip, port, time, sockfd
	 */
	Connection(uint64_t d, uint32_t p, uint32_t pt, uint64_t t, int sock) { id = d; ip = p; port = pt; time = t; sockfd = sock; }
	/*
	 * parameter: ip, port, time, sockfd
	 */
	Connection(uint32_t p, uint32_t pt, uint64_t t, int sock) {	
		id = Anomynous::RandomUint64_t();
		ip = p;	port = pt; time = t; sockfd = sock;	
	}
	/*
	 * parameter: id, ip, port, sockfd.
	 */
	Connection(uint64_t d, uint32_t p, uint32_t pt, int sock) {	
		id = d;
		ip = p;	port = pt; sockfd = sock;	
	}
	/*
	 * parameter: ip, port, sockfd
	 */
	Connection(uint32_t p, uint32_t pt, int sock) {	
		id = Anomynous::RandomUint64_t();
		ip = p;	port = pt; sockfd = sock;	
	}
	/*
	 * parameter: time, sockfd.
	 */
	Connection(uint32_t t, int sock) {
		id = Anomynous::RandomUint64_t();
		time = t; sockfd = sock;
	}

	int setID(uint64_t d) { id = d;	}
	int setIpPort(uint32_t p, uint32_t pt) { ip = p; port = pt;	}
	int setInfo(uint64_t d, uint32_t p, uint32_t pt){ id = d; ip = p; port= pt; }
	int setSock(int sock) { sockfd = sock; }

	uint64_t getID() { return id; }
	uint64_t getIP() { return ip; }
	uint32_t getPort() { return port; }
	uint64_t getTime() { return time; }
	int getSockfd() { return sockfd; }
};

}
#endif

