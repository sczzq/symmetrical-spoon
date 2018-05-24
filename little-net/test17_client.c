#include "globals.h"
#include <errno.h>

int exit_os = 0;

int do_client(int sockfd, struct sockaddr *sad, socklen_t sad_len)
{
    int n;
    int buf_leng = 1024;
    char buf[1024] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'};
    char base = 'a';
    int i = 0;
    struct sockaddr_in *lsad = (struct sockaddr_in *)sad;
    char buf_addr[32]={0};
    int length = 16;
    int ret;
    for(i=0;i<1024;i++){
        buf[i] = base + (i%26);
    }

    if(connect(sockfd, (struct sockaddr *)sad, sad_len)!=0){
        close(sockfd);
        return (1);
    }
    else{
        struct sockaddr_in cad;
        socklen_t cad_len = sizeof(cad);
        char adstr[32]={0};
        int ad_len = 12;
        memset(&cad,0, sizeof(cad));
        getsockname(sockfd, (struct sockaddr *)&cad, &cad_len);
        printf("local bind info after connect, %s:%d\n",inet_ntop(cad.sin_family,&cad.sin_addr,adstr,ad_len), ntohs(cad.sin_port));
    }
    printf("server addr: %s:%d\n",inet_ntop(lsad->sin_family,&lsad->sin_addr,buf_addr,length), ntohs(lsad->sin_port));
    while(!exit_os){
        buf[0] = base + (i%26);
        ret = send(sockfd, buf, strlen(buf), 0);
        if(ret != strlen(buf)){
            printf("Error %s, send again\n", strerror(errno));
            close(sockfd);
            return 1;
        }
        else{
            printf("send length: %d, expected length: %lu\n", ret, strlen(buf));
            i++;
            sleep(3);
        }
    }
}

int main(int argc, char *argv[])
{
    struct sockaddr_in sad;
    char *sad_ip = "127.0.0.1";
    uint16_t sad_port = htons(2233);
    int sockfd;
    memset(&sad, 0, sizeof(sad));
    sad.sin_family = AF_INET;
    sad.sin_port = sad_port;
    if(inet_pton(sad.sin_family, sad_ip, &sad.sin_addr)<=0){
         printf("something wrong\n");
         return -1;
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in cad;
    socklen_t cad_len = sizeof(cad);
    char adstr[32]={0};
    int ad_len = 12;
    memset(&cad,0, sizeof(cad));
    getsockname(sockfd, (struct sockaddr *)&cad, &cad_len);
    printf("local addrinfo after socket, %s:%d\n",inet_ntop(cad.sin_family,&cad.sin_addr,adstr,ad_len), cad.sin_port);

    do_client(sockfd, (struct sockaddr *)&sad, sizeof(sad));

     return 0;
}
