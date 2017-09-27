/**
	COS: FDS
	linked_list_queue.c
	Purpose: 	Create linked list queue holding integers
	
	@author:	Martin Nestorov
	@version:	0.1.3 12.08.2017
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

struct queue
{
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
    struct queue *que = (struct queue *) malloc(sizeof(struct queue));

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

    temp = (struct node *) malloc(sizeof(struct node));

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
}
/*
int main()
{
	struct queue *queue;

	int answer = 0, elem = 0;

	printf("----- Linked List Queue Menu -----\n");

	printf("1. EnQueue new element to queue.\n");
	printf("2. DeQueue end of queue.\n");
	printf("3. Display contents of queue.\n");
	printf("4. Quit.\n");

	queue = create_queue();

	do
	{
		printf("Take action: ");
		scanf("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf("%d", &elem);

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

		default:
			continue;
		}

	} while (answer);

	return 0;
}*/