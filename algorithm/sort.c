#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sort.h"

int merge(TYPE *, int , int , int);

/*
int main(){
    TYPE data[] = {7, 3, 2, 4, 1, 5, 8, 10, 6, 11, 9};
    int length = sizeof(data)/sizeof(TYPE);

    print_array(data, length);

//    insert_sort(data, length);
    merge_sort(data, 0, length-1);

    print_array(data, length);

    return 0;
}
*/

int print_array(TYPE *data, int length){
    int i = 0;
    for(i=0; i<length; i++){
        printf("%lu  ", data[i]);
    }
    printf("\n");
    return 0;
}

int insert_sort(TYPE *data, int length){
    int i=0, j=0;
    TYPE key;
    for(j=1; j<length; j++){
        key = data[j];
        i = j - 1;
        while(i>=0 && data[i]>key){
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = key;
    }
    return 0;
}

int merge_sort(TYPE *data, int p, int r){
    if(p < r){
        int q = (p + r)/2;
        merge_sort(data, p, q);
        merge_sort(data, q+1, r);
        merge(data, p, q, r);
    }
}

// here p q r are index of pointer.
int merge(TYPE *data, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    TYPE *L = malloc((n1+1) * sizeof(TYPE));
    TYPE *R = malloc((n2+1) * sizeof(TYPE));
    int i=0, j=0, k=0;
    for(i=0; i<n1; i++){
         L[i] = data[p+i];
    }
    for(j=0; j<n2; j++){
        R[j] = data[q+j+1];
    }
    for(i=0; i<(sizeof(TYPE)*8); i++){
        L[n1] |= (0x1<<i);
        R[n2] |= (0x1<<i);
    }

    i=0;j=0;
    for(k=p; k<=r; k++){
        if(L[i]<=R[j]){
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);
    return 0;
}

int binary_search(TYPE *A, int length, TYPE x){
    int s=0,e=length-1;
    int m = (s+e)/2;
    while(s<e){
        if(A[m]>x){
            e = m - 1;
        } else if (A[m]<x){
            s = m + 1;
        } else {
             break;
        }
        m = (s+e)/2;
    }
    if(A[m] == x){
        return 1;
    }
    return 0;
}

int search(TYPE *A, int length, TYPE x){
     return binary_search(A, length, x);
}

