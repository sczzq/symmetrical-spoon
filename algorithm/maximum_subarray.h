#ifndef _DIVIDE_H_
#define _DIVIDE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Array{
    int *data;
    int length;
}Array;

// left right are index of array.
typedef struct Subarray{
    Array array;
    int left;
    int right;
    int sum;
}Subarray;

typedef struct Solution{
    Subarray ms;
    int t_left;
    int t_sum;
}Solution;

Subarray get_maximum_subarray(Array array);
Subarray get_maximum_subarray2(Array array);

void print_array(Array);


#endif
