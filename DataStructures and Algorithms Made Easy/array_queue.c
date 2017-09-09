<<<<<<< HEAD
<<<<<<< HEAD
=======
#include <stdio.h>
=======
/**
	COS: FDS
	array_queue.c
	Purpose:	Create dynamic array queue holding integers

	@author:	Martin Nestorov
	@version:	0.2.2 21/08/2017
*/

#include <stdio.h>
#include <stdlib.h>
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

struct queue
{
	int front, end;
	int capacity;
	int *array;
};

<<<<<<< HEAD
=======
/** Prototypes */
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
static void double_queue_capacity(struct queue *que);
static void en_queue(struct queue *que, int value);
static void display_queue(struct queue *que);
static void delete_queue(struct queue *que);
static void de_queue(struct queue *que);

static struct queue *create_queue();

<<<<<<< HEAD
=======
/**
	Allocate memory for the queue

	@return	A pointer to the initial queue structure.
*/
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
static struct queue *create_queue()
{
	struct queue *que = (struct queue*)malloc(sizeof(struct queue));

	if (que == NULL)
		exit(0);

	que->front = que->end = -1;
	que->capacity = 1;

	que->array = (int*)malloc(que->capacity * sizeof(int));

	if (que->array == NULL)
		exit(0);

	return que;
}

static void double_queue_capacity(struct queue *que)
{
	que->capacity *= 2;
	que->array = (int*)realloc(que->array, que->capacity * sizeof(int));
}

<<<<<<< HEAD
static void en_queue(struct queue *que, int value)
{
	if (que->end == que->capacity - 1)

=======
/**
	Insert a new element to the end of the queue

	@param *que		A pointer to the original queue structure.
	@param value	The value to be inserted.
*/
static void en_queue(struct queue *que, int value)
{
	if (que->end == que->capacity - 1)
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		double_queue_capacity(&*que);

	if (que->front == -1)
		que->front = 0;

	que->end++;
	que->array[que->end] = value;
<<<<<<< HEAD

	return que;
}

=======
}

/**
	Remove the front element of the queue

	@param *que		A pointer to the original queue structure.
*/
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
static void de_queue(struct queue *que)
{
	if (que->front == que->end)

		printf("Queue is Empty.\n");

	else 
	{
		printf("Deleted: %d\n", que->array[que->front]);

		que->front++;

		if (que->front == que->end)
			que->front = que->end = -1;
	}
<<<<<<< HEAD

	return que;
=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
}

static void display_queue(struct queue *que) 
{
	if (que->end == -1)

		printf("Queue is Empty.\n");

	else 
	{
		int i;

		printf("Queue elements are: ");

		for (i = que->front; i <= que->end; i++)
			printf("%d ", que->array[i]);

		printf("\n");
	}
}

static void delete_queue(struct queue *que)
{
	if(que->end != que->capacity -1)
		if (que->array)
			free(que->array);

	free(que);
}
<<<<<<< HEAD

int main(void)
=======
/*
int main()
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
{
	struct queue *queue;

	int answer = 0, elem = 0;

	printf("----- Array Queue Menu -----\n");

	printf("1. EnQueue new element to queue.\n");
	printf("2. DeQueue end of queue.\n");
	printf("3. Display contents of queue.\n");
	printf("4. Quit.\n");

<<<<<<< HEAD
	queue = create_queue(&queue);
=======
	queue = create_queue();
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

	do
	{
		printf("Take action: ");
<<<<<<< HEAD
		scanf_s("%d", &answer);
=======
		scanf("%d", &answer);
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
<<<<<<< HEAD
			scanf_s("%d", &elem);
=======
			scanf("%d", &elem);
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

			en_queue(&*queue, elem);
			break;

		case 2:
			de_queue(&*queue);

			break;

		case 3:
			display_queue(&*queue);
			break;

		case 4:
			delete_queue(&*queue);

			exit(0);
<<<<<<< HEAD
=======

		default:
			continue;
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		}

	} while (answer);

	return 0;
<<<<<<< HEAD
}
>>>>>>> bbf3e3e... Added array queue implementation
=======
}*/
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
