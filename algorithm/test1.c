#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 2.1-4
 *   Consider the problem of adding two n-bit binary integers, stored in two n-element
 *   arrays A and B, The sum of the two integers should be stored in binary form in
 *   an (n+1)-element array C. State the problem formally and write pseudecode for
 *   adding the two integers.
 */

/*
 * Statement:
 *   Assume A[1..n] = {a1, a2, ..., an},
 *          B[1..n] = {b1, b2, ..., bn},
 *          where ai, bi equal 0 or 1, binary integer,
 *   and, A stands for an n-binary integer,
 *        B also stands for an n-binary integer,
 *   to caculate the sum of A and B,
 *
 */

/*
 * 1  for i=1 to A.length
 * 2      sum = A[i] + B[i]
 * 3      if sum == 2
 * 4         C[i+1] = 1
 * 5      elseif sum == 1
 * 6         if C[i] == 1
 * 7            C[i+1] = 1
 * 8            C[i] = 0
 * 9         else
 * 10           C[i] = 1
 */

int main(int argc, char *argv[]){
    int n = 0;
    if(argc == 2){
        n = strtod(argv[1], NULL);
    }
    if(n < 1){
         return 100;
    }
    char *A = (char *)malloc(n);
    char *B = (char *)malloc(n);
    char *C = (char *)malloc(n+1);
    memset(C, 0, n+1);
    int i=0;
    for(i=0; i<n; i++){
        printf("A[%d]=%d, B[%d]=%d\n", i, A[i], i, B[i]);
        char *p;
        A[i] = (((unsigned long)A[i])) % 2;
        char *q;
        B[i] = (((unsigned long)B[i])) % 2;
    }

    int sum=0;
    for(i=0; i<n; i++){
        sum = A[i] + B[i];
        if(sum == 2){
            C[i+1] = 1;
        } else if ( sum == 1 ){
            if(C[i] == 1){
                 C[i+1] = 1;
                 C[i] = 0;
            } else {
                C[i] = 1;
            }
        }
    }

    for(i=0; i<n; i++){
         printf("%d ", A[i]);
    }
    printf("\n");
    for(i=0; i<n; i++){
         printf("%d ", B[i]);
    }
    printf("\n");
    for(i=0; i<n+1; i++){
         printf("%d ", C[i]);
    }
    printf("\n");
}
