#include <stdio.h>
#include <limits.h>
#include "math.h"

void test1();

int main(){
    test1();
}

void test1(){
    int i=0;
    for(i=1; i<INT_MAX; i++){
        long long r = factorial(i);
        if(r>0)
            printf("factorial(%d)=%lld\n", i, r);
        else
            break;
    }
}
