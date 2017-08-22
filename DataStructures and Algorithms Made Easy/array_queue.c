#include <stdio.h>

struct queue
{
	int front, end;
	int capacity;
	int *array;
};

static void double_queue_capacity(struct queue *que);
static void en_queue(struct queue *que, int value);
static void display_queue(struct queue *que);
static void delete_queue(struct queue *que);
static void de_queue(struct queue *que);

static struct queue *create_queue();

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

static void en_queue(struct queue *que, int value)
{
	if (que->end == que->capacity - 1)

		double_queue_capacity(&*que);

	if (que->front == -1)
		que->front = 0;

	que->end++;
	que->array[que->end] = value;

	return que;
}

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

	return que;
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

int main(void)
{
	struct queue *queue;

	int answer = 0, elem = 0;

	printf("----- Array Queue Menu -----\n");

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
		}

	} while (answer);

	return 0;
}