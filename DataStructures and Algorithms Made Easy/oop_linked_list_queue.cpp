/**
	COS: FDS
	oop_linked_list.cpp
	Purpose: 	Create a dynamic object oriented linked list queue

<<<<<<< HEAD
	@author: 	Martin Nestorov
	@version: 	0.1.0 15/08/2017
=======
	@author: Martin Nestorov
	@version: 0.1.2 15/08/2017

>>>>>>> feature/binary-tree
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
<<<<<<< HEAD
	Queue();
	~Queue();

	void en_queue(int key);
	void de_queue();
	void display_queue();

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
	
		front = end = temp;
	
	else
	{
		end->next = temp;
		end = temp;
	}

	delete temp;
=======
	Queue()=default;
	~Queue();

	void en_queue(int key);
	void display_queue();
	void delete_queue();
	void de_queue();

private:
	node *front{}, *end{};
};

void Queue::en_queue(int key)
{
	auto *temp = new node;

	temp->key = key;
	temp->next = nullptr;

	if (front == nullptr)
		front = temp;
	
	else
		end->next = temp;
	
	end = temp;
>>>>>>> feature/binary-tree
}

void Queue::de_queue()
{
<<<<<<< HEAD
	if (front == NULL)
=======
	if (front == nullptr)
>>>>>>> feature/binary-tree
	
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
	
>>>>>>> feature/binary-tree
		delete temp;
	}
}

void Queue::display_queue()
{
	node *temp;

<<<<<<< HEAD
	if (front == NULL)
=======
	if (front == nullptr)
>>>>>>> feature/binary-tree
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		temp = front;

<<<<<<< HEAD
		while (temp->next != NULL)
=======
		std::cout << "front-> ";

		while (temp->next != nullptr)
>>>>>>> feature/binary-tree
		{
			std::cout << temp->key << " ";

			temp = temp->next;
		}

<<<<<<< HEAD
		std::cout << std::endl;
	}
}

Queue::~Queue()
{
}

int main(void)
=======
		std::cout << temp->key << " ->end\n";
	}
}

void Queue::delete_queue()
{
	if (front != nullptr)
	{
		auto *temp = new node;

		while (front != nullptr)
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
/*
int main()
>>>>>>> feature/binary-tree
{
	Queue queue;

	int answer = 0, elem = 0;

<<<<<<< HEAD
	printf("----- Linked List Queue Menu -----\n");

	printf("1. EnQueue new element to queue.\n");
	printf("2. DeQueue end of queue.\n");
	printf("3. Display contents of queue.\n");
	printf("4. Quit.\n");

	do
	{
		printf("Take action: ");
		scanf_s("%d", &answer);
=======
	std::cout << "----- Linked List Queue Menu -----\n";

	std::cout << "1. EnQueue new element to queue.\n";
	std::cout << "2. DeQueue end of queue.\n";
	std::cout << "3. Display contents of queue.\n";
	std::cout << "4. Quit.\n";

	do
	{
		std::cout << "Take action: ";
		std::cin >> answer;
>>>>>>> feature/binary-tree

		switch (answer)
		{
		case 1:
<<<<<<< HEAD
			printf("Enter an element: ");
			scanf_s("%d", &elem);

			queue.en_queue(elem);
=======
		std::cout << "Enter an element: ";
			std::cin >> elem;

			queue.en_queue(elem);

>>>>>>> feature/binary-tree
			break;

		case 2:
			queue.de_queue();

			break;

		case 3:
			queue.display_queue();
			break;

		case 4:
			exit(0);
<<<<<<< HEAD
		}

	} while (answer);

	return 0;
}
=======

		default:
			continue;
		}

	} while ((bool)answer);

	return 0;
}*/
>>>>>>> feature/binary-tree
