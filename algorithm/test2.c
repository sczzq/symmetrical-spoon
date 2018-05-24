#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sort.h"

int test_merge_sort(TYPE *S, int length);
int test_inversion(TYPE *S, int length);
int parse_parameter(int argc, char *argv[]);

int debug = 0;

int main(int argc, char *argv[]){
    TYPE S[] = {2, 13, 4, 1, 17, 5, 6, 9, 10, 11};
    int i = 0;
    int length = sizeof(S)/sizeof(TYPE);

    parse_parameter(argc, argv);

//    test_merge_sort(S, length);

    test_inversion(S, length);

    return 0;
}

int parse_parameter(int argc, char *argv[]){
    if(argc == 2){
        debug = strtod(argv[1], NULL);
        printf("in debug %d mode\n", debug);
    }
}

int test_inversion(TYPE *S, int length){
    int inversion_number = 0;

    inversion_number = inversion(S, length);

    print_array(S, length);
    printf("inversion is %d\n", inversion_number);

    return 0;
}

int test_merge_sort(TYPE *S, int length){
    TYPE x = 1;
    merge_sort(S, 0, length-1);
    print_array(S, length);

    for(x=0; x<S[length-1]*2; x++){
        if(problem2_3_7(S, length, x)){
            printf("find %lu in set that exist tow elements whose sum is exactly equals with\n", x);
        } else {
            printf("%lu oohps\n", x);
        }
    }

    return 0;
}

