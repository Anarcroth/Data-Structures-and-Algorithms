#include<iostream>

struct node
{
	int data;
	node *next;
};

class linked_list
{
private:
	node *head, *tail;

public:
	linked_list();
	~linked_list();

	void createnode(int value);

	void display();

	void insert_start(int value);

	void insert_position(int pos, int value);

	void delete_first();

	void delete_last();

	void delete_position(int pos);
};

linked_list::linked_list() : head(NULL), tail(NULL) { }

/*
 * Create either the beginning of the list,
 * or insert a new node to it.
 */
void linked_list::createnode(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = NULL;

	// If there isn't a beginning of the linked list,
	// create one and assign the thead to the temp node.
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		temp = NULL;
	}
}

/*
 * Display every node from the HEAD.
 * The HEAD is the beginning
 */
void linked_list::display()
{
	node *temp = new node;
	temp = head; // Use a temp node to traverse the list.

	while (temp != NULL)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
}

/*
 * Insert a node to the start of the list
 * and push the current head one position
 * bellow.
 */
void linked_list::insert_start(int value)
{
	node *temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
}

/*
 * Delete the last node of the list.
 * The current node reaches the last node
 * and is deleted, while the previous
 * node becomes the tail of the list.
 */
void linked_list::delete_last()
{
	node *current = new node;
	node *previous = new node;
	current = head;

	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}

	tail = previous;
	previous->next = NULL;

	delete current;
}

/*
 * Insert a node at a specific position,
 * where the temp node holds the value
 * we want to insert.
 */
void linked_list::insert_position(int pos, int value)
{
	node *previous = new node;
	node *current = new node;
	node *temp = new node;

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
	// the temp node we want to isnert.
	previous->next = temp;
	// Now th temp node has to link the right side of the
	// list and points to the current node.
	// That is, between the current and previous node,
	// we inserted our data.
	temp->next = current;
}

/*
 * Delete the HEAD of the list.
 */
void linked_list::delete_first()
{
	node *temp = new node;
	temp = head;
	head = head->next;

	delete temp;
}

/*
 * For a specified position, find that
 * node and delete it from the list.
 */
void linked_list::delete_position(int pos)
{
	node *current = new node;
	node *previous = new node;
	
	current = head;

	for (std::size_t i = 1; i < pos; i++)
	{
		previous = current;
		current = current->next;
	}

	previous->next = current->next;

	delete current;
}
/*
int main()
{
	list l_list;
	int num;

	for (std::size_t i = 0; i < 10; i++)
	{
		std::cin >> num;
		l_list.createnode(num);
	}

	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "---------------Displaying All nodes---------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.display();

	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "-----------------Inserting At End-----------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.createnode(55);
	l_list.display();
	
	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "----------------Inserting At Start----------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.insert_start(50);
	l_list.display();
	
	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "-------------Inserting At Particular--------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.insert_position(5, 60);
	l_list.display();
	
	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "----------------Deleting At Start-----------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.delete_first();
	l_list.display();
	
	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "-----------------Deleing At End-------------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.delete_last();
	l_list.display();
	
	std::cout << "\n--------------------------------------------------\n";
	std::cout <<   "--------------Deleting At Particular--------------";
	std::cout << "\n--------------------------------------------------\n";
	l_list.delete_position(4);
	l_list.display();
	
	std::cout << "\n--------------------------------------------------\n";
	
	system("pause");
	
	return 0;
}*/