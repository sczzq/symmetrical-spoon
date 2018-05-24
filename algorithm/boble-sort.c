/*************************************************************************
	> File Name: boble-sort.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月21日 星期一 21时39分09秒
 ************************************************************************/

#include <stdio.h>
#include <assert.h>

int swap(int *data, int r, int s)
{
	int temp = *(data + r);
	*(data + r) = *(data + s);
	*(data + s) = temp;
}

// ascend sort.
int boble_sort(int *data, int size)
{
	assert(data);
	assert(size > 0);

	int i = size;
	while(i > 0){
		int j = 0;
		while(j < size - 1){
			if(*(data+j) > *(data+j+1)){
				swap(data, j, j+1);
			}
			j++;
		}
		i--;
	}
	return 0;
}

int print_array(int *data, int size)
{
	int i = 0;
	while(i < size){
		printf("%d ", *(data+i));
		i++;
	}
	printf("\n");
	return 0;
}

// ascend sort.
int insert_sort(int *data, int size)
{
	assert(data);
	assert(size > 0);

	int *result = malloc(size * sizeof(int));
	int i = 0;
	for(i = 0; i < size; i++){
		*(result + i) = 0;
	}

	result[0] = data[0];
	for(i = 1; i < size; i++){
		int j = 0;
		// find the middle position if exist.
		for(j = 0; j < i; j++){
			if( *(result+j) > *(data+i) ){
			// find the insert position.
				int k = i;
				while(j < k){ // move to the end.
					*(result+k) = *(result+k-1);
					k--;
				}
				*(result+j) = *(data+i);
				break;
			}
		}
		// if not in middle,
		// just insert the position after last element.
		if(j == i){
			*(result+j) = *(data+i);
		}
	}
	for(i = 0; i < size; i++){
		*(data+i) = *(result+i);
	}
	free(result);
	return 0;
}

int main()
{
	int data[] = {10, 4, 1, 32, 5, 6, 1};
	int size = sizeof(data) / sizeof(int);
	print_array(data, size);
//	boble_sort(data, size);
	insert_sort(data, size);
	print_array(data, size);
}

