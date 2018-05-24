/**
 * The maximum-subarray problem
 *
 */

#include "maximum_subarry.h"

#define MAX2(a, b)  ((a>b)?(a):(b))

int MAX3(int a, int b, int c){
    int temp = (a > b) ? a : b;

    return temp > c ? temp : c;
}

int MAX4(int a, int b, int c, int d){
    int t1 = (a>b)?a:b;
    int t2 = (c>d)?c:d;
    return (t1>t2)?t1:t2;
}

Subarray brute_force_solution(Array array){
    Subarray ms;
    ms.array = array;

    int i=0, j=0, k=0, sum=0xFFFFFFFF,tmp=0;
    for(i=0; i<array.length-1; i++){
        for(j=i+1; j<array.length; j++){
            tmp=0;
            for(k=i; k<j; k++){
                tmp += array.data[k];
            }
            if( sum < tmp ){
                 sum = tmp;
                 ms.left = i;
                 ms.right = j-1;
            }
        }
    }
    ms.sum = sum;

    return ms;
}

Subarray find_max_crossing_subarray(Subarray s){
    int mid = (s.left + s.right)/2;

    int left_sum = 0xFFFFFFFF, right_sum = 0xFFFFFFFF;
    int sum = 0, i;
    int max_left, max_right;
    for(i=mid; i>=s.left; i--){
        sum += s.array.data[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(i=mid+1; i<=s.right; i++){
        sum += s.array.data[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }

    s.left = max_left;
    s.right = max_right;
    s.sum = left_sum + right_sum;

    return s;
}

Subarray find_maximum_subarray(Subarray s){
    if(s.left == s.right){
        s.sum = s.array.data[s.left];
    } else {
        int mid = (s.left + s.right)/2;

        Subarray left_array = s;
        left_array.right = mid;
        left_array = find_maximum_subarray(left_array);

        Subarray right_array = s;
        right_array.left = mid + 1;
        right_array = find_maximum_subarray(right_array);

        Subarray cross_array = find_max_crossing_subarray(s);

        if(left_array.sum >= right_array.sum && left_array.sum >= cross_array.sum){
            s = left_array;
        } else if(right_array.sum >= left_array.sum && right_array.sum >= cross_array.sum){
            s = right_array;
        } else {
            s = cross_array;
        }
    }
    return s;
}

Subarray divide_and_conquer(Array array){
    Subarray s;

    printf("method %s\n", __func__);

    s.array = array;
    s.left = 0;
    s.right = array.length - 1;

    return find_maximum_subarray(s);
}

Subarray linear_time_solution(Array array){
    Subarray s;
    int *A = array.data;
    int left = 0, right = 0, t_left = -1, t_sum = 0, right_sum = 0, sum = A[0];
    int i=0, t;
    s.array = array;
    for(i=1; i<array.length; i++){
        if(t_left == -1){
            t = MAX3(sum, sum+A[i], A[i]);
            if(t == sum){
                t_left = 0;
                right_sum = A[i];
            } else if(t == sum+A[i]){
                right = i;
            } else if(t == A[i]){
                left = i;
                right = i;
            }
        } else if( t_left == 0 ){
            t = MAX3(sum, sum+right_sum+A[i], A[i]);
            if(t == sum){
                right_sum += A[i];
                if(A[i] > 0){
                    t_left = i;
                    t_sum = A[i];
                }
            } else if(t == sum+right_sum+A[i]){
                right = i;
                t_left = -1;
                t_sum = 0;
                right_sum = 0;
            } else if(t == A[i]){
                 left = i;
                 right = i;
                 t_left = -1;
                 t_sum = 0;
                 right_sum = 0;
            }
        } else if( t_left > 0 ){
             t = MAX4(sum, sum+right_sum+A[i], t_sum + A[i], A[i]);
             if(t == sum){
                 t_sum += A[i];
                 right_sum += A[i];
                 if(t_sum < 0){
                     t_left = 0;
                     t_sum = 0xFFFFFFFF;
                 }
             } else if(t == sum+right_sum+A[i]){
                 right = i;
                 t_left = -1;
                 t_sum = 0;
                 right_sum = 0;
             } else if(t == t_sum + A[i]){
                  left = t_left;
                  right = i;
                  t_left = -1;
                  t_sum = 0xFFFFFFFF;
                  right_sum = 0;
             } else if(t == A[i]){
                 left = i;
                 right = i;
                 t_left = -1;
                 t_sum = 0xFFFFFFFF;
             }
        }
        sum = t;

//        printf("left %d, right %d, t_left %d, t_sum %d, right_sum %d, sum %d\n",
//                left, right, t_left, t_sum, right_sum, sum);
    }

    s.left = left;
    s.right = right;
    s.sum = sum;

    return s;
}

Subarray get_maximum_subarray3(Array array){
    return divide_and_conquer(array);
}

Subarray get_maximum_subarray2(Array array){
    return brute_force_solution(array);
}

Subarray get_maximum_subarray(Array array){
    return linear_time_solution(array);
}

void print_array(Array array){
     int i;
     printf("\nIndex: ");
     for(i=0; i<array.length; i++){
         printf("\t%d ", i);
     }
     printf("\n");
     printf("Array: ");
     for(i=0; i<array.length; i++){
         printf("\t%d ", array.data[i]);
     }
     printf("\nlength: %d\n\n", array.length);
     return;
}

