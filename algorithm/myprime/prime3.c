#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
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

    number = prime_restore(&primes, max);

    clock_gettime(CLOCK_REALTIME, &ntv);
//    printf("\nloading stored prime using time: %lu second, %lu nanosecond\n", ntv.tv_sec - tv.tv_sec, ntv.tv_nsec - tv.tv_nsec );

    int splice_size=10000, splice_total=0, total_number = number;
    splice_size = splice_size > max ? max : splice_size;
    while(splice_total < max){

        splice_size = (splice_size+splice_total) > max ? (max-splice_total) : splice_size;

        // now we have total_number prime in primes, and generate more splice_size prime.
        splice_total += prime_gen(primes, splice_size, total_number);

        printf("total number %d, splice_total %d\n", total_number, splice_total);

        clock_gettime(CLOCK_REALTIME, &tv);
        if(tv.tv_nsec < ntv.tv_nsec)
            printf("generate new %d prime using time: %lu second, %lu nanosecond\n", splice_size, tv.tv_sec - ntv.tv_sec - 1, 1000*1000*1000 + tv.tv_nsec - ntv.tv_nsec );
        else
            printf("generate new %d prime using time: %lu second, %lu nanosecond\n", splice_size, tv.tv_sec - ntv.tv_sec, tv.tv_nsec - ntv.tv_nsec );

        total_number = number + splice_total;

        prime_storing(primes, total_number);

        clock_gettime(CLOCK_REALTIME, &ntv);
        if(ntv.tv_nsec < tv.tv_nsec)
            printf("storing all %d prime using time: %lu second, %lu nanosecond\n", total_number, ntv.tv_sec - tv.tv_sec - 1, 1000*1000*1000 + ntv.tv_nsec - tv.tv_nsec );
        else
            printf("storing all %d prime using time: %lu second, %lu nanosecond\n", total_number, ntv.tv_sec - tv.tv_sec, ntv.tv_nsec - tv.tv_nsec );

    }

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
    int fd = 0;
    char prime[1024];
    int ret = 0;

    fd = open(PRIME,  O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
    if(fd < 0){
        printf("error on open file %s\n", PRIME);
        goto RET;
    }

    printf("total number %d\n", number);
    int i=0;
    for(i=0; i<number; i++){
        if(primes[i] > 0){
            sprintf(prime, "%llu\n", primes[i]);
            ret = write(fd, prime, strlen(prime));
            if(ret != strlen(prime))
                goto RET;
        }
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
    int j=0, n=0, length=0,nmax=max;
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
    char *tttt;
    prime_t temp;
    for(j=0; j<st.st_size; j++){
        if(file_buffer[j]=='\n'){
            string[length] = '\0';

            temp = strtoll(string, &tttt, 10);
            if(temp > 0){
                primes[n] = temp;
                length = 0;
                n++;
            }
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
// so, we have number prime in primes, and generate max prime.
int prime_gen(prime_t *primes, int max, int number){
    struct timeval tm[2];
    prime_t prime;
    int n, i=number, imax=0;
    gettimeofday(tm, NULL);
    if(i == 0){
        primes[i] = 2;
        i++;
        imax++;
    }

    printf("new: %d, number: %d\n", max, number);

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
        gettimeofday(tm+1, NULL);
        if(tm[1].tv_sec - tm[0].tv_sec > 60){
            break;
        }
    }
    printf("\ngenerate %d prime OK, now total %d prime\n", imax, i);
    return imax;
}

int prime_check(prime_t *primes, int number, prime_t prime){
    int i=0;
    int ret = 1;
    int temp1 = prime%10;

    if(temp1==5){
        return 0;
    }

//    if(!(temp1==1&&temp1==3&&temp1==7&&temp1==9)){
//        return 0;
//    }

    for(i=0; i<number; i++){
        if(prime%primes[i]==0){
            ret = 0;
            break;
        }
    }

    return ret;
}
