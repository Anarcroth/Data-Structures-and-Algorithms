/**
	COS: FDS
	oop_linked_list.cpp
	Purpose: 	Create a dynamic object oriented linked list queue

<<<<<<< HEAD
<<<<<<< HEAD
	@author: Martin Nestorov
	@version: 0.1.2 15/08/2017
=======
	@author: 	Martin Nestorov
	@version: 	0.1.0 15/08/2017
>>>>>>> 052aeeb... Fix branch files and structure
=======
	@author: 	Martin Nestorov
	@version: 	0.1.0 15/08/2017
>>>>>>> 1384c68... Added stack files
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
<<<<<<< HEAD
	void display_queue();
	void delete_queue();
	void de_queue();
=======
	void de_queue();
	void display_queue();
>>>>>>> 1384c68... Added stack files

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
<<<<<<< HEAD
		front = temp;
	
	else
		end->next = temp;
	
	end = temp;
=======
	
		front = end = temp;
	
	else
	{
		end->next = temp;
		end = temp;
	}

	delete temp;
>>>>>>> 1384c68... Added stack files
}

void Queue::de_queue()
{
	if (front == NULL)
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		node *temp = front;
<<<<<<< HEAD

		front = front->next;

		std::cout << "The de queued element is: " << temp->key << std::endl;
	
=======
		front = front->next;

		std::cout << "The de queued element is: " << temp->key << std::endl;

>>>>>>> 1384c68... Added stack files
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

<<<<<<< HEAD
		std::cout << "front-> ";

=======
>>>>>>> 1384c68... Added stack files
		while (temp->next != NULL)
		{
			std::cout << temp->key << " ";

			temp = temp->next;
		}

<<<<<<< HEAD
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
=======
		std::cout << std::endl;
>>>>>>> 1384c68... Added stack files
	}
}

Queue::~Queue()
{
<<<<<<< HEAD
	delete_queue();
}
/*
=======
}

>>>>>>> 1384c68... Added stack files
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
<<<<<<< HEAD

=======
>>>>>>> 1384c68... Added stack files
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
<<<<<<< HEAD
}*/
=======
}
>>>>>>> 1384c68... Added stack files
