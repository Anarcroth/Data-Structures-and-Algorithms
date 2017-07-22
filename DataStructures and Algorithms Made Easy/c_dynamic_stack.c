#include <stdlib.h>
#include <stdio.h>

/* Stack ADT in C */

struct node 
{
	struct node *next;
	int key;
};

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

struct node* pop(struct node *top, int *element)
{
	*element = top->key;
	top = top->next;

	return top;
}

void display_stack(struct node* top)
{
	if (top != NULL)
	{
		printf("S: ");
	
		do
		{
			printf("%d ", top->key);
			top = top->next;

		} while (top != NULL);
		
		printf("\n");
	}
	else
		printf("The Stack is is_empty\n");

}

int is_empty(struct node *top)
{
	return top == NULL;
}

int main()
{
	struct node* top = NULL;
	int size, element;
	int counter = 0;

	printf("Enter the number of stack elements:");
	scanf_s("%d", &size);

	printf("--- Push elements into the linked stack ---\n");

	while (counter < size)
	{

		printf("Enter a number to push into the stack:");
		scanf_s("%d", &element);
		top = push(top, element);
		display_stack(top);
		counter++;
	}

	printf("--- Pop elements from the linked stack --- \n");
	while (is_empty(top) == 0)
	{
		top = pop(top, &element);
		printf("Pop %d from stack\n", element);

		display_stack(&top);
	}


	int z;
	
	scanf_s("%d", z);

	return 0;
}