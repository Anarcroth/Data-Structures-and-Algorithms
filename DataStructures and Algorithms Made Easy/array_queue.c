#include <stdio.h>

struct queue
{
	int size;
	int *array;
	int front, end;
};

struct queue *create_queue()
{
	struct queue *que = (struct queue*)malloc(sizeof(struct queue));

	if (que == NULL)
		exit(0);

	que->size = 1;
	que->front = que->end = -1;
	que->array = (int)malloc(sizeof(int) * que->size);

	if (que->array == NULL)
		exit(0);

	return que;
}

int is_empty(struct queue *que)
{
	return que->front == -1;
}

int is_full(struct queue *que)
{
	return (que->end + 1) % que->size == que->front;
}

void en_queue(struct queue *que)
{
	if (que->end == que->size - 1)
	{

	}
}