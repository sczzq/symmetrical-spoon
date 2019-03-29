// double linked list
//
// insert
// delete
// search

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
	void *data;
	Node *prev;
	Node *next;
};

typedef struct DoubleLinkedList DoubleLinkedList;

typedef int (*Compare)(void *, void *);

// Double Linked List with sentinel
// head and tail nodes are sentinel.
struct DoubleLinkedList {
	Node *head;
	Node *tail;
	int size;
	Compare compare;
};

// return value
//	-1 s1 less than s2
//	0  s1 equals to s2
//	1  s1 greater than s2
int string_compare(void *s1, void *s2)
{
	return strcmp((char *)s1, (char *)s2);
}

int integer_compare(void *s1, void *s2)
{
	return ((*(int *)s1 - *(int *)s2)) % 1;
}


Node *getNode(void *data)
{
	Node *node = malloc(sizeof(Node));
	if(node)
	{
		node->data = data;
		node->prev = NULL;
		node->next = NULL;
	}
	return node;
}

void releaseNode(Node *node)
{
	node->data = NULL;
	node->prev = NULL;
	node->next = NULL;
	free(node);
}

DoubleLinkedList *getDLList(Compare compare)
{
	DoubleLinkedList *list = malloc(sizeof(DoubleLinkedList));
	list->head = getNode(NULL);
	list->tail = getNode(NULL);
	list->size = 0;
	list->compare = compare;

	list->head->next = list->tail;
	list->tail->prev = list->head;

	return list;
}

void releaseDLList(DoubleLinkedList *list)
{
	Node *node = list->head->next;
	Node *next = node->next;
	while(node != list->tail)
	{
		releaseNode(node);
		node = next;
		next = node->next;
	}
	free(list->head);
	free(list->tail);
	free(list);
}

int insert_node(Node *prev, Node *next, Node *node)
{
	prev->next = node;
	node->prev = prev;

	node->next = next;
	next->prev = node;

	return 0;
}

int delete_node(Node *prev, Node *next, Node *node)
{
	prev->next = next;
	next->prev = prev;
	releaseNode(node);
	return 0;
}

int dllist_insert_back(DoubleLinkedList *list, void *data)
{
	Node *node = getNode(data);
	insert_node(list->tail->prev, list->tail, node);
	list->size++;
	return 0;
}

int dllist_insert_front(DoubleLinkedList *list, void *data)
{
	Node *node = getNode(data);
	insert_node(list->head, list->head->next, node);
	list->size++;
	return 0;
}

Node *dllist_search(DoubleLinkedList *list, void *data)
{
	Node *node = list->head->next;
	while(node != list->tail)
	{
		if (0 == list->compare(data, node->data))
		{
			return node;
		}
		node = node->next;
	}
	return NULL;
}

int dlllist_delete(DoubleLinkedList *list, void *data)
{
	Node *node = dllist_search(list, data);
	if (node)
	{
		delete_node(node->prev, node->next, node);
		list->size--;
	}
	return 0;
}

int dllist_reverse(DoubleLinkedList *list)
{
	Node *node = list->head;
	list->head = list->tail;
	list->tail = node;

	node = list->head->prev;
	list->head->prev = NULL;
	list->head->next = node;

	Node *next = node->prev;
	node->prev = list->head;

	while(node != list->tail)
	{
		node->next = next;
		Node *temp = next->prev;
		next->prev = node;
		node = next;
		next = temp;
	}

	list->tail->next = NULL;
}

void dllist_transfer_front(DoubleLinkedList *list)
{
	Node *node = list->head->next;
	while(node != list->tail)
	{
		printf("%s  ", (char *)node->data);
		node = node->next;
	}
	printf("\n");
}

void dllist_transfer_back(DoubleLinkedList *list)
{
	Node *node = list->tail->prev;
	while(node != list->head)
	{
		printf("%s  ", (char *)node->data);
		node = node->prev;
	}
	printf("\n");
}

int dllist_test1()
{
	DoubleLinkedList *list = getDLList(string_compare);
	char *s1 = "1";
	char *s2 = "2";
	char *s3 = "3";
	char *s4 = "4";

	dllist_insert_front(list, (void *)s1);
	dllist_insert_front(list, (void *)s2);
	dllist_insert_front(list, (void *)s3);
	dllist_insert_front(list, (void *)s4);

	dllist_transfer_front(list);
	dllist_transfer_back(list);

	dllist_reverse(list);

	dllist_transfer_front(list);
	dllist_transfer_back(list);

	releaseDLList(list);
}

int dllist_test2()
{
	printf("--------test2----\n");
	DoubleLinkedList *list = getDLList(string_compare);
	dllist_transfer_front(list);
	dllist_transfer_back(list);
	dllist_reverse(list);
	dllist_transfer_front(list);
	dllist_transfer_back(list);
	releaseDLList(list);

	printf("------------\n");
}


int dllist_test3()
{
	printf("--------test3----\n");
	DoubleLinkedList *list = getDLList(string_compare);
	char *s1 = "1";

	dllist_insert_front(list, (void *)s1);

	dllist_transfer_front(list);
	dllist_transfer_back(list);

	dllist_reverse(list);

	dllist_transfer_front(list);
	dllist_transfer_back(list);

	releaseDLList(list);
	printf("------------\n");
}


int dllist_test4()
{
	printf("--------test4----\n");
	DoubleLinkedList *list = getDLList(string_compare);
	char *s1 = "1";
	char *s2 = "2";

	dllist_insert_front(list, (void *)s1);
	dllist_insert_front(list, (void *)s2);

	dllist_transfer_front(list);
	dllist_transfer_back(list);

	dllist_reverse(list);

	dllist_transfer_front(list);
	dllist_transfer_back(list);

	releaseDLList(list);
	printf("------------\n");
}

/*
int main()
{
	dllist_test1();
	dllist_test2();
	dllist_test3();
	dllist_test4();
}
*/
