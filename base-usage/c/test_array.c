/*************************************************************************
	> File Name: test_array.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Tue 03 Apr 2018 09:07:07 PM CST
 ************************************************************************/

#include <stdio.h>

int main()
{
	int array[3][4] = {{1, 2, 3, 4},
		 			   {1, 2, 3, 4},
					   {1, 2, 3, 4}};
	int col = 4, row = 3;
	int col_sum[4] = {0, 0, 0, 0};

	int i, j;

	// start
	for(i=0; i<col; i++){
		for(j=0; j<row; j++){
			col_sum[i] += array[j][i];
		}
	}
	// end

	for(i=0; i<col; i++){
		printf("%d ", col_sum[i]);
	}
	printf("\n");
	return 0;
}
