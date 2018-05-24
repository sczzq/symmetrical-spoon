/*************************************************************************
	> File Name: queue.c
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 09 May 2018 10:58:59 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "xmalloc.h"

void *pop(queue qu)
{
	if(qu->size > 0 && qu->head != qu->tail){
//		printf("before head %d\n", qu->head);
		void *ele = qu->element[qu->head];
//		printf("ele: %d\n", (int)ele);
		qu->head += 1;
		qu->head = qu->head >= qu->size ? 0 : qu->head;
//		printf("after head %d\n", qu->head);
		return ele;
	}
	return NULL;
}

static int expand(queue qu)
{
	if(((qu->tail+1) % qu->size) == qu->head){
		qu->size *= 2;
		void ** newele = (void **)realloc((void *)qu->element, qu->size * 2 * sizeof(void **));
		if(newele == NULL){
			fprintf(stderr, "realloc error\n");
			exit(EXIT_FAILURE);
		}
		qu->element = newele;
		int oldsize = qu->size/2;
		if(qu->tail < qu->head){
			int i = 0;
			while(i < qu->tail){
				qu->element[oldsize++] = qu->element[i++];
			}
			qu->tail = oldsize;
		}
//		printf("expand size from %d to %d\n", qu->size/2, qu->size);
	}
	return 0;
}

static int init(queue qu)
{
	if(qu->size == 0){
		qu->size = 32;
		qu->element = (void **)xmalloc(qu->size * sizeof(void **));
		qu->head = 0;
		qu->tail = 0;
	}
	return 0;
}

int push(queue qu, void *ele)
{
	init(qu);
	expand(qu);
//	printf("before tail: %d\n", qu->tail);
//	printf("ele: %d\n", (int)ele);
	qu->element[qu->tail] = ele;
	qu->tail += 1;
	qu->tail = qu->tail >= qu->size ? 0 : qu->tail;
//	printf("after tail: %d\n", qu->tail);
}

int isempty(queue qu)
{
	return (qu->head==qu->tail) ? true : false;
}

queue get_queue()
{
	queue qu = xmalloc(sizeof(*qu));
	init(qu);
	return qu;
}

int delete_queue(queue qu)
{
	if(qu){
		if(qu->element){
			free(qu->element);
		}
		free(qu);
	}
	return 0;
}

