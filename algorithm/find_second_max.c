/*************************************************************************
	> File Name: find_second_max.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月14日 星期一 15时30分55秒
 ************************************************************************/

/*
 * work step
 * first step:
 *	get the second maximum of the array with fixed size.
 *	to see function find_second_maximum
 *	
 * second step:
 *	still to get the second maximum of the array with fixed size.
 *	to see function find_second_max
 *
 * third step
 *	still to get the second maximum of the array with fixed size.
 *	to see function find_second_max2
 *
 * fourth step
 *	to get the nth maximum of the array with fixed size.
 *	to see function find_max_n
 *
 */

#include <stdio.h>
#include <limits.h>

#include "utils.h"

int show_array(int *array, int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", array[i]);
	debug_print("\n");
}

// first step.
// this function cannot work
// so, this is first step, 
// and get a wrong function.
int find_second_maximum(int *array, int size)
{
	if(size < 1)
		return INT_MAX;
	int max = array[0];
	int second = array[1];

	for(int i = 1; i < size; i++){
		if(max < array[i]){
			max = array[i];
		} else if(second < max && second < array[i]){
			second = array[i];
		}
		debug_print("max %d, second max %d\n", max, second);
	}
	debug_print("max %d, second max %d\n", max, second);
	return second;
}

/*
 * insert a value to array,
 * and the values after postion in array should move one step behind.
 * array	Array address
 * size		size of array
 * position	put value in this position
 * value	the value needed to put into array.
 *
 */
int array_insert(int *array, int size, int position, int value)
{
	if(position >= size)
		return -1;
	for(int i = size; i > position; i--){
		array[i] = array[i-1];
	}
	array[position] = value;
	return 0;
}

/*
 * fourth step.
 *
 * search nth maximum number in array.
 * this seems to work.
 *
 * qualities of the result set
 *	1, unique element
 *	2, sorted
 *
 * but need to optimize.
 * 1, use binary search to find the position to insert.
 * 2, use link-list or rbtree as the result data-structure.
 */
int find_max_n(int *array, int size, int *max_n, int n)
{
	for(int i = 0; i < n; i++){
		max_n[i] = INT_MIN;
	}

	int cur = 0;

	// assume max_n is unique sorted queue, 
	// insert all elements in array to max_n,
	// at the same time, keep it unique and sorted,
	for(int i = 0; i < size; ++i){
		int j = 0;
		// search the position to insert.
		// maybe using binary-search is better.
		for( ; j < cur; j++){
			if(array[i] > max_n[j])
				break;
		}
		// insert a value to position.
		if(cur != n || j != cur){
			// if same to previous element,
			// donot insert to result set.
			// so, the element in result set is unique.
			if(j!=0 && array[i] == max_n[j-1])
				continue;
			array_insert(max_n, n, j, array[i]);
			cur++;
		}
	}
}

/*
 * third step
 *
 * search second two maximum number in an array.
 * this function can work.
 */
int find_second_max2(int *array, int size)
{
	int second_two[2];

	if(size < 1)
		return INT_MAX;
	if(size == 1)
		return array[0];
	if(size == 2){
		return array[0] > array[1] ? array[1] : array[0];
	}
	second_two[0] = array[0] > array[1] ? array[0] : array[1];
	second_two[1] = array[0] > array[1] ? array[1] : array[0];


	for(int i = 2; i < size; i++){
		if(second_two[0] != second_two[1]){
			if(array[i] > second_two[0]){
				second_two[1] = second_two[0];
				second_two[0] = array[i];
			} else if(array[i] < second_two[0] && array[i] > second_two[1]){
				second_two[1] = array[i];
			}
		} else {
			if(array[i] > second_two[0]){
				second_two[1] = second_two[0];
				second_two[0] = array[i];
			} else if(array[i] < second_two[0]){
				second_two[1] = array[i];
			}
		}
	}

	printf("second_two is %d, %d\n", second_two[0], second_two[1]);

	return second_two[1];
}

int find_max(int *array, int size)
{
	if(size < 1)
		return INT_MAX;
	if(size == 1)
		return array[0];
	if(size == 2){
		return array[0] > array[1] ? array[0] : array[1];
	}
	int max = array[0];

	for(int i = 0; i < size; i++){
		if(max < array[i])
			max = array[i];
	}
	return max;
}

/* 
 * second step,
 *
 * get the second maximum element in an array.
 * this function can work.
 */
int find_second_max(int *array, int size)
{
	if(size == 2){
		return array[0] > array[1] ? array[1] : array[0];
	}
	else if(size == 1){
		return array[0];
	}
	if(size < 1) {
		return INT_MAX;
	}
	
	int left_max = find_max(array, size/2);
	int right_max = find_max(array+size/2, size-size/2);

	show_array(array, size);

	if(left_max < right_max){
		debug_print("its second max is left_max %d\n", left_max);
		return left_max;
	} else if(left_max > right_max){
		debug_print("its second max is right_max %d\n", right_max);
		return right_max;
	} else {
		int l_second_max = find_second_max(array, size/2);
		int r_second_max = find_second_max(array+size/2, size-size/2);
		if(l_second_max == left_max || r_second_max == right_max){ // 有一个半部分是相等的,则取最小的.
			if(l_second_max > r_second_max){
				debug_print("its second max is r_second_max %d\n", r_second_max);
				return r_second_max;
			} else if(l_second_max < r_second_max){
				debug_print("its second max is l_second_max %d\n", l_second_max);
				return l_second_max;
			}
			// 两个半部分都相等.
			else {
				debug_print("all element is same, is %d\n", l_second_max);
				return l_second_max;
			}
		} else { // 左半部分全部不相等,右半部分全部不相等,
			 // 则取返回值的最大的.
			if(l_second_max > r_second_max){
				debug_print("its second max is l_second_max %d\n", l_second_max);
				return l_second_max;
			} else if(l_second_max < r_second_max){
				debug_print("its second max is r_second_max %d\n", r_second_max);
				return r_second_max;
			}
		}
	}
}

/*
 * another implementation from http://www.cnblogs.com/fangyukuan/archive/2010/09/18/1829871.html
 *
 * to find the second-max number in an array with fixed size.
 *
 */

int find_sec_max(int data[], int size)
{
	if(size < 1)
		return INT_MIN;
	int max = data[0];
	int second = INT_MIN;
	for(int i = 0; i < count; ++i){
		if(data[i] > max){
			second = max;
			max = data[i];
		} else {
			if(data[i] > second){
				second = data[i];
			}
		}
	}
	return second;
}

int main()
{
	int array[] = {10, 4, 5, 20, 10, 30, 4, 2, 1};
	int size = sizeof(array) / sizeof(int);

	int array2[] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	int size2 = sizeof(array2) / sizeof(int);

	int array3[] = {10, 10, 4, 10, 10, 10};
	int size3 = sizeof(array3) / sizeof(int);

	int array4[] = {10, 10, 20, 10, 10, 10};
	int size4 = sizeof(array4) / sizeof(int);

	int array5[] = {10, 10, 20, 10, 10, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size5 = sizeof(array5) / sizeof(int);

//	find_second_maximum(array, size);

	debug_print("---------------------------\n");
	int second_max1 = find_second_max(array, size);

	printf("---------------------------\n");
	int second_max2 = find_second_max(array2, size2);

	printf("---------------------------\n");
	int second_max3 = find_second_max(array3, size3);

	printf("---------------------------\n");
	int second_max4 = find_second_max(array4, size4);

	printf("---------------------------\n");
	int second_max5 = find_second_max(array5, size5);

	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");
	show_array(array, size);
	printf("second max %d\n", second_max1);
	printf("find_second_max2: %d\n", find_second_max2(array, size));
	printf("---------------------------\n");
	
	show_array(array2, size2);
	printf("second max %d\n", second_max2);
	printf("find_second_max2: %d\n", find_second_max2(array2, size2));
	printf("---------------------------\n");
	
	show_array(array3, size3);
	printf("second max %d\n", second_max3);
	printf("find_second_max2: %d\n", find_second_max2(array3, size3));
	printf("---------------------------\n");
	
	show_array(array4, size4);
	printf("second max %d\n", second_max4);
	printf("find_second_max2: %d\n", find_second_max2(array4, size4));
	printf("---------------------------\n");
	
	show_array(array5, size5);
	printf("second max %d\n", second_max5);
	printf("find_second_max2: %d\n", find_second_max2(array5, size5));
	printf("---------------------------\n");
	printf("---------------------------\n");
	printf("---------------------------\n");

	int max_2[2];
	int n = 2;
	find_max_n(array, size, max_2, n);
	printf("first %d max number: ");
	for(int i = 0; i < n ; i++){
		printf("%d ", max_2[i]);
	}
	printf("---------------------------\n");
	find_max_n(array2, size2, max_2, n);
	printf("first %d max number: ");
	for(int i = 0; i < n ; i++){
		printf("%d ", max_2[i]);
	}

	printf("---------------------------\n");
	find_max_n(array3, size3, max_2, n);
	printf("first %d max number: ");
	for(int i = 0; i < n ; i++){
		printf("%d ", max_2[i]);
	}

	printf("---------------------------\n");
	find_max_n(array4, size4, max_2, n);
	printf("first %d max number: ");
	for(int i = 0; i < n ; i++){
		printf("%d ", max_2[i]);
	}

	printf("---------------------------\n");
	find_max_n(array5, size5, max_2, n);
	printf("first %d max number: ");
	for(int i = 0; i < n ; i++){
		printf("%d ", max_2[i]);
	}
	printf("---------------------------\n");


	return 0;
}
