/*************************************************************************
	> File Name: test_array_bounds.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 27 Feb 2018 07:31:38 PM CST
 ************************************************************************/

#include <stdio.h>

int main()
{
	int arr[4] = {0, 1, 2, 3};
	arr[40] = 4;
	printf("%d\n", arr[0]);
	return 0;
}
