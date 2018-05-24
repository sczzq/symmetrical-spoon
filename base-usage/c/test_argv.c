#include <stdio.h>

int main(int argc, char *argv[]){
    int i = 0;
    printf("command: %s\n", argv[i++]);
    while(i<argc){
        printf("parameter %d: %s\n", i, argv[i++]);
    }
}
