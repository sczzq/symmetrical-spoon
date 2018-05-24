#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

#include <poll.h>
#include <pthread.h>
#include <sys/time.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <errno.h>

typedef unsigned char uchar;

/* ===========================
 *      global structures
 * =========================== */
struct timeb {
	time_t time;
	uint16_t millitm;
};



#define BIND_TIMEOUT  20 // just 20 seconds
#define QLEN       128 // size of request queue
#define MAXSLEEP   100 // 100 seconds




#endif

