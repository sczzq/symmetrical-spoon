/*************************************************************************
	> File Name: mallopt.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Mon 11 Dec 2017 11:23:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int malloc_init_value = (1 << 3) & 0xff;
	if(0 == mallopt(M_PERTURB, 0xff)){
		perror("mallopt");
		exit(EXIT_FAILURE);
	}
	int mall_size = 1024;
	int *ptr = (int *)malloc(mall_size * sizeof(int));
	if(ptr == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for(int i = 0; i < mall_size; i++){
		printf("%d", ptr[i]);
		if(i % 101 == 100){
			printf("\n");
		}
	}
	printf("\n");
	free(ptr);
//	free(ptr);

	exit(EXIT_SUCCESS);
}
