#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 10

struct ArrStack
{
	int top;
	int capacity;
	int *array;
};

ArrStack *create_stack()
{
	// Allocate space for the whole ADT
	struct ArrStack *AStack = (struct ArrStack*) malloc(sizeof(struct ArrStack));

	if (!AStack)
		return NULL;

	AStack->capacity = MAXSIZE;
	AStack->top = -1;
	// Allocate space for the array in the stack
	AStack->array = (int*) malloc(AStack->capacity * sizeof(int));

	if (!AStack->array)
		return NULL;

	return AStack;
}

bool stack_is_empty(struct ArrStack *S)
{
	return (S->top == -1) ? true : false;
}

bool stack_is_full(struct ArrStack *S)
{
	return (S->top == S->capacity - 1) ? true : false;
}

void push(struct ArrStack *S, int data)
{
	if (stack_is_full(S))
		printf("%sStack Overflow");
	else
		S->array[++S->top] = data;
}

int pop(struct ArrStack *S)
{
	if (stack_is_empty(S))
	{
		printf("%Stack Underflow");
		return INT_MIN;
	}
	else
		return (S->array[S->top--]);
}

int main()
{
	ArrStack *stack = create_stack();

	int num = 0;
	char answer;

	while (true)
	{
		std::cout << "Enter a number: ";
		std::cin >> num;
		push(stack, num);

		if (stack->top == MAXSIZE)
			false;
	}

	pop(stack);
	return 0;
}