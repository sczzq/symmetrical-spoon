/* queue.c -- the implemention of queue type */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* local function */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

void InitializeQueue(Queue * pg)
{
	pg->front = pg->rear = NULL;
	pg->items = 0;
}

bool QueueIsFull(const Queue *pg)
{
	return pg->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue * pg)
{
	return pg->items == 0;
}

int QueueItemCount(const Queue * pg)
{
	return pg->items;
}

bool EnQueue(Item item, Queue * pg)
{
	Node * pnew;

	if(QueueIsFull(pg))
		return false;
	pnew = (Node *) malloc(sizeof(Node));
	if(pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if( QueueIsEmpty(pg))
		pg->front = pnew;
	else
		pg->rear->next = pnew;
	pg->rear = pnew;
	pg->items++;
	return true;
}

bool DeQueue(Item *pitem, Queue *pg)
{
	Node *pt;
	
	if(QueueIsEmpty(pg))
		return false;
	CopyToItem(pg->front, pitem);
	pt = pg->front;
	pg->front = pg->front->next;
	free(pt);
	pg->items--;
	if(pg->items == 0)
		pg->rear = NULL;
	return true;
}

void EmptyTheQueue(Queue *pg)
{
	Item dummy;
	while(!QueueIsEmpty(pg))
		DeQueue(&dummy, pg);
}

static void CopyToNode(Item item, Node *pn)
{
	pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
	*pi = pn->item;
}


