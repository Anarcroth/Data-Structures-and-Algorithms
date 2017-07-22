#include <iostream>

struct node
{
	int key;
	node *next;
};

struct queue
{
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
		printf("%s", "Queue is empty");
		return 0;
	}
	else
	{
		temp = q->front;
		key = q->front->key;
		q->front == q->front->next;
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
}
/*
int main()
{

	return 0;
}*/