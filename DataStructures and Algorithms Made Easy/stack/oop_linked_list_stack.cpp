/*
	COS: FDS
	array_stack.c
	Purpose:	Create linked list stack holding integers

	@author:	Martin Nestorov
	@version:	0.2.1 24/07/2017
*/

#include <iostream>
#include "oop_linked_list_stack.h"

/**
	Push new element on top of stack

	@param *top_of_stack		The pointer to the top of stack
	@param key					The value that is pushed on top
*/
template<class T>
void Stack<T>::push(int &key)
{
    auto *temp = new node;

    temp->key = key;
    temp->next = top_of_stack;

    top_of_stack = temp;
}

/**
	Remove the top element from the stack
	
	
	@param *top_of_stack		The pointer to the top of stack
	@return						The top element from the stack
*/
template<class T>
int Stack<T>::pop()
{
    if (!is_empty())
    {
        int key = top_of_stack->key;
        top_of_stack = top_of_stack->next;

        return key;
    }

    return NULL;
}

/**
	Only get the top value of the stack without removing the element

	@param *top_of_stack		The pointer to the top of stack
	@return						The top element from the stack
*/
template<class T>
int Stack<T>::top()
{
    if (!is_empty())
        return top_of_stack->key;

    return 0;
}

/**
	Display the contents of the stack

	@param *top_of_stack	The pointer to the top of stack
*/
template<class T>
void Stack<T>::display_stack()
{
    auto *temp = top_of_stack;

    if (!is_empty())
    {
        std::cout << "Stack: \n";

        do
        {
            std::cout << temp->key << std::endl;
            temp = temp->next;
        } while (temp != nullptr);

        std::cout << "\n";
    }
}

/**
	Check if the stack is empty

	@param *top_of_stack	Pointer to the top of the stack
	@return					True of the stack is empty, otherwise, false
*/
template<class T>
bool Stack<T>::is_empty()
{
    return top_of_stack == nullptr;
}

/**
	Delete the whole stack

	@param *top_of_satck	Pointer to the top of the stack
*/
template<class T>
void Stack<T>::delete_stack()
{
    if (!is_empty())
    {
        auto *temp = new node;

        while (top_of_stack->next != nullptr)
        {
            temp = top_of_stack;
            top_of_stack = top_of_stack->next;
        }

        delete temp;
    }

    delete top_of_stack;
}

template<class T>
Stack<T>::~Stack()
{
    delete_stack();
}
/*
int main()
{
    Stack<int> stack;

    int answer = 0, elem = 0;

    std::cout << "----- OOP Stack Menu -----\n";

    std::cout << "1. Push new element to stack.\n";
    std::cout << "2. Pop top of stack.\n";
    std::cout << "3. Display contents of stack.\n";
    std::cout << "4. Look at the top of stack.\n";
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

                stack.push(elem);
                break;

            case 2:
                if (!stack.is_empty())
                    std::cout << "The poped element is: " << stack.pop() << std::endl;
                else
                    std::cout << "The stack is empty.\n";

                break;

            case 3:
                if (!stack.is_empty())
                    stack.display_stack();
                else
                    std::cout << "The stack is empty.\n";

                break;

            case 4:
                if (!stack.is_empty())
                    std::cout << "The top element is: " << stack.top() << std::endl;
                else
                    std::cout << "The stack is empty.\n";

                break;

            case 5:
                exit(0);

            default:
                continue;
        }

    } while ((bool) answer);

    return 0;
}*/