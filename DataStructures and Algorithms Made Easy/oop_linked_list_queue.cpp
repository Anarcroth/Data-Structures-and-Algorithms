/**
	COS: FDS
	oop_linked_list.cpp
	Purpose: 	Create a dynamic object oriented linked list queue

	@author: Martin Nestorov
	@version: 0.1.2 15/08/2017

*/

#include <iostream>

struct node
{
	int key;
	node *next;
};

class Queue
{
public:
	Queue();
	~Queue();

	void en_queue(int key);
	void display_queue();
	void delete_queue();
	void de_queue();

private:
	node *front;
	node *end;
};

Queue::Queue() : front(NULL), end(NULL)
{
}

void Queue::en_queue(int key)
{
	node *temp = new node;

	temp->key = key;
	temp->next = NULL;

	if (front == NULL)
		front = temp;
	
	else
		end->next = temp;
	
	end = temp;
}

void Queue::de_queue()
{
	if (front == NULL)
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		node *temp = front;

		front = front->next;

		std::cout << "The de queued element is: " << temp->key << std::endl;
	
		delete temp;
	}
}

void Queue::display_queue()
{
	node *temp;

	if (front == NULL)
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		temp = front;

		std::cout << "front-> ";

		while (temp->next != NULL)
		{
			std::cout << temp->key << " ";

			temp = temp->next;
		}

		std::cout << temp->key << " ->end\n";
	}
}

void Queue::delete_queue()
{
	if (front != NULL)
	{
		node *temp = new node;

		while (front != NULL)
		{
			temp = front;

			front = front->next;

			delete temp;
		}

		delete front;
	}
}

Queue::~Queue()
{
	delete_queue();
}

int main(void)
{
	Queue queue;

	int answer = 0, elem = 0;

	printf("----- Linked List Queue Menu -----\n");

	printf("1. EnQueue new element to queue.\n");
	printf("2. DeQueue end of queue.\n");
	printf("3. Display contents of queue.\n");
	printf("4. Quit.\n");

	do
	{
		printf("Take action: ");
		scanf_s("%d", &answer);

		switch (answer)
		{
		case 1:
			printf("Enter an element: ");
			scanf_s("%d", &elem);

			queue.en_queue(elem);

			break;

		case 2:
			queue.de_queue();

			break;

		case 3:
			queue.display_queue();
			break;

		case 4:
			exit(0);
		}

	} while (answer);

	return 0;
}