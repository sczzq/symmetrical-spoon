#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef unsigned long long prime_t;

int prime_gen(prime_t *primes, int max, int number);
int prime_check(prime_t *primes, int number, prime_t prime);
int prime_storing(prime_t *primes, int number);
int prime_restore(prime_t **primes, int max);

char *PRIME="prime.number";
int debug = 0;

int main(int argc, char *argv[]){
    prime_t *primes = NULL;
    prime_t prime;
    int number = 0, max = 1000*1000;
    max = 500;
    if(argc == 2){
        max = strtod(argv[1], NULL);
    }
    if(argc == 3){
        max = strtod(argv[1], NULL);
         debug = strtod(argv[2], NULL);
    }

    struct timespec tv, ntv;
    clock_gettime(CLOCK_REALTIME, &tv);
    printf("\nstart time %lu, nano time %lu\n", tv.tv_sec, tv.tv_nsec);

    printf("\nnow need generate %d new prime\n", max);

    number = prime_restore(&primes, max);

    clock_gettime(CLOCK_REALTIME, &ntv);
    printf("\nloading stored prime using time: %lu second, %lu nanosecond\n", ntv.tv_sec - tv.tv_sec, ntv.tv_nsec - tv.tv_nsec );

    prime_gen(primes, max, number);

    clock_gettime(CLOCK_REALTIME, &tv);
    printf("\ngenerate new prime using time: %lu second, %lu nanosecond\n", tv.tv_sec - ntv.tv_sec, tv.tv_nsec - ntv.tv_nsec );

    prime_storing(primes, max+number);

    clock_gettime(CLOCK_REALTIME, &ntv);
    printf("\nstoring all prime using time: %lu second, %lu nanosecond\n", ntv.tv_sec - tv.tv_sec, ntv.tv_nsec - tv.tv_nsec );

    printf("generate new prime number %d, now total number is %d, store in %s\n\n", max, max+number, PRIME);

RET:
    if(primes)
        free(primes);
    return 0;
}

int prepare(){
    return 0;
}

int prime_storing(prime_t *primes, int number){
    int fd = open(PRIME,  O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    char prime[1024];
    int ret = 0;

    if(fd < 0){
        printf("error on open file %s\n", PRIME);
        goto RET;
    }
    int i=0;
    for(i=0; i<number; i++){
        sprintf(prime, "%llu\n", primes[i]);
        ret = write(fd, prime, strlen(prime));
        if(ret != strlen(prime))
            goto RET;
    }

    printf("store %d prime OK\n", number);

RET:
    if(fd)
        close(fd);
    return 0;
}

int prime_restore(prime_t **p, int max){
    struct stat st;
    char *file_buffer = NULL;
    int fd = 0;
    int i=0, start_pos=0, end_pos=0, pos=0;
    char string[1024];

    // first to malloc memory.
    prime_t *primes = NULL;
    primes = malloc(max*sizeof(prime_t));
    if(primes==NULL){
        perror("malloc");
        goto RET;
    }

    // read data from file.
    if(stat(PRIME, &st)==-1){
        perror("stat");
        printf("no %s, so just create it\n", PRIME);
        goto RET;
    }
    printf("file size: %lu\n", st.st_size);
    file_buffer = (char *)malloc((st.st_size + 2)*sizeof(prime_t));
    if(file_buffer==NULL){
         perror("malloc");
         goto RET;
    }
    fd = open(PRIME, O_RDONLY);
    if(fd < 0){
        perror("open");
        goto RET;
    }
    read(fd, file_buffer, st.st_size);
    close(fd);

    // parse prime from data.
    int j=0, n=0, length=0,nmax=max;
    char *tttt;
    prime_t temp;
    for(j=0; j<st.st_size; j++){
        if(file_buffer[j]=='\n'){
            string[length] = '\0';
            temp = strtoll(string, &tttt, 10);
            if(temp == 0)
                continue;
            primes[n] = temp;
            length = 0;
            n++;
        } else {
            string[length] = file_buffer[j];
            length++;
        }
        if(n==nmax){
            nmax = nmax * 2;
            primes = realloc(primes, nmax*sizeof(prime_t));
            printf("realloc memory size to %lu, %d prime space\n", nmax * sizeof(prime_t), nmax);
        }
    }

    // adjust memory size.
    if((max+n) > nmax){
         primes = realloc(primes, (max+n)*sizeof(prime_t));
         printf("adjust memory size to %d\n", max + n);
    }

    printf("restore %d prime from %s OK\n", n, PRIME);

RET:
    *p = primes;

    if(file_buffer)
        free(file_buffer);
    return n;
}

// number already generate in last step.
// max need this step.
int prime_gen(prime_t *primes, int max, int number){
    prime_t prime;
    int n, i=number, imax=0;

    printf("new: %d, number: %d\n", max, number);

    if(i == 0){
        primes[i] = 2;
        i++;
    }

    while(imax<max){
        for(prime=primes[i-1] + 1; ; prime++){
            if(prime_check(primes, i, prime)){
                imax++;
                primes[i] = prime;
                break;
            }
        }
        i++;
        if(debug && i%1==0)
            printf("%d:%llu, ", i, prime);
    }
    printf("\ngenerate %d prime OK, now total %d prime\n", imax, i);
    return i;
}

int prime_check(prime_t *primes, int number, prime_t prime){
    int i=0;
    int ret = 1;
//    if(debug)
//    printf("%d, %llu\n", number, prime);
    for(i=0; i<number; i++){
        if(debug)
            printf("%d: %d: %llu\n", i, number, prime);
        if(prime%primes[i]==0){
            ret = 0;
            break;
        }
//        if(debug && number%100==0)
//            printf("%d: %d: %llu\n", i, number, prime);
    }
    return ret;
}
