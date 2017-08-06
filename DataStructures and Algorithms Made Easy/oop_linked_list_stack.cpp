/*
	COS: FDS
	array_stack.c
	Purpose:	Create dyamic array stack holding integers

	@author:	Martin Nestorov
	@version:	0.1 24/07/2017
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
	void push(int key);

	bool is_empty(node *top_of_stack);
	
	int pop();
	int top();

	node *top_of_stack;

private:
	void push(node *top_of_stack, int key);
	void display_stack(node *top_of_stack);
	void delete_stack(node *top_of_stack);	
	
	int pop(node *top_of_stack);
	int top(node *top_of_stack);
};

stack::stack() : top_of_stack(NULL) { }

/**
	Pass an element to be pushed on the top. If needed, create a stack and the push the new element.

	@param key		The value that is pushed on top
*/
void stack::push(int key)
{
	if (is_empty(top_of_stack))
	{
		top_of_stack = new node;
		top_of_stack->key = key;
		top_of_stack->next = NULL;
	}
	else
		push(top_of_stack, key);
}

/**
	Push new element on top of stack

	@param *top_of_stack		The pointer to the top of stack
	@param key					The value that is pushed on top
*/
void stack::push(node *top_of_stack, int key)
{
	node *temp = new node;
	temp->key = key;
	temp->next = top_of_stack;
	
	top_of_stack = temp;
}

/**
	Get the top element from the top of stack

	@return The top element from the stack
*/
int stack::pop()
{
	return pop(top_of_stack);
}

/**
	Remove the top element from the stack
	
	
	@param *top_of_stack		The pointer to the top of stack
	@return						The top element from the stack
*/
int stack::pop(node *top_of_stack)
{
	if (!is_empty(top_of_stack))
	{
		int key = top_of_stack->key;
		top_of_stack = top_of_stack->next;

		return key;
	}
}

/**
	Get the top element from the stack

	@return The top element from the stack
*/
int stack::top()
{
	return top(top_of_stack);
}

/**
	Only get the top value of the stack without removing the element

	@param *top_of_stack		The pointer to the top of stack
	@return						The top element from the stack
*/
int stack::top(node *top_of_stack)
{
	if (!is_empty(top_of_stack))
		return top_of_stack->key;
	else
		return 0;
}

/**
	Display the contents of the stack
*/
void stack::display_stack()
{
	display_stack(top_of_stack);
}

/**
	Display the contents of the stack

	@param *top_of_stack	The pointer to the top of stack
*/
void stack::display_stack(node *top_of_stack)
{
	if (!is_empty(top_of_stack))
	{
		std::cout << "Stack: ";

		do
		{
			std::cout << " " << top_of_stack->key;
			top_of_stack = top_of_stack->next;
		} while (top_of_stack != NULL);

		std::cout << "\n";
	}
}

//TODO make it templized and also so that one can initialize multiple stacks and not only one, so code restructure.

/**
	Check if the stack is empty

	@param *top_of_stack	Pointer to the top of the stack
	@return					True of the stack is empty, otherwise, false
*/
bool stack::is_empty(node *top_of_stack)
{
	return top_of_stack == NULL;
}

/**
	Delete the whole stack

	@param *top_of_satck	Pointer to the top of the stack
*/
void stack::delete_stack(node *top_of_stack)
{
	if (!is_empty(top_of_stack))
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
	delete_stack(top_of_stack);
}

int main(void)
{
	stack stack;

	int answer = 0, elem = 0;

	std::cout << "----- Menu -----\n";

	std::cout << "1. Push new element to stack.\n";
	std::cout << "2. Pop top of stack.\n";
	std::cout << "3. Display contents of stack.\n";
	std::cout << "4. Look at the top of stack.\n";

	do 
	{
		std::cout << "Take action: ";
		scanf_s("%d", &answer);

		switch (answer)
		{
		case 1:
			std::cout << "Enter an element: ";
			std::cin >> elem;

			stack.push(elem);
			break;

		case 2:
			elem = stack.pop();
			
			if (!stack.is_empty(stack.top_of_stack))
				std::cout << "The poped element is: \n" << elem;
			
			break;

		case 3:
			stack.display_stack();
			break;

		case 4:
			std::cout << "The top element is: \n" << stack.top();
			break;
		}

	} while (answer);

	return 0;
}