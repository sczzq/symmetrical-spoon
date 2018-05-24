/* stack.c -- implementation of stack data type */
#include "stack.h"

void InitializeStack(Stack * pst)
{
	pst->top = 0;
}

bool StackIsFull(const Stack * pst)
{
	return (pst->top >= MAXITEMS) ? true : false;
}

bool StackIsEmpty(const Stack * pst)
{
	return (pst->top <= 0) ? true : false;
}

int StackItemCount(const Stack * pst)
{
	return pst->top;
}

bool PushStack(Item item, Stack * pst)
{
	if(StackIsFull(pst))
		return false;

	pst->node.item[pst->top] = item;
	pst->top++;
	return true;
}

bool PopStack(Item * pitem, Stack * pst)
{
	if(StackIsEmpty(pst))
		return false;

	*pitem = pst->node.item[pst->top-1];
	pst->top--;
	return true;
}

void EmptyTheStack(Stack * pst)
{
	pst->top = 0;
}

