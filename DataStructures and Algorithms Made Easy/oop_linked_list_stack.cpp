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

class Stack
{
public:
	Stack()= default;
	~Stack();
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged

	void display_stack();
	void push(int &key);

	bool is_empty();
	
	int pop();
	int top();


private:
	void delete_stack();	
	
	node *top_of_stack{};
};

<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
/**
	Push new element on top of stack

	@param *top_of_stack		The pointer to the top of stack
	@param key					The value that is pushed on top
*/
void Stack::push(int &key)
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
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
int Stack::pop()
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
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
int Stack::top()
{
	if (!is_empty())
		return top_of_stack->key;

	return 0;
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
}

/**
	Display the contents of the stack

	@param *top_of_stack	The pointer to the top of stack
*/
void Stack::display_stack()
{
	auto *temp = new node;
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged

	temp = top_of_stack;

	if (!is_empty())
	{
		std::cout << "Stack: ";

		do
		{
			std::cout << temp->key << " ";
			temp = temp->next;
		} while (temp != nullptr);
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged

		std::cout << "\n";
	}
}

<<<<<<< HEAD
<<<<<<< HEAD
//TODO make it templized and also so that one can initialize multiple stacks and not only one, so code restructure.

=======
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
/**
	Check if the stack is empty

	@param *top_of_stack	Pointer to the top of the stack
	@return					True of the stack is empty, otherwise, false
*/
bool Stack::is_empty()
{
	return top_of_stack == nullptr;
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
}

/**
	Delete the whole stack

	@param *top_of_satck	Pointer to the top of the stack
*/
void Stack::delete_stack()
{
	if (!is_empty())
	{
		auto *temp = new node;

		while (top_of_stack->next != nullptr)
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged
		{
			temp = top_of_stack;
			top_of_stack = top_of_stack->next;
		}

		delete temp;
	}

	delete top_of_stack;
}

<<<<<<< HEAD
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
=======
>>>>>>> 5683347... Fixed conflicts and merged
Stack::~Stack()
{
	delete_stack();
}

/*
int main()
{
	Stack stack;
<<<<<<< HEAD
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
=======
>>>>>>> 5683347... Fixed conflicts and merged

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
=======
>>>>>>> 5683347... Fixed conflicts and merged

		default:
			continue;
		}

	} while ((bool)answer);

	return 0;
}*/
>>>>>>> f6c296b... Added Binary Tree implemenation with traversals
