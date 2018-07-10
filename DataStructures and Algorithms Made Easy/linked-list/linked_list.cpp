#include <iostream>
#include "linked_list.h"

template<class T>
void LinkedList<T>::insert_node(T value)
{
    auto *temp = new node;
    temp->data = value;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        temp = nullptr;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        temp = nullptr;
    }
}

template<class T>
void LinkedList<T>::display()
{
    auto *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->data << "\t";
        temp = temp->next;
    }

    std::cout << std::endl;
}

template<class T>
void LinkedList<T>::insert_start(T value)
{
    auto *temp = new node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

template<class T>
void LinkedList<T>::delete_last()
{
    node *current = nullptr;
    auto *previous = new node;

    current = head;

    while (current->next != nullptr)
    {
        previous = current;
        current = current->next;
    }

    tail = previous;
    previous->next = nullptr;

    delete current;
}

template<class T>
void LinkedList<T>::insert_position(T value, T pos)
{
    auto *previous = new node;
    auto *temp = new node;

    node *current = nullptr;

    current = head;

    for (std::size_t i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }

    // The temp node holds the value we want to insert,
    // it is just a node floating in space right now.
    temp->data = value;
    // The previous node points to the temp node,
    // i.e. the left side of the list now includes
    // the temp node we want to insert.
    previous->next = temp;
    // Now th temp node has to link the right side of the
    // list and points to the current node.
    // That is, between the current and previous node,
    // we inserted our data.
    temp->next = current;
}

template<class T>
void LinkedList<T>::delete_first()
{
    auto *temp = nullptr;
    temp = head;
    head = head->next;

    delete temp;
}

template<class T>
void LinkedList<T>::delete_position(T pos)
{
    auto *current = head;
    auto *previous = new node;

    for (std::size_t i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    delete current;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    if (head != nullptr)
    {
        node *temp;

        while (head != nullptr)
        {
            temp = head;

            head = head->next;

            delete temp;
        }
    }

    delete head, tail;
}

int main()
{
    LinkedList<int> linked_list;

    int answer = 0, elem = 0, pos = 0;

    std::cout << "----- Linked List Menu -----\n";

    std::cout << "1. Insert element to the list.\n";
    std::cout << "2. Insert element at a posiiton.\n";
    std::cout << "3. Display contents of the list.\n";
    std::cout << "4. Delete element at a position.\n";
    std::cout << "5. Quit.\n";

    do
    {
        std::cout << "Take action: ";
        std::cin >> answer;

        switch (answer)
        {
        case 1:
            std::cout << "Enter an element: ";
            std::cin >> elem;

            linked_list.insert_node(elem);
            break;

        case 2:
            std::cout << "Enter an element: ";
            std::cin >> elem;
            std::cout << "Enter a position: ";
            std::cin >> pos;

            linked_list.insert_position(elem, pos);
            break;

        case 3:
            linked_list.display();

            break;

        case 4:
            std::cout << "Enter a position to delete: ";
            std::cin >> pos;

            linked_list.delete_position(pos);

            break;

        case 5:
            exit(0);

        default:
            continue;
        }

    } while ((bool) answer);

    return 0;
}
