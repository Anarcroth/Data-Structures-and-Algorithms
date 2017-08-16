<<<<<<< HEAD
/**
	COS: FDS
	linked_list_queue.c
	Purpose: 	Create linked list queue holding integers
	
	@author:	Martin Nestorov
	@version:	0.1.3 12.08.2017
*/

=======
>>>>>>> 1384c68... Added stack files
#include <stdio.h>

struct node
{
	int key;
<<<<<<< HEAD
	struct node *next;
=======
	node *next;
>>>>>>> 1384c68... Added stack files
};

struct queue
{
<<<<<<< HEAD
	struct node *front;
	struct node *end;
};

/** Prototypes */
static struct queue *en_queue(struct queue *que, int key);
static struct queue *de_queue(struct queue *que);
static struct queue *create_queue();

static void display_queue(struct queue *que);
static void delete_queue(struct queue *que);

/**
	Initialize the beginning of the queue
*/
static struct queue *create_queue()
{
	struct queue *que = (struct queue*)malloc(sizeof(struct queue));

	if (que == NULL)
		exit(0);

	que->end = NULL;
	que->front = NULL;

	return que;
}

/**
	Append a new element to the end of the queue

	@param *que		A pointer to the queue structure.
	@param key		The value to be en queued.
	@return			The pointer to the queue.
*/
static struct queue *en_queue(struct queue *que, int key)
{
	struct node *temp;

	temp = (struct node*)malloc(sizeof(struct node));

	temp->key = key;
	temp->next = NULL;
	
	if (que->front == NULL)
	
		que->front = que->end = temp;
	
	else 
	{
		que->end->next = temp;
		que->end = temp;
	}

	return que;
}

/**
	Remove an element at the front of the queue

	@param *que		A pointer to the queue structure.
	@return			The pointer to the queue.
*/
static struct queue *de_queue(struct queue *que)
{
	if (que->front == NULL)
	
		printf("The Queue is Empty!\n");
	
	else
	{
		struct node *temp = que->front;
		que->front = que->front->next;

		printf("The de queued element is: %d\n", temp->key);

		free(temp);
	}

	return que;
}

/**
	Delete the whole queue structure

	@param *que		A pointer to the queue structure.
*/
static void delete_queue(struct queue *que)
{
	struct node *temp;

	while (que->front != NULL)
	{
		temp = que->front;
		que->front = que->front->next;

		free(temp);
	}

	free(que);
}

/**
	Display the whole queue structure

	@param *que		A pointer to the queue structure.
*/
static void display_queue(struct queue *que)
{
	struct node *temp;

	if (que->front == NULL)

		printf("The Queue is Empty!\n");

	else 
	{
		temp = que->front;
		
		while (temp->next != NULL) 
		{
			printf("%d--->", temp->key);
			
			temp = temp->next;
		}

		printf("%d--->NULL\n", temp->key);
	}
=======
	node *front;
	node *end;
};

queue *create_queue()
{
	queue *q;
	node *temp;

	q = (queue*)malloc(sizeof(queue));

	if (!q)
		return NULL;

	temp = (node*)malloc(sizeof(node));

	q->front = q->end = NULL;

	return q;
}

int is_queue_empty(queue *q)
{
	return q->end == NULL;
}

void en_queue(queue *q, int key)
{
	node *new_node;

	new_node = (node*)malloc(sizeof(node));

	if (!new_node)
		NULL;

	new_node->key = key;
	new_node->next = NULL;
	
	if (!q->end) q->end->next = new_node;

	q->end = new node;

	if (q->front == NULL)
		q->front = q->end;
}

int de_queue(queue *q)
{
	int key = 0;
	
	node* temp;
	
	if (is_queue_empty(q))
	{
		std::cout << "%s", "Queue is empty";
		return 0;
	}
	else
	{
		temp = q->front;
		key = q->front->key;
		q->front = q->front->next;
		free(temp);
	}

	return key;
}

void delete_queue(queue *q)
{
	node *temp;

	while (q)
	{
		temp = (node*)q;
		q = (queue*)q->front;
		free(temp);
	}

	free(q);
>>>>>>> 1384c68... Added stack files
}
/*
int main()
{
<<<<<<< HEAD
	struct queue *queue;

	int answer = 0, elem = 0;

	printf("----- Linked List Queue Menu -----\n");

	printf("1. EnQueue new element to queue.\n");
	printf("2. DeQueue end of queue.\n");
	printf("3. Display contents of queue.\n");
	printf("4. Quit.\n");

	queue = create_queue(&queue);

	do
	{
		printf("Take action: ");
		scanf_s("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf_s("%d", &elem);

			queue = en_queue(&*queue, elem);
			break;

		case 2:
			queue = de_queue(&*queue);

			break;

		case 3:
			display_queue(&*queue);
			break;

		case 4:
			delete_queue(&*queue);
			exit(0);
		}

	} while (answer);
=======
>>>>>>> 1384c68... Added stack files

	return 0;
}*/