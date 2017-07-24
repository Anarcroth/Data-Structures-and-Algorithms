/**
	COS: FDS
	array_stack.c
	Purpose: Create dyamic array stack holding integers

	@author: Martin Nestorov
	@version: 0.1 24/07/2017
*/

#include <stdlib.h>
#include <stdio.h>

struct array_stack
{
	int top;
	int capacity;
	int *array;
};

/**
	Allocate space and create the array stack.

	@noparam
	@return The initial stack.
*/
struct array_stack *create_stack()
{
	struct array_stack *temp_stack = (struct array_stack*)malloc(sizeof(struct array_stack));

	if (temp_stack == NULL)
		exit(0);

	temp_stack->capacity = 1;
	temp_stack->top = -1;
	// Initial allocation is of size 1
	temp_stack->array = (int)malloc(temp_stack->capacity * sizeof(int));
	
	if (temp_stack->array == NULL)
		exit(0);

	return temp_stack;
}

/**
	Check if stack is full.

	@param *stack, Pointer to the stack structure.
	@return 1 if the stack is full, 0 if it is not.
*/
int is_full(struct array_stack *stack)
{
	return stack->top == stack->capacity - 1;
}

/**
	Check if stack is empty.
	
	@param *stack, Pointer to the stack structure.
	@return 1 if the stack is empty, 0 if it is not.	
*/
int is_empty(struct array_stack *stack)
{
	return stack->top == -1;
}

/**
	Double stacks capacity.
	
	@param *stack, Pointer to the stack structure.
	@noreturn
*/
void double_stack_capacity(struct array_stack *stack)
{
	stack->capacity *= 2;
	stack->array = (int)realloc(stack->array, stack->capacity * sizeof(int));
}

/**
	Push an element on the top of the stack array.

	@param *stack, Pointer to the stack structure.
	@param key, The value that is pushed on top.
	@noreturn
*/
void push(struct array_stack *stack, int key)
{
	if (is_full(stack))
		double_stack_capacity(stack);

	stack->array[++stack->top] = key;
}

/**
	Get the value at the top of stack.

	@param *stack, Pointer to the stack structure.
	@return The top element of the stack.
*/
int top(struct array_stack *stack)
{
	if (is_empty(stack))
		return NULL;

	return stack->array[stack->top];
}

/**
	Remove the top value of the stack.

	@param *stack, Pointer to the stack structure.
	@return Remove the top value of the stack and return it.
*/
int pop(struct array_stack *stack)
{
	if (is_empty(stack))
		return NULL;

	return stack->array[stack->top--];
}

/**
	Delete the whole stack structure.

	@param *stack, Pointer to the stack structure.
	@noreturn
*/
void delete_stack(struct array_stack *stack)
{
	if (!is_empty(stack))
		if (stack->array)
			free(stack->array);
		
	free(stack);
}

/**
	Main method of the program.

	@noparam
	@return 0
*/
int main()
{
	struct array_stack *stack = NULL;

	create_stack();

	return 0;
}