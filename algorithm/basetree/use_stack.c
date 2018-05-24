/* use_stack.c -- sample to use stack data type */
/* link with stack.c */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	Stack stack;
	Item temp;
	srand(time(0));

	InitializeStack(&stack);
	
	int i=0;
	while(i<50)
	{
		printf("%d", i);
		if(StackIsFull(&stack))
			printf(": Stack is full, and item number is %d\n", StackItemCount(&stack));
		if(StackIsEmpty(&stack))
			puts(": Stack is empty");
		if(rand()%2 == 1)
			if(false==PopStack(&temp, &stack))
				puts("  pop error");
			else
				printf("  pop item %d\n", (int)temp);
		else
			if(false==PushStack((Item)i, &stack))
				puts("  push error");
			else
				printf("  push %d\n", i);
		i++;
	}

	puts("-------------------");
	while(false==StackIsEmpty(&stack))
	{
		if(false==PopStack(&temp, &stack))
			puts("  pop error");
		else
			printf("  pop item %d\n", (int)temp);
	}

	return 0;
}

