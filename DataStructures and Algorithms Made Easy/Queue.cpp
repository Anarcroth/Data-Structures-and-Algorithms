#include <iostream>

struct node
{
	node *next;
	int key;
};

class Queue
{
public:
	Queue();
	
	~Queue();
	
	void insert_key(int key);
	node search_key(int key);
	void create_queue(int key);

private:
	node *en_queue = NULL;
	node *de_queue = NULL;

	void insert_key(node* next, int key);
	node search_key(node* next, int key);
};

Queue::Queue()
{
}

Queue::~Queue()
{
}

void Queue::create_queue(int key)
{
	if (en_queue == NULL)
	{
		en_queue = new node;
		en_queue->key = key;
		en_queue->next = NULL;
	}
}

void Queue::insert_key(int key)
{
	node *temp;

	if (en_queue != NULL)
	{
		//while ()
	}
}

int main()
{

}