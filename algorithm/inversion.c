/**
 * Give an algorithm that determines the number of inversions in any permutation
 * on n elements in Theta-nlgn worst-case time.
 * (Hint: Modify merge sort)
 */

#include "sort.h"

// here p q r is index of array
int modify_merge(TYPE *A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int length = r - p + 1;
    int inversion = 0;
    TYPE *L = malloc(n1 * sizeof(TYPE));
    TYPE *R = malloc(n2 * sizeof(TYPE));
    int i, j, k;
    for(i=0; i<n1; i++){
        L[i] = A[p+i];
    }
    for(i=0; i<n2; i++){
        R[i] = A[q+i+1];
    }
    i = 0;
    j = 0;
    for(k=p; k<=r; k++){
        if(i<n1 && j<n2){
            if(L[i] <= R[j]){
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
                inversion += (n1 - i);
                if(debug)
                    printf("%lu inversion is %d\n", A[k], n1 - i);
            }
        } else {
            if(i == n1){
                A[k] = R[j];
                j++;
            } else if(j == n2){
                A[k] = L[i];
                i++;
            }
        }
    }
    free(L);
    free(R);
    return inversion;
}

// here p r is index of array.
int modify_merge_sort(TYPE *A, int p, int r){
    int inversion = 0;
    if( p < r ){
        int q = (p+r)/2;
        inversion += modify_merge_sort(A, p, q);
        inversion += modify_merge_sort(A, q+1, r);
        inversion += modify_merge(A, p, q, r);
    }
    return inversion;
}

int inversion(TYPE *S, int length){
    TYPE *A = malloc(length * sizeof(TYPE));
    memcpy(A, S, length*sizeof(TYPE));
    int inversion = modify_merge_sort(A, 0, length-1);
    if(debug)
        print_array(A, length);
    free(A);
    return inversion;
}

