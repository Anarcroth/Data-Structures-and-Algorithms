/**
	COS: FDS
	oop_linked_list.cpp
	Purpose: 	Create a dynamic object oriented linked list queue

<<<<<<< HEAD
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
=======
	@author: Martin Nestorov
	@version: 0.1.2 15/08/2017

>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
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
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		front = temp;
	
	else
		end->next = temp;
	
	end = temp;
<<<<<<< HEAD
=======
	
		front = end = temp;
	
	else
	{
		end->next = temp;
		end = temp;
	}

	delete temp;
>>>>>>> 1384c68... Added stack files
=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
}

void Queue::de_queue()
{
<<<<<<< HEAD
	if (front == NULL)
=======
	if (front == nullptr)
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		node *temp = front;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

		front = front->next;

		std::cout << "The de queued element is: " << temp->key << std::endl;
	
<<<<<<< HEAD
=======
		front = front->next;

		std::cout << "The de queued element is: " << temp->key << std::endl;

>>>>>>> 1384c68... Added stack files
=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
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
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		temp = front;

<<<<<<< HEAD
<<<<<<< HEAD
		std::cout << "front-> ";

=======
>>>>>>> 1384c68... Added stack files
		while (temp->next != NULL)
=======
		std::cout << "front-> ";

		while (temp->next != nullptr)
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		{
			std::cout << temp->key << " ";

			temp = temp->next;
		}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		std::cout << temp->key << " ->end\n";
	}
}

void Queue::delete_queue()
{
<<<<<<< HEAD
	if (front != NULL)
	{
		node *temp = new node;

		while (front != NULL)
=======
	if (front != nullptr)
	{
		auto *temp = new node;

		while (front != nullptr)
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		{
			temp = front;

			front = front->next;

			delete temp;
		}

		delete front;
<<<<<<< HEAD
=======
		std::cout << std::endl;
>>>>>>> 1384c68... Added stack files
=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
	}
}

Queue::~Queue()
{
<<<<<<< HEAD
<<<<<<< HEAD
	delete_queue();
}
/*
=======
}

>>>>>>> 1384c68... Added stack files
int main(void)
=======
	delete_queue();
}
/*
int main()
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
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
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

		switch (answer)
		{
		case 1:
<<<<<<< HEAD
			printf("Enter an element: ");
			scanf_s("%d", &elem);

			queue.en_queue(elem);
<<<<<<< HEAD

=======
>>>>>>> 1384c68... Added stack files
=======
		std::cout << "Enter an element: ";
			std::cin >> elem;

			queue.en_queue(elem);

>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
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
<<<<<<< HEAD
}*/
=======
}
>>>>>>> 1384c68... Added stack files
=======

		default:
			continue;
		}

	} while ((bool)answer);

	return 0;
}*/
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
