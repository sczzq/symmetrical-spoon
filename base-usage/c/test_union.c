#include <stdio.h>

typedef struct S{
    union{
        int i;
        char c;
        double d;
    }u;
}S;

int main(int argc, char *argv[]){
    S s;

    s.u.i = 4;
    printf("%d\n", s.u.i);

    s.u.c = 'c';
    printf("%c\n", s.u.c);

    s.u.d = 4.4;
    printf("%f\n", s.u.d);
}
