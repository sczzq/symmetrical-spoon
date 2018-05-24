#include "math.h"

long long factorial(int x){
    long long r=1;
    while(x>0){
        r *= x;
        x--;
    }
    return r;
}
