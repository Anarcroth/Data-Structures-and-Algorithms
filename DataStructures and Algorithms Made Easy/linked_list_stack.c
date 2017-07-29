/**
	COS: FDS  
	linked_list_stack.c
	Purpose:	Create linked list stack holding integers

	@author:	Martin Nestorov
	@version:	0.2 24/07/2017
*/

#include <stdlib.h>
#include <stdio.h>

struct node 
{
	struct node *next;
	int key;
};

// Prototypes
struct node* pop(struct node *top, int *element);
struct node* push(struct node *top, int key);

void display_stack(struct node *top);
void delete_stack(struct node *top);

int is_empty(struct node *top);
int top(struct node *top);

/**
	Allocates space and pushes new node element on top of stack. 

	@param *top		Pointer to the top of the stack.
	@param key		The value that is pushed on top.
	@return			Pointer to the new top of the stack.
*/
struct node* push(struct node *top, int key)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));

	if (temp == NULL)
		exit(0);

	temp->key = key;
	temp->next = top;

	top = temp;

	return top;
}

/**
	Get the key from the top of the stack.

	@param *top		Pointer to the top of the stack.
	@return			The key at the top of stack.
*/
int top(struct node *top)
{
	return top->key;
}

/**
	Popes the top node of the stack and assigns the top
	element of the stack to the element varaible.
	
	@param *top		Pointer to the top of the stack.
	@param *element	Pointer to the element that will hold the top key of the stack.
	@return			Pointer to the new top of the stack.
*/
struct node* pop(struct node *top, int *element)
{
	if (is_empty(top))
	{
		printf("The Stack is empty.\n");

		return NULL;
	}

	*element = top->key;
	top = top->next;

	return top;
}

/**
	Display the whole contents of the stack.

	@param *top		Pointer to the top of the stack.
	@return			No return value, display a string if the stack is empty.
*/
void display_stack(struct node *top)
{
	if (!is_empty(top))
	{
		printf("Stack: ");
	
		do
		{
			printf("%d ", top->key);
			top = top->next;

		} while (top != NULL);
		
		printf("\n");
	}
	else
		printf("The Stack is is empty.\n");

}

/**
	Check if the stack is empty.

	@param *top		Pointer to the top of the stack.
	@return			1 if the stack is empty, 0 if it is not.
*/
int is_empty(struct node *top)
{
	return top == NULL;
}

/**
	Delete the whole stack structure.

	@param *top		Pointer to the top of the stack.
	@noreturn
*/
void delete_stack(struct node *top)
{
	if (!is_empty(top))
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));

		if (temp == NULL)
			exit(0);

		while (top->next != NULL)
		{
			temp = top;
			top = top->next;
		}

		free(temp);
	}

	free(top);
}

int main(void)
{
	struct node *top = NULL;

	int answer = 0, elem = 0;

	printf("----- Menu -----\n");

	printf("1. Push new element to stack.\n");
	printf("2. Pop top of stack.\n");
	printf("3. Display contents of stack.\n");
	printf("4. quit.\n");

	do 
	{
		printf("Take action: ");
		scanf_s("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf_s("%d", &elem);

			top = push(top, elem);
			break;

		case 2:
			top = pop(top, &elem);
			
			if (!is_empty(top))
				printf("The poped element is: %d\n", elem);
			
			break;

		case 3:
			display_stack(top);
			break;

		case 4:
			delete_stack(top);

			exit(0);
			break;
		}
	
	} while (answer);

	return 0;
}