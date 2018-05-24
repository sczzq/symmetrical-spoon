#include "globals.h"
#include <netdb.h>

#define PORT 2233
#define MAXDATASIZE  2100

int main(int argc, char *argv[])
{
    int sockfd, num;
    char buf[MAXDATASIZE ]={'a','b','c','d','e','f'};
    struct hostent *he;
    struct sockaddr_in server;
    char *ip_str = "127.0.0.1";
    int numsec = 0;
    if((he=gethostbyname(ip_str))==NULL)
    {
        printf("gethostname error\n");
        return 0;
    }
    if((sockfd=socket(AF_INET,SOCK_STREAM, IPPROTO_TCP))==-1){
        printf("socket error\n");
        return 0;
    }

    int i = 0;
    for(i=0; i<MAXDATASIZE; i++){
        buf[i] = 'a' + (i%26);
    }
    bzero(&server,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *((struct in_addr *)he->h_addr);
    printf("errno: %d, %s, %d\n", errno, strerror(errno), __LINE__);
    for(numsec=0; numsec<MAXSLEEP; numsec++){
        printf("errno: %d, %s, %d\n", errno, strerror(errno), __LINE__);
        if(connect(sockfd,(struct sockaddr *)&server, sizeof(server))==0){
            printf("errno: %d, %s, %d\n", errno, strerror(errno), __LINE__);
            break;
        }
        sleep(numsec);
    }
    num=write(sockfd, buf, strlen(buf));
    if(num==-1){
        printf("send error\n\n");
        close(sockfd);
        return 0;
    }
    printf("send %s\n", buf);
    close(sockfd);
    return 0;
}

