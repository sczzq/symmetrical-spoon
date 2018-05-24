/*************************************************************************
	> File Name: double_pointer.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: 2018年05月20日 星期日 13时24分00秒
 ************************************************************************/

#include <stdio.h>

/*
 * about the memory layout of more-string strings
 * like "hello\0world\0every one\0\0"
 * this is the implementation of the layout of char *string[]
 *
 * if assign it to parameter like char **data,
 * how to parse each string in data.
 *
 * note: sizeof(data) has no effect,
 *       sizeof(char *) also need not to use.
 *
 * do like this:
 *	1, parse first null-terminated string,
 *	2, move the start-position of data to start of next string,
 *	3, then get the next null-terminated string,
 *	4, reply step2-3.
 *
 *
 */

int main()
{
	char **ds = {"hello", "world", "every one"};

	char **ds2 = malloc(sizeof("hello world every one") + 1);

	memcpy(ds2, "hello\0world\0every one\0", sizeof("hello\0world\0every one\0")+1);

//	printf("sizeof(ds): %u, sizeof(char *): %u\n", sizeof(ds), sizeof(char *));
//	printf("sizeof(ds): %u, sizeof(char *): %u\n", sizeof(ds2), sizeof(char *));
	
}

