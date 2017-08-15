/*
	COS: FDS
	array_stack.c
	Purpose:	Create linked list stack holding integers

	@author:	Martin Nestorov
	@version:	0.2.1 24/07/2017
*/

#include <iostream>

struct node
{
	node *next;
	int key;
};

class stack
{
public:
	stack();
	~stack();

	void display_stack();
	void push(int &key);

	bool is_empty();
	
	int pop();
	int top();


private:
	void delete_stack();	
	
	node *top_of_stack;
};

stack::stack() : top_of_stack(NULL) { }

/**
	Push new element on top of stack

	@param *top_of_stack		The pointer to the top of stack
	@param key					The value that is pushed on top
*/
void stack::push(int &key)
{
	node *temp = new node;

	temp->key = key;
	temp->next = top_of_stack;
	
	top_of_stack = temp;
}

/**
	Remove the top element from the stack
	
	
	@param *top_of_stack		The pointer to the top of stack
	@return						The top element from the stack
*/
int stack::pop()
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
int stack::top()
{
	if (!is_empty())
		return top_of_stack->key;
	else
		return 0;
}

/**
	Display the contents of the stack

	@param *top_of_stack	The pointer to the top of stack
*/
void stack::display_stack()
{
	node *temp = new node;

	temp = top_of_stack;

	if (!is_empty())
	{
		std::cout << "Stack: ";

		do
		{
			std::cout << temp->key << " ";
			temp = temp->next;
		} while (temp != NULL);

		std::cout << "\n";
	}
}

//TODO make it templized and also so that one can initialize multiple stacks and not only one, so code restructure.

/**
	Check if the stack is empty

	@param *top_of_stack	Pointer to the top of the stack
	@return					True of the stack is empty, otherwise, false
*/
bool stack::is_empty()
{
	return top_of_stack == NULL;
}

/**
	Delete the whole stack

	@param *top_of_satck	Pointer to the top of the stack
*/
void stack::delete_stack()
{
	if (!is_empty())
	{
		node *temp = new node;

		while (top_of_stack->next != NULL)
		{
			temp = top_of_stack;
			top_of_stack = top_of_stack->next;
		}

		delete temp;
	}

	delete top_of_stack;
}

stack::~stack()
{
	delete_stack();
}
/*
int main(void)
{
	stack stack;

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
		}

	} while (answer);

	return 0;
}*/