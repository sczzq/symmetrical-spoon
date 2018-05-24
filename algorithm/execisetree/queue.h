/* queue.h -- queue interface */
#pragma c9x on
#ifndef __QUEUE_H_
#define __QUEUE_H_
#include <stdbool.h>

//#define TEST
#ifdef TEST
typedef int Item;
#else
typedef struct item
{
	long arrive;     /* time of adding of a customer */
	int processtime; /* inquery time of the customer */
} Item;
#endif

#define MAXQUEUE 10

typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef struct queue
{
	Node * front; /* pointing to header of queue */
	Node * rear;  /* pointing to rear of queue */
	int items;   /* item's number in queue */
} Queue;

/*
 * opration: initialize a queue
 * before operation: pg points to a queue
 * after operation: the queue has initialized
 */
void InitializeQueue(Queue * pq);

/*
 * operation: check queue is full or not
 * before operation: pg points to an initialized queue
 * after operation: if the queue is empty, then return True, otherwise return False
 */
bool QueueIsFull(const Queue * pg);

/*
 * operation: check queue is empty or not
 */
bool QueueIsEmpty(const Queue *pg);

/*
 * operation: count item number in the queue
 * before operation: pg points to an initialized queue
 * after operation: return item number in the queue
 */
int QueueItemCount(const Queue * pq;);

/*
 * operation: add new item to the rear of queue
 * before operation: pg points to an initialized queue
 * 		     item is the new item
 * after operation: if queue is not full, item will be added to rear of the queue, return True
 * 			otherwise queue will be not changed, return False
 */
bool EnQueue(Item item, Queue * pg);

/*
 * operation: delete item from front of queue
 */
bool DeQueue(Item * pitem, Queue * pg);

/*
 * operation: empty the queue.
 */
void EmptyTheQueue(Queue * pg);

#endif

