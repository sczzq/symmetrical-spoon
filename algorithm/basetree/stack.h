/* stack.h -- interface of stack data type */
#ifndef __STACK_H_
#define __STACK_H_
#include <stdbool.h>

#define MAXITEMS 10

typedef int Item;

typedef struct node
{
	Item item[MAXITEMS];
} Node;

typedef struct stack
{
	Node node;
	int top; /* top of the stack, and is the number of items in stack */
} Stack;

/*
 * operation: initialize a stack
 */
void InitializeStack(Stack * pst);

/*
 * operation: to check stack is full or not
 */
bool StackIsFull(const Stack * pst);

/*
 * operation: to check statck is empty or not
 */
bool StackIsEmpty(const Stack * pst);

/*
 * operation: count the stack item number
 */
int StackItemCount(const Stack * pst);

/*
 * operation: push item from stack
 */
bool PushStack(Item item, Stack * pst);

/*
 * operation: pop item to stack
 */
bool PopStack(Item * pitem, Stack * pst);

/*
 * operation: pop all item of the stack
 */
void EmptyTheStack(Stack * pst);
#endif
