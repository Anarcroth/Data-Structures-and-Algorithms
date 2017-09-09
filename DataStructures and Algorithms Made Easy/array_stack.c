/**
	COS: FDS
	array_stack.c
	Purpose:	Create dynamic array stack holding integers

	@author:	Martin Nestorov
	@version:	0.2.2 24/07/2017
*/

#include <stdlib.h>
#include <stdio.h>

struct array_stack
{
	int num_elements;
	int capacity;
	int *array;
	int top;
};

/** Prototypes */
static void double_stack_capacity(struct array_stack *stack);
static void display_stack(struct array_stack *stack);
static void push(struct array_stack *stack, int key);
static void delete_stack(struct array_stack *stack);

static int is_empty(struct array_stack *stack);
static int is_full(struct array_stack *stack);
static int pop(struct array_stack *stack);
static int top(struct array_stack *stack);

static struct array_stack *create_stack();

/**
	Allocate space and create a new array stack

	@return		The initial stack
*/
static struct array_stack *create_stack()
{
	struct array_stack *temp_stack = (struct array_stack*)malloc(sizeof(struct array_stack));

	if (temp_stack == NULL)
		exit(0);

	temp_stack->capacity = 1;
	temp_stack->top = -1;
	temp_stack->num_elements = 0;

	// Initial allocation is of size 1
	temp_stack->array = (int*)malloc(temp_stack->capacity * sizeof(int));
	
	if (temp_stack->array == NULL)
		exit(0);

	return temp_stack;
}

/**
	Check if stack is full

	@param *stack	Pointer to the stack structure
	@return			1 if the stack is full, 0 if it is not
*/
static int is_full(struct array_stack *stack)
{
	return stack->top == stack->capacity - 1;
}

/**
	Check if stack is empty
	
	@param *stack	Pointer to the stack structure
	@return			1 if the stack is empty, 0 if it is not	
*/
static int is_empty(struct array_stack *stack)
{
	return stack->top == -1;
}

/**
	Double stacks capacity
	
	@param *stack	Pointer to the stack structure
*/
static void double_stack_capacity(struct array_stack *stack)
{
	stack->capacity *= 2;
	stack->array = (int*)realloc(stack->array, stack->capacity * sizeof(int));
}

/**
	Push an element on the top of the stack array

	@param *stack	Pointer to the stack structure
	@param key		The value that is pushed on top
*/
static void push(struct array_stack *stack, int key)
{
	if (is_full(stack))
		double_stack_capacity(stack);

	stack->num_elements++;
	stack->array[++stack->top] = key;
}

/**
	Get the value at the top of stack

	@param *stack	Pointer to the stack structure
	@return			The top element of the stack
*/
static int top(struct array_stack *stack)
{
	if (is_empty(stack)) 
	{
		printf("The stack is empty.");

		return 0;
	}

	return stack->array[stack->top];
}

/**
	Remove the top value of the stack

	@param *stack	Pointer to the stack structure
	@return			Remove the top value of the stack and return it
*/
static int pop(struct array_stack *stack)
{
	if (is_empty(stack))
	{
		printf("The stack is empty.");

		return 0;
	}

	stack->num_elements--;

	return stack->array[stack->top--];
}

/**
	Display the contents of stack

	@param *stack	Pointer to the strack structure
*/
static void display_stack(struct array_stack *stack)
{
	if (!is_empty(stack))
	{
		printf("Stack: ");

		for (int elem = stack->num_elements - 1; elem > -1; elem--)
			printf("%d ", stack->array[elem]);

		printf("\n");
	}
}

/**
	Delete the whole stack structure

	@param *stack	Pointer to the stack structure
*/
static void delete_stack(struct array_stack *stack)
{
	if (!is_empty(stack))
		if (stack->array)
			free(stack->array);
		
	free(stack);
}
/*
int main(void)
{
	struct array_stack *stack = NULL;

	int answer = 0, elem = 0;

	printf("----- Array Stack Menu -----\n");

	printf("1. Push new element to stack.\n");
	printf("2. Pop top of stack.\n");
	printf("3. Display contents of stack.\n");
	printf("4. Look at the top of stack.\n");
	printf("5. Quit.\n");
	
	stack = create_stack();

	do 
	{
		printf("Take action: ");
		scanf("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf("%d", &elem);

			push(&*stack, elem);
			break;

		case 2:
			elem = pop(&*stack);
			
			if (!is_empty(&*stack))
				printf("The poped element is: %d\n", elem);
			
			break;

		case 3:
			display_stack(&*stack);
			break;
			
		case 4:
			printf("The top element is: %d\n", top(&*stack));
			break;

		case 5:
			delete_stack(&*stack);

			exit(0);

        default:
            continue;
		}
	
	} while (answer);

	return 0;
}*/