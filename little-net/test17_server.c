#include "globals.h"
#include "oscam-time.h"

int exit_os=0;

int32_t start_listener( const char *ip, uint16_t port, int is_udp )
{
    int fd, err;
    int reuse = 1;
    int timeout = BIND_TIMEOUT;

    struct sockaddr_in sad;
    uint32_t sad_len;

	char ptxt[2][32];

    printf("start listen: ------->>>>>>\n");

    ptxt[0][0] = ptxt[1][0] = '\0';

    if(!port){
        printf("port %d disabled\n", port);
        return 0;
    }
    memset(&sad, 0, sizeof(sad));

    sad.sin_family = AF_INET;
    sad_len = sizeof(struct sockaddr);
    if(!ip){
         return 0;
    }
    if(inet_pton(sad.sin_family, ip, &sad.sin_addr.s_addr)!=1){
        printf("Error, inet_pton\n");
        return 0;
    }
    sad.sin_port = htons((uint16_t)port);

    int s_domain = AF_INET;
    int s_type = SOCK_STREAM;
    int s_proto = IPPROTO_TCP;


	if ((fd = socket(s_domain, s_type, s_proto)) < 0) {
		printf("Cannot create socket (errno=%d: %s)\n", errno, strerror(errno));
		return 0;
	}

	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *)&reuse, sizeof(reuse)) < 0) {
		printf("%s; setsockopt failed (errno=%d: %s)\n", __func__, errno, strerror(errno));
		close(fd);
		return 0;
	}
    if(!is_udp){
        int32_t keep_alive = 1;
        setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, (void *)&keep_alive, sizeof(keep_alive));
    }

	while (timeout-- && !exit_os) {
		if (bind(fd, (struct sockaddr *)&sad, sad_len) < 0) {
			if (timeout) {
				printf("%s: Bind request failed (%s), waiting another %d seconds\n",__func__, strerror(errno), timeout);
				sleep(1);
			} else {
				printf("%s: Bind request failed (%s), giving up\n", __func__, strerror(errno));
				close(fd);
				return 0;
			}
		} else {
			timeout = 0;
		}
	}

    if(!is_udp){
        if (listen(fd, QLEN) < 0) {
            printf("%s: Cannot start listen mode (errno=%d: %s)\n", __func__, errno, strerror(errno));
            close(fd);
            return 0;
        }
    }

	printf("%s: initialized (fd=%d, port=%d%s%s)\n",
		__func__, fd,
		port,
		ptxt[0], ptxt[1]);

	return fd;
}


static void process_work(int fd)
{
	int32_t i, k, j, rc, pfdcount = 0;
	struct s_reader *rdr;
	struct pollfd *pfd;
	struct timeb start, end;  // start time poll, end time poll
	uint32_t cl_size = 0;

	uchar buf[10];

	pfd[pfdcount].fd = fd;
	pfd[pfdcount].events = POLLIN | POLLPRI;

	while (!exit_os) {
		pfdcount = 1;

		if (pfdcount >= 1024)
			printf("WARNING: too many users!\n");
		cs_ftime(&start); // register start time
		rc = poll(pfd, pfdcount, 5000);
		if (rc<1){
            printf("nothing concur, just listen another 5 seconds\n");
            continue;
        }
		cs_ftime(&end); // register end time

		for (i=0; i<pfdcount&&rc>0; i++) {
			if (pfd[i].revents == 0) continue; // skip sockets with no changes
			rc--; //event handled!
			printf("[OSCAM] new event %d occurred on fd %d after %ld ms inactivity\n", pfd[i].revents,
			pfd[i].fd,1000*(end.time-start.time)+end.millitm-start.millitm);
			//clients

			//clients
			// message on an open tcp connection
			if (pfd) {
				if (pfd[i].fd == fd && (pfd[i].revents & (POLLHUP | POLLNVAL | POLLERR))) {
					//client disconnects
					continue;
				}
				if (pfd[i].fd == fd && (pfd[i].revents & (POLLIN | POLLPRI))) {
                    printf("add_job, ACTION_CLIENT_TCP\n");
//					add_job(cl, ACTION_CLIENT_TCP, NULL, 0);
				}
			}

            if (pfd && pfd[i].fd == fd && (pfd[i].revents & (POLLHUP | POLLNVAL | POLLERR))) {
                //connection to remote proxy was closed
                //oscam should check for rdr->tcp_connected and reconnect on next ecm request sent to the proxy
//                network_tcp_connection_close(rdr, "closed");
                printf("connection closed\n");
            }
            if (pfd && pfd[i].fd == fd && (pfd[i].revents & (POLLIN | POLLPRI))) {
                printf("add_job, ACTION_READER_REMOTE\n");
//                add_job(cl2, ACTION_READER_REMOTE, NULL, 0);
            }

		}
		cs_ftime(&start); // register start time for new poll next run
	}
	free(pfd);
	return;
}

int main(int argc, const char *agrv[])
{
    char *ip = "127.0.0.1";
    uint16_t c_port = 3233;
    uint16_t s_port = 2233;
    int is_udp = 0;
    int fd;
    struct sockaddr_in sad;
    uint32_t sad_len;

    memset(&sad, 0, sizeof(sad));
    sad.sin_family = AF_INET;
    sad_len = sizeof(struct sockaddr);
    if(inet_pton(sad.sin_family, ip, &sad.sin_addr.s_addr)!=1){
        printf("Error, inet_pton\n");
        return 0;
    }
    sad.sin_port = htons((uint16_t)s_port);

    fd = start_listener(ip, s_port, is_udp);
    if(fd){
        char buf[10]={0};
        char base = 'a';
        int i = 0;
        int status;
        int numsec;
        int newfd = 0;
        for(numsec=1; numsec <= MAXSLEEP; ++numsec){
            printf("waiting for connetting.........\n");
            newfd = accept(fd, (struct sockaddr *)&sad, &sad_len);
            printf("comming new connectted>>>>>>>>>>>>>\n");
            if(newfd>0){
                printf("new client query: %d\n",newfd);
                while(!exit_os){
                    status = recv(newfd, buf, sizeof(buf)-1,0);
                    if(status==-1){
                        printf("Error, receive\n");
                        continue;
                    }
                    else{
                         if(buf[0]) printf("receive %s\n", buf);
                         buf[0] = '\0';
                    }
                    i++;
//                    sleep(1);
                }

            }
            else{
                if(numsec<=MAXSLEEP){
                    printf("Error, connecting waiting %d seconds\n", numsec);
                    sleep(numsec);
                }
            }
        }
    }
    else{
         printf("Error, init %s:%d\n", ip, c_port);
    }
    return 0;
}
