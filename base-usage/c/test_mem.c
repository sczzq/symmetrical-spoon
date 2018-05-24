#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void m_free(char *t){
    printf("%p\n", t);
}

int main(){
    char *arg, *val;
    arg = (char *)malloc(20);

    sprintf(arg,"Hello\n");

    printf("val: %p\n", val);
    printf("arg: %p\n", arg);

    memcpy(&val, &arg, sizeof(val));
    memcpy(&arg, &(void *){ NULL }, sizeof(val));

    printf("val: ");
    m_free(val);
    printf("arg: ");
    m_free(arg);
}
