/*
	COS: FDS
	array_stack.c
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	Purpose:	Create linked list stack holding integers
=======
	Purpose:	Create dyamic array stack holding integers
>>>>>>> 000929b... squashed last 9 commits
=======
	Purpose:	Create linked list stack holding integers
>>>>>>> 052aeeb... Fix branch files and structure
=======
	Purpose:	Create linked list stack holding integers
>>>>>>> 1384c68... Added stack files
=======
	Purpose:	Create linked list stack holding integers
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

	@author:	Martin Nestorov
	@version:	0.2.1 24/07/2017
*/

#include <iostream>

struct node
{
	node *next;
	int key;
};

<<<<<<< HEAD
class stack
{
public:
	stack();
	~stack();
=======
class Stack
{
public:
	Stack()= default;
	~Stack();
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

	void display_stack();
	void push(int &key);

	bool is_empty();
	
	int pop();
	int top();


private:
	void delete_stack();	
	
<<<<<<< HEAD
	node *top_of_stack;
};

stack::stack() : top_of_stack(NULL) { }

=======
	node *top_of_stack{};
};

>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
/**
	Push new element on top of stack

	@param *top_of_stack		The pointer to the top of stack
	@param key					The value that is pushed on top
*/
<<<<<<< HEAD
void stack::push(int &key)
=======
void Stack::push(int &key)
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
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
<<<<<<< HEAD
int stack::pop()
=======
int Stack::pop()
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
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
<<<<<<< HEAD
int stack::top()
{
	if (!is_empty())
		return top_of_stack->key;
	else
		return 0;
=======
int Stack::top()
{
	if (!is_empty())
		return top_of_stack->key;

	return 0;
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
}

/**
	Display the contents of the stack

	@param *top_of_stack	The pointer to the top of stack
*/
<<<<<<< HEAD
void stack::display_stack()
{
	node *temp = new node;
=======
void Stack::display_stack()
{
	auto *temp = new node;
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

	temp = top_of_stack;

	if (!is_empty())
	{
		std::cout << "Stack: ";

		do
		{
			std::cout << temp->key << " ";
			temp = temp->next;
<<<<<<< HEAD
		} while (temp != NULL);
=======
		} while (temp != nullptr);
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

		std::cout << "\n";
	}
}

<<<<<<< HEAD
//TODO make it templized and also so that one can initialize multiple stacks and not only one, so code restructure.

=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
/**
	Check if the stack is empty

	@param *top_of_stack	Pointer to the top of the stack
	@return					True of the stack is empty, otherwise, false
*/
<<<<<<< HEAD
bool stack::is_empty()
{
	return top_of_stack == NULL;
=======
bool Stack::is_empty()
{
	return top_of_stack == nullptr;
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
}

/**
	Delete the whole stack

	@param *top_of_satck	Pointer to the top of the stack
*/
<<<<<<< HEAD
void stack::delete_stack()
{
	if (!is_empty())
	{
		node *temp = new node;

		while (top_of_stack->next != NULL)
=======
void Stack::delete_stack()
{
	if (!is_empty())
	{
		auto *temp = new node;

		while (top_of_stack->next != nullptr)
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
		{
			temp = top_of_stack;
			top_of_stack = top_of_stack->next;
		}

		delete temp;
	}

	delete top_of_stack;
}

<<<<<<< HEAD
stack::~stack()
{
	delete_stack();
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*
=======

>>>>>>> 000929b... squashed last 9 commits
=======

/*
>>>>>>> 052aeeb... Fix branch files and structure
=======

/*
>>>>>>> 1384c68... Added stack files
int main(void)
{
	stack stack;
=======
Stack::~Stack()
{
	delete_stack();
}
/*
int main()
{
	Stack stack;
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals

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
<<<<<<< HEAD
		}

	} while (answer);

	return 0;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
}*/
=======
}
>>>>>>> 000929b... squashed last 9 commits
=======
}*/
>>>>>>> 052aeeb... Fix branch files and structure
=======
}*/
>>>>>>> 1384c68... Added stack files
=======

		default:
			continue;
		}

	} while ((bool)answer);

	return 0;
}*/
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
