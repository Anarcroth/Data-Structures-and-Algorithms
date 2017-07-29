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

	node *top;
};

stack::stack() : top(NULL) { }

void stack::push(int key)
{
	if (is_empty(top))
	{
		top = new node;
		top->key = key;
		top->next = NULL;
	}
	else
		push(top, key);
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
	return pop(top);
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

	return 0;
}