/*************************************************************************
	> File Name: opendir.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 13 Dec 2017 09:08:27 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("usage: ./a.out <directory path>\n");
		exit(EXIT_FAILURE);
	}
	
	DIR *dir = opendir(argv[1]);
	if(dir == NULL){
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	struct dirent *dirt;
	while((dirt = readdir(dir)) != NULL){
		printf("d_ino: %d, name: %s\n", dirt->d_ino, dirt->d_name);
	}
	exit(EXIT_SUCCESS);
}

