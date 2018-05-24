#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned long TYPE;

extern int debug;

int insert_sort(TYPE*, int);
int print_array(TYPE*, int);
int merge_sort(TYPE *, int, int);

int search(TYPE *, int, TYPE);

int problem2_3_7(TYPE *S, int length, TYPE t);

int inversion(TYPE *S, int length);

#endif

