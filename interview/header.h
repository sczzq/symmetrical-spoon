#ifndef HEADER_H
#define HEADER_H

typedef struct Stack Stack;
Stack *getStack();
void releaseStack(Stack *stack);
void stack_push(Stack *stack, void *data);
void stack_pop(Stack *stack, void **data);
void stack_access(Stack *stack, void **data);
int stack_size(Stack *stack);
int stack_capability(Stack *stack);


typedef struct Queue Queue;
Queue *getQueue();
void releaseQueue(Queue *queue);
void queue_push_front(Queue *queue, void *data);
void queue_pop_front(Queue *queue, void **data);
void queue_push_back(Queue *queue, void *data);
void queue_pop_back(Queue *queue, void **data);
int queue_size(Queue *queue);
int queue_capalibity(Queue *queue);


typedef struct BinarySearchTree BinarySearchTree;
typedef struct Node Node;
typedef int (*Compare)(void *, void *);
int string_compare(void *s1, void *s2);
int integer_compare(void *s1, void *s2);

BinarySearchTree *getBSTree(Compare comp);
void releaseBSTree(BinarySearchTree *tree);
void bst_insert(BinarySearchTree *tree, void *data);
Node *bst_search(BinarySearchTree *tree, void *data);
int bst_height(BinarySearchTree *tree);


typedef struct DoubleLinkedList DoubleLinkedList;
DoubleLinkedList *getDLList(Compare compare);
void releaseDLList(DoubleLinkedList *list);
int dllist_insert_back(DoubleLinkedList *list, void *data);
int dllist_insert_front(DoubleLinkedList *list, void *data);
Node *dllist_search(DoubleLinkedList *list, void *data);
int dlllist_delete(DoubleLinkedList *list, void *data);
int dllist_reverse(DoubleLinkedList *list);
void dllist_transfer_front(DoubleLinkedList *list);
void dllist_transfer_back(DoubleLinkedList *list);

int random_string(char *rand_str, int length);
int random_integer(int *, int size, int max);


typedef struct val_varry val_varry;
val_varry *getValVarry();
val_varry *copyValVarry(val_varry * val);
void releaseValVarry(val_varry *val);
int insertValVarry(val_varry *val, int d);
int sumValVarry(val_varry *val);
int getSumValVarry(val_varry *val);
int sizeValVarry(val_varry *val);
int dataValVarry(val_varry *val, int index);

#endif

