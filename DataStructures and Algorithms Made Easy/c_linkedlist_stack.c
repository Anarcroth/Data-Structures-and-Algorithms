#include <stdlib.h>
#include <stdio.h>

/* Stack ADT in C */

struct node 
{
	struct node *next;
	int key;
};

/* Allocate space and push new node on top of stack */
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

/* Remove and return the key at the top of the stack
and then set the top of the stack to the next node */
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

int is_empty(struct node *top)
{
	return top == NULL;
}

int main()
{
	struct node* top = NULL;
	int answer = 0, elem = 0;

	printf("----- Menu -----\n");

	printf("1. Push new element to stack.\n");
	printf("2. Pop top of stack.\n");
	printf("3. Display contents of stack.\n");
	printf("4. quit.\n");

	do {
		printf("Take action: ");
		scanf_s("%u", answer);

		printf("Enter an element: ");
		scanf_s("%d", &elem);

		switch (answer)
		{
		case 1:
			top = push(top, elem);
			break;
		case 2:
			top = pop(top, &elem);
			break;
		case 3:
			display_stack(top);
			break;
		case 4:
			exit(0);
			break;
		}
	
	} while (answer);

	return 0;
}