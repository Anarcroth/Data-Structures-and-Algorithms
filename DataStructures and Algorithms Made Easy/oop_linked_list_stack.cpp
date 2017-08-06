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
	void delete_stack();
	void push(int key);
	
	int pop();
	int top();

private:
	void push(node *top, int key);
	void display_stack(node *top);
	void delete_stack(node *top);
	
	bool is_empty(node *top);
	
	int pop(node *top);
	int top(node *top);

	node *top_of_stack;
};

stack::stack() : top_of_stack(NULL) { }

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

void stack::push(node *top, int key)
{
	node *temp = new node;
	temp->key = key;
	temp->next = top;
	
	top = temp;
}

int stack::pop()
{
	return pop(top_of_stack);
}

int stack::pop(node *top)
{
	if (!is_empty(top))
	{
		int key = top->key;
		top = top->next;

		return key;
	}
}

int stack::top()
{
	return top(top_of_stack);
}

int stack::top(node *top_of_stack)
{
	if (!is_empty(top_of_stack))
		return top_of_stack->key;
	else
		return 0;
}

//TODO make it templized and also so that one can initialize multiple stacks and not only one, so code restructure.

bool stack::is_empty(node *top)
{
	return top == NULL;
}

stack::~stack()
{
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
	std::cout << "5. quit.\n";

	do 
	{
		std::cout << "Take action: ";
		scanf_s("%d", &answer);

		switch (answer)
		{
		case 1:
			cout("Enter an element: ");
			scanf_s("%d", &elem);

			stack.push(elem);
			break;

		case 2:
			stack = pop(stack, &elem);
			
			if (!is_empty(stack))
				cout("The poped element is: %d\n", elem);
			
			break;

		case 3:
			display_stack(stack);
			break;

		case 4:
			cout("The top element is: %d\n", top(stack));
			break;

		case 5:
			delete_stack(stack);

			exit(0);
			break;
		}
	
	} while (answer);


	
	return 0;
}