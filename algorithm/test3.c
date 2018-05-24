
#include "divide.h"

int test_maximum_subarray();
int test_maximum_subarray2();
int test_maximum_subarray3();
int test_maximum_subarray4();

int main(){
    test_maximum_subarray();
    test_maximum_subarray2();
    test_maximum_subarray3();
    test_maximum_subarray4();
    return 0;
}

int test_maximum_subarray(){
    int a[] = {13, -3, -25, 20, -3, 16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Array array;
    array.data = a;
    array.length = sizeof(a)/sizeof(int);
    print_array(array);
    Subarray ms = get_maximum_subarray(array);
    printf("maximum subarray: [%d,%d], sum: %d\n", ms.left, ms.right, ms.sum);
    return 0;
}

int test_maximum_subarray2(){
    int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    Array array;
    array.data = a;
    array.length = sizeof(a)/sizeof(int);
    print_array(array);
    Subarray ms = get_maximum_subarray(array);
    printf("maximum subarray: [%d,%d], sum: %d\n", ms.left, ms.right, ms.sum);
    return 0;
}

int test_maximum_subarray3(){
    int a[] = {-13, -3, -25, -20, -3, -16, -23, -18, -20, -7, -12, -5, -22, -15, -4, -7};
    Array array;
    array.data = a;
    array.length = sizeof(a)/sizeof(int);
    print_array(array);
    Subarray ms = get_maximum_subarray(array);
    printf("maximum subarray: [%d,%d], sum: %d\n", ms.left, ms.right, ms.sum);
    return 0;
}

int test_maximum_subarray4(){
    int a[] = {8, -3,0, -2, -3, -1, 6, -1, -2, 7, -12, -5, -22, -15, -4, -7};
    Array array;
    array.data = a;
    array.length = sizeof(a)/sizeof(int);
    print_array(array);
    Subarray ms = get_maximum_subarray(array);
    printf("maximum subarray: [%d,%d], sum: %d\n", ms.left, ms.right, ms.sum);
    return 0;
}




