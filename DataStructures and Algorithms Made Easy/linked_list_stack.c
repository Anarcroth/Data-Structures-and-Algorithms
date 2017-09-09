/**
	COS: FDS  
	linked_list_stack.c
	Purpose:	Create linked list stack holding integers

	@author:	Martin Nestorov
	@version:	0.2.2 24/07/2017
*/

#include <stdlib.h>
#include <stdio.h>

struct node 
{
	struct node *next;
	int key;
};

/** Prototypes */
static struct node* pop(struct node *stack, int *element);
static struct node* push(struct node *stack, int key);

static void display_stack(struct node *stack);
static void delete_stack(struct node *stack);

static int is_empty(struct node *stack);
static int top(struct node *stack);

/**
	Allocates space and pushes new node element on top of stack 

	@param *top		Pointer to the top of the stack
	@param key		The value that is pushed on top
	@return			Pointer to the new top of the stack
*/
static struct node* push(struct node *stack, int key)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));

	if (temp == NULL)
		exit(0);

	temp->key = key;
	temp->next = stack;

	stack = temp;

	return stack;
}

/**
	Get the key from the top of the stack

	@param *top		Pointer to the top of the stack
	@return			The key at the top of stack
*/
static int top(struct node *stack)
{
	return stack->key;
}

/**
	Popes the top node of the stack and assigns the top	element of the stack to the element varaible
	
	@param *top		Pointer to the top of the stack
	@param *element	Pointer to the element that will hold the top key of the stack
	@return			Pointer to the new top of the stack
*/
static struct node* pop(struct node *stack, int *element)
{
	if (is_empty(stack))
	{
		printf("The Stack is empty.\n");

		return NULL;
	}

	*element = stack->key;
	stack = stack->next;

	return stack;
}

/**
	Display the whole contents of the stack

	@param *top		Pointer to the top of the stack
	@return			No return value, display a string if the stack is empty
*/
static void display_stack(struct node *stack)
{
	if (!is_empty(stack))
	{
		printf("Stack: ");
	
		do
		{
			printf("%d ", stack->key);
			stack = stack->next;

		} while (stack != NULL);
		
		printf("\n");
	}
	else
		printf("The Stack is is empty.\n");

}

/**
	Check if the stack is empty

	@param *top		Pointer to the top of the stack
	@return			1 if the stack is empty, 0 if it is not
*/
static int is_empty(struct node *stack)
{
	return stack == NULL;
}

/**
	Delete the whole stack structure

	@param *top		Pointer to the top of the stack
*/
static void delete_stack(struct node *stack)
{
	if (!is_empty(stack))
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));

		if (temp == NULL)
			exit(0);

		while (stack->next != NULL)
		{
			temp = stack;
			stack = stack->next;
		}

		free(temp);
	}

	free(stack);
}
/*
int main(void)
{
	struct node *stack = NULL;

	int answer = 0, elem = 0;

	printf("----- Linked List Stack Menu -----\n");

	printf("1. Push new element to stack.\n");
	printf("2. Pop top of stack.\n");
	printf("3. Display contents of stack.\n");
	printf("4. Look at the top of stack.\n");
	printf("5. Quit.\n");

	do 
	{
		printf("Take action: ");
		scanf("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf("%d", &elem);

			stack = push(&*stack, elem);
			break;

		case 2:
			stack = pop(&*stack, &elem);
			
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
		}
	
	} while (answer);

	return 0;
}*/