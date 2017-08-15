/**
	COS: FDS
	linked_list_queue.c
	Purpose: Create linked list queue holding integers
	
	@author:	Martin Nestorov
	@version:	0.1.0 12.08.2017
*/

#include <stdio.h>

struct node
{
	int key;
	struct node *next;
};

struct queue
{
	int num_elements;

	struct node *front;
	struct node *end;
};

/** Prototypes */
static struct queue *create_queue();

static struct node *create_new_node(int key);
static int de_queue(struct queue *q);

static void en_queue(struct queue *q, int key);
static void delete_queue(struct queue *q);

static int is_empty(struct queue *q);

static struct queue *create_queue()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));

	if (q == NULL)
		return NULL;
	
	q->front = q->end = NULL;

	q->num_elements == 0;

	return q;
}

static struct node *create_new_node(int key)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	temp->key = key;
	temp->next = NULL;

	return temp;
}

static int is_empty(struct queue *q)
{
	return q->end == NULL;
}

static void en_queue(struct queue *q, int key)
{
	struct node *temp = create_new_node(key);

	if (is_empty(q))
	{
		q->front = q->end = temp;

		q->num_elements++;

		return;
	}

	q->end->next = temp;
	q->end = temp;

	q->num_elements++;
}

static int de_queue(struct queue *q)
{
	if (is_empty(q))
	{
		printf("Queue is empty");
		return 0;
	}

	struct node* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL)
		q->end == NULL;

	q->num_elements--;

	return temp->key;
}

static void delete_queue(struct queue *q)
{
	struct node *temp;

	while (!is_empty(q))
	{
		temp = q;
		q = q->front;
		free(temp);
	}

	free(q);
}

static void display_queue(struct queue *q)
{
	struct node *temp;
	
	while (q->num_elements > 0)
	{
		temp = q;

		q = q->end->next;

		printf("%d ", temp->key);

		q->num_elements--;
	}
}

int main()
{
	struct queue *que = create_queue();

	int answer = 0, elem = 0;

	printf("----- Linked List Queue Menu -----\n");

	printf("1. EnQueue new element to queue.\n");
	printf("2. DeQueue end of queue.\n");
	printf("3. Display contents of queue.\n");
	printf("4. Look at the front of queue.\n");
	printf("5. Quit.\n");

	do
	{
		printf("Take action: ");
		scanf_s("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf_s("%d", &elem);

			en_queue(&*que, elem);
			break;

		case 2:
			elem = de_queue(&*que);

			if (!is_empty(&*que))
				printf("The DeQueued element is: %d\n", elem);

			break;

		case 3:
			display_queue(que);
			break;

		case 4:
			//printf("The top element is: %d\n", top(&*que));
			break;

		case 5:
			delete_queue(&*que);

			exit(0);
		}

	} while (answer);

	return 0;
}