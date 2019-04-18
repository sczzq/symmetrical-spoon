// queue optor

// push_front
// pop_front
// push_back
// pop_back

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue Queue;

struct Queue {
	void **data;
	int start;
	int end;
	int size;
	int capability;
};

Queue *getQueue()
{
	Queue *queue = malloc(sizeof(Queue));
	queue->data = malloc(sizeof(void *) * 8);
	queue->start = 0;
	queue->end = 0;
	queue->size = 0;
	queue->capability = 8;
	return queue;
}

void releaseQueue(Queue *queue)
{
	free(queue->data);
	queue->data = NULL;
	queue->start = 0;
	queue->end = 0;
	queue->size = 0;
	queue->capability = 0;
	free(queue);
}

Queue *queueEnlarge(Queue *queue)
{
	if (queue->size + 1 >= queue->capability)
	{
		int old_capability = queue->capability;
		queue->capability *= 2;
		queue->data = realloc(queue->data,
				queue->capability * sizeof(void *));
		if (queue->start > queue->end)
		{
			memcpy(queue->data+old_capability*sizeof(void *),
					queue->data, queue->end * sizeof(void *));
			queue->end += old_capability;
		}
	}
	return queue;
}

void queue_push_front(Queue *queue, void *data)
{
	queueEnlarge(queue);
	queue->data[queue->start] = data;
	queue->start = (queue->start - 1 + queue->capability) % queue->capability;
	queue->size++;
}

void queue_pop_front(Queue *queue, void **data)
{
	if (queue->size > 0)
	{
		*data = queue->data[queue->start];
		queue->start = (queue->start + 1 + queue->capability) % queue->capability;
		queue->size--;
	}
}

void queue_push_back(Queue *queue, void *data)
{
	queueEnlarge(queue);
	queue->data[queue->end] = data;
	queue->end = (queue->end + 1 + queue->capability) % queue->capability;
	queue->size++;
}

void queue_pop_back(Queue *queue, void **data)
{
	*data = queue->data[queue->end];
	queue->end = (queue->end - 1 + queue->capability) % queue->capability;
	queue->size--;
}

int queue_size(Queue *queue)
{
	return queue->size;
}

int queue_capalibity(Queue *queue)
{
	return queue->capability;
}

int queue_start(Queue *queue)
{
	return queue->start;
}

int queue_end(Queue *queue)
{
	return queue->end;
}

int queue_test1()
{
	char *s1 = "hello";
	char *s2 = "world";

	Queue *q = getQueue();
	queue_push_front(q, (void *)s1);
	queue_push_front(q, (void *)s2);

	printf("size: %d\n", queue_size(q));
	printf("capability: %d\n", queue_capalibity(q));
	printf("start: %d, end: %d\n", queue_start(q), queue_end(q));

	char *s3;

	queue_pop_front(q, (void **)&s3);
	printf("s: %s\n", s3);

	printf("size: %d\n", queue_size(q));
	printf("capability: %d\n", queue_capalibity(q));
	printf("start: %d, end: %d\n", queue_start(q), queue_end(q));

	queue_pop_front(q, (void **)&s3);
	printf("s: %s\n", s3);

	printf("size: %d\n", queue_size(q));
	printf("capability: %d\n", queue_capalibity(q));
	printf("start: %d, end: %d\n", queue_start(q), queue_end(q));

	releaseQueue(q);
}

/*
int main()
{
	test1();
}
*/

