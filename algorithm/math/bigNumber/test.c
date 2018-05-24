#include "bigInteger.h"

void test12();
void test22();

int main(){
//    test12();
//    test22();
//    test();
//    test1();
//    test2();
    test4();
}

void test12(){
    int i=0;
    uint32_t n = 0;
    for(i=0; i<32; i++){
        printf("0x%08X, ", 0x1<<i);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    for(i=0; i<32; i++){
        printf("%u, ", 0x1<<i);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    for(i=0; i<32; i++){
        printf("0x%08X, ", ~(0x1<<i));
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    for(i=0; i<32; i++){
        n += 0x1<<i;
        printf("0x%08X, ", n);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    n = 0;
    for(i=0; i<32; i++){
        n += 0x1<<i;
        printf("%u, ", n);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
}

void test22(){
    uint64_t i=0;
    uint64_t n = 0;
    uint64_t t, b64 = 0x1;
    /*
    */
    printf("\n");
    for(i=0; i<64; i++){
        printf("%lu, ", b64<<i);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    uint32_t a, b;
    for(i=0; i<64; i++){
        n += b64<<i;
        a = n>>32;
        b = n&0xFFFFFFFF;
        printf("0x%08X%08X, ", a, b);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    n = 0;
    for(i=0; i<64; i++){
        t = b64 << i; // use 0x1 as shift base number.
        n += t;
        printf("%lu, ", n);
        if((i+1)%4==0){
            printf("\n");
        }
    }
    printf("\n");
    printf("%lu\n", 0xFFFFFFFFFFFFFFFF);
}

