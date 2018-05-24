/*
 * Describe a Theta-(nlgn)-time algorithm that
 * Given a set S of n integers and another integer x,
 * determine whether or not there exit two elements in S
 * whose sum is exactly x.
 *
 * TOBEDOLIST:
 *     1, if there exit some pairs of elements in S,
 *           try to find out all of them.
 *     2, to test correctness if have nagetive number
 *           in set S,
 *
 */

#include "sort.h"

int problem2_3_7(TYPE *S, int length, TYPE t){
    int i, ret=0;
    merge_sort(S, 0, length-1);

    for(i=0; i<length-1; i++){
        int x = S[i];
        if(x<t && search(S+i+1, length-i-1, t-x)){
            ret = 1;
            break;
        }
    }

    return ret;
}

/*
 * Horner's rule
 *   The following code fragment implements Horner's rule for evaluating a polynomial
 *           P(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
 *                = a0 + x(a1 + x(a2 + ... + x(an-1 + x*an))).
 *   given the coeficients a0, a1, .., an and a value for x:
 *
 *   1  y = 0
 *   2  for i=n downto 0
 *   3    y = ai + x * y
 */
