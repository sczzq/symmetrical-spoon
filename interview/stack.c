// stack optor

// push
// pop
// access

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack Stack;

struct Stack {
	void **data;
	int size;
	int capability;
};

Stack *getStack()
{
	Stack *s = malloc(sizeof(Stack));
	s->data = malloc(sizeof(void *) * 8);
	s->size = 0;
	s->capability = 8;
	return s;
}

void releaseStack(Stack *stack)
{
	if(stack)
	{
		free(stack->data);
		stack->data = NULL;
		stack->size = 0;
		stack->capability = 0;
		free(stack);
	}
}

Stack *stackEnlarge(Stack *stack)
{
	if (stack && stack->size + 1 >= stack->capability)
	{
		stack->capability *= 2;
		stack->data = realloc(stack->data,
				stack->capability);
	}
	return stack;
}

void stack_push(Stack *stack, void *data)
{
	stackEnlarge(stack);
	stack->data[stack->size++] = data;
}

void stack_pop(Stack *stack, void **data)
{
	if (stack->size > 0)
		*data = stack->data[--stack->size];
	else
		*data = NULL;
}

void stack_access(Stack *stack, void **data)
{
	if (stack->size > 0)
		*data = stack->data[stack->size-1];
	else 
		*data = NULL;
}

int stack_size(Stack *stack)
{
	return stack->size;
}

int stack_capability(Stack *stack)
{
	return stack->capability;
}

int stack_test1()
{
	Stack *stack = getStack();

	char *s1 = "Hello";
	char *s2 = "world";

	stack_push(stack, (void *)s1);
	stack_push(stack, (void *)s2);

	printf("size: %d\n", stack_size(stack));
	printf("capability: %d\n", stack_capability(stack));

	char *s3;
	stack_pop(stack, (void **)&s3);
	printf("pop: %s\n", s3);

	printf("size: %d\n", stack_size(stack));
	printf("capability: %d\n", stack_capability(stack));

	stack_pop(stack, (void **)&s3);
	printf("pop: %s\n", s3);

	printf("size: %d\n", stack_size(stack));
	printf("capability: %d\n", stack_capability(stack));
}
/*
int main()
{
	test1();
}
*/
