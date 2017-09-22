/**
	COS: FDS
	oop_linked_list.cpp
	Purpose: 	Create a dynamic object oriented linked list queue

	@author: Martin Nestorov
	@version: 0.1.2 15/08/2017
*/

#include <iostream>

#include "oop_linked_list_queue.h"

template<class T>
void Queue<T>::en_queue(int key)
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

template<class T>
void Queue<T>::de_queue()
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

template<class T>
void Queue<T>::display_queue()
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

template<class T>
void Queue<T>::delete_queue()
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

template<class T>
Queue<T>::~Queue()
{
    delete_queue();
}
/*
int main()
{
	Queue<int> queue;

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
