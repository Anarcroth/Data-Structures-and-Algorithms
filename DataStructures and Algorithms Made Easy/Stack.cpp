#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct node 
{
	node *next;
	int key;
};

void init(node *top)
{
	top = NULL;
}

node* push(node *head, int key)
{
	node *temp = (node*)malloc(sizeof(node));

	if (temp == NULL)
		exit(0);

	temp->key = key;
	temp->next = head;

	head = temp;

	return head;
}

node* pop(node *head, int *element)
{
	*element = head->key;
	head = head->next;

	return head;
}

void display(struct node* head)
{
	struct node *current;
	current = head;

	if (current != NULL)
	{
		printf("Stack: ");
		do
		{
			printf("%d ", current->key);
			current = current->next;
		} while (current != NULL);
		printf("\n");
	}
	else
	{
		printf("The Stack is empty\n");
	}

}

bool empty(node *head)
{
	return head == NULL;
}

int main()
{
	struct node* head = NULL;
	int size, element;
	int counter = 0;

	printf("Enter the number of stack elements:");
	scanf_s("%d", &size);

	printf("--- Push elements into the linked stack ---\n");

	init(head);

	while (counter < size)
	{

		printf("Enter a number to push into the stack:");
		scanf_s("%d", &element);
		head = push(head, element);
		display(head);
		counter++;
	}

	printf("--- Pop elements from the linked stack --- \n");
	while (empty(head) == 0)
	{
		head = pop(head, &element);
		printf("Pop %d from stack\n", element);
		display(head);
	}


	int z;

	std::cin >> z;

	return 0;
}