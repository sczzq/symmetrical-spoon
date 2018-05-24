/*************************************************************************
	> File Name: queue.h
	> Author: ziqiang
	> Mail: ziqiang_free@163.com 
	> Created Time: Wed 09 May 2018 10:54:08 PM CST
 ************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_

struct Queue{
	void **element;
	int *id;
	int size;
	int head;
	int tail;
};

typedef struct Queue * queue;

queue get_queue();

void *pop(queue );
int push(queue , void * );
int isempty(queue );
int delete_queue(queue );

#endif

