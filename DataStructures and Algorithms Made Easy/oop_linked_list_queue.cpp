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
}

void Queue::de_queue()
{
	if (front == nullptr)
	
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

	if (front == nullptr)
	
		std::cout << "The Queue is empty!\n";
	
	else
	{
		temp = front;

		std::cout << "front-> ";

		while (temp->next != nullptr)
		{
			std::cout << temp->key << " ";

			temp = temp->next;
		}

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
{
	Queue queue;

	int answer = 0, elem = 0;

	std::cout << "----- Linked List Queue Menu -----\n";

	std::cout << "1. EnQueue new element to queue.\n";
	std::cout << "2. DeQueue end of queue.\n";
	std::cout << "3. Display contents of queue.\n";
	std::cout << "4. Quit.\n";

	do
	{
		std::cout << "Take action: ";
		std::cin >> answer;

		switch (answer)
		{
		case 1:
		std::cout << "Enter an element: ";
			std::cin >> elem;

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

		default:
			continue;
		}

	} while ((bool)answer);

	return 0;
}*/