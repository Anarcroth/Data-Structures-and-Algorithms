#Fundamental Data Structures and Algorithms

---

---

---

*Documentation for different data structures and algorithms in C/C++*

##Index:

1. Linked Lists and Arrays
	
	1.1 Arrays
	1.2 Array Linked List  in **C**
	1.3 Dynamic Linked List in **C**
	1.4 Linked List in **C++**
	1.5 Problems
	
2. Stacks

	2.1 Array Stack in **C**
	2.2 Dynamic Array Stack in **C**
	2.3 Linked List Stack in **C++**
	2.4 Problems
	
3. Queues
	
	3.1 Array Queue in **C**
	3.2 Dynamic Array Queue in **C**
	3.3 Linked List Queue in **C++**
	3.4 Problems
	
	
4. Binray Trees

5. B-Trees

6. Practice problems

7. Basic concepts of **C/C++**

---

## 1. Linked Lists and Arrays

*Linked Lists vs. Arrays* - Both linked lists and arrays do fairly similar things, but there are several fundamental differences between the two.

**--- 1.1 Arrays ---**

>*Arrays*  allocate an entire memory block to hold the elements. The first element in an array always has an index of *0 (zero)*, and if the array has *n* elements the last element will have the index *n - 1*. 

>Using the index of the array, access time to each one of the elements is constant (To access an array element, its address is computed as an offset from the base address of the array. One multiplication is needed to compute what is suppposed to be added to the base address to get the memory address of the element. To do the multiplication, first the size of an element of that data type is calculated, and then it is multiplied with the index of the element to get the value to be added to the base address).

 >Using an index/subscript that is out of range is called *Subscript Overflow*.

![array](/home/mdn/Data-Structures-and-Algorithms/ADT pics/array.jpg  "array")

An element of an array *“A[ I ]”* is calculated using the following formula:

*A [ I ] = B + W * ( I – LB )*

Where,
**B** = Base address
**W** = Storage Size of one element stored in the array (in byte)
**I** = Subscript of element whose address is to be found
**LB** = Lower limit / Lower Bound of subscript, if not specified assume 0 (zero)

These arithmetic processes take constant time so we can say, that the array access is performed in constant time.

#####---Pros--- 

- Simple and easy to use
- Very fast access time, no boundary checks

#####---Cons--- 

- Preallocation of needed memory and possible waste of memory if indices are left empty
- Fixed size / Difficult and slow to change size
- One block allocation, where to allocate the array itself at the beginning, seomtimes it may not be possible to get the memory for the complete array, if the array size is too big
- Complex position-based insertion, where to insert an element at a give position, we may need to shift the existing elements. If the insertion is at the beginning of the array, then the operation is very expensive.

*Dynamic Arrays* are enhanced arrays, which expand and shrink during runtime. Initialized with a fixed length, they can either double their size when they get full, or shrink by half, if the elements in the array are less than half.

#####---Time Complexity---

Indexing: **O(1)**
Access:  **O(1)**
Search: **O(1)**
Insertion at the beginning (if array is not full): **O(n)**
Insertion at the middle (if array is not full): **O(n)**
Insertion at the end: **O(1)**
Deletion at the beginning (if array is not full): **O(n)**
Deletion at the middle (if array is not full): **O(n)**
Deletion at the end: **O(1)**

Space Complexity: **O(0)**

---

**--Linked Lists--**

>A Linked List is a *dynamic*, *sequential data structure*, where the elements are not stored in a contiguous location in memory, but are scattered around the memory, connected via pointers. Each element of the list can be represented with a **node** structure. The **node** holds a key(the data we want to store) and a pointer to the next **node**.
 
![linked list](/home/mdn/Data-Structures-and-Algorithms/ADT pics/basic_linked_list.png  "linked list")

*Linked Lists* are useful for when we do not know the number of the elements we will be storing. Because of its dynamic nature we can, during runtime, allocate new space and continually delete and insert new elements anywhere we want.
 
~~~c
 struct node
 {
 	int key;
 	struct node *next;
 };
~~~

Although a Linked List is very flexible, it has several limitations. Unlike an array, a linked list doesn't have random access to the elements (you cannot directly access any element). Sometimes linked lists are hard to manipulate. For instance, if the last node is deleted, the list has to be traversed to find the last node and set its pointer to NULL.

The program will also taken in more memory to execute, because of the extra allocation for the pointers.

#####---Pros---

- Dynamically changes size during runtime
- Easy access to the first and last element
- Ease of insertion and deletion
- Very efficient in dynamic memory allocation (Outperforms an array when it comes to a fragmented memory usage)

#####---Cons---

- No random access (ex: cannot performe a binary search)
- Program needs more memory to run
- Have to traverse trough the whole list to find a specific elements

#####---Time Complexity---

Indexing: **O(n)**
Access:  **O(n)**
Search: **O(n)**
Insertion at the beginning: **O(1)**
Insertion at the middle/end: **O(n)**
Deletion at the beginning:  **O(1)**
Deletion at the middle/end:  **O(n)**

Space Complexity: **O(n)**

#####Basic Linked List methods

~~~c
void create_node(int value);				// Create new node
	
void display_linked_list(); 				// Traverse list and display contents

void insert_at_start(int value); 			// Insert node at the start

void insert_at_position(int pos, int value);// Insert node at a position

void delete_first(); 						// Delete the first node

void delete_last(); 						// Delete the last node

void delete_at_position(int pos); 			// Delete a node at a position
	
void delete_linked_list(); 					// Delete whole linked list
~~~

---

## 2. Stacks

>*Stacks*, based on Lists, are *dyamic*, *sequential data structures*, where the elements are *"on top of each other"* and follow the FILO/LIFO (**F**irst **I**n **L**ast **O**ut / **L**ast **I**n **F**irst **O**ut) principle. Insertion and deletion operations are limited to one end (*top*) of the structure.

>When inserting an elements in a stack, the operation is *push*, and when an element is taken from the *top*, the operation is *pop*. Trying to *pop* an empty stack is refered to as a *stack underflow* and trying to *push* an element into a full stack is a *stack overflow*.

As an example, a pile of plates can be represented as a stack. Plates are put on top of the stack and are taken from the top when needed. The first plate that is put on the stack is the last one to be serviced.

![stack](/home/mdn/Data-Structures-and-Algorithms/ADT pics/stack.png  "stack")

#####---Applications---

- Balancing of symbols
- Infix to Postfix conversion
- Postfix expressions evaluation
- Function calls (with recursion)
- Web browser history
- Undo sequences

(Stacks can also be used for Tree traversal algorithms or simulating componenys of other data structures)

#####---Pros---

- Dynamically changes size during runtime
- Easy access to the element on the top
- Ease of insertion and deletion on the top
- Not easily corrupted, no easy insertion in the middle

#####---Cons---

- No random access
- Program needs more memory to run
- Have to traverse trough the whole stack to find a specific elements

#####---Time Complexity---

Access: **O(n)**
Search: **O(n)**
Insertion: **O(1)**
Deletion: **O(1)**

Space Complexity: **O(n)**

#####Basic Stack methods

~~~c
struct node* pop(struct node *stack, int *element); // Remove the top element

struct node* push(struct node *stack, int key);		// Insert new element on top

void display_stack(struct node *stack);				// Display the whole stack

void delete_stack(struct node *stack);				// Delete the whole stack

int top(struct node *stack); 						// Look at the top element
~~~

#####Stack vs. Heap (Memory management and CPU control)

The computer memory manager utilizes the *stack* and *heap* principles to allocate main memory to the user, but *satcks* and *heaps* are quite different.

**--Stack--**

The **Stack** is managed and optimized by the CPU quite closely. Everytime a function declares a new variable, it is *"pushed"* onto the stack. Then every time a function exits, all of the variables pushed onto the stack by that function, are deleted. Once a stack variable is freed, that region of memory becomes available for other stack variables. 

 The advantage of using the stack to store variables, is that memory is managed for you. You don't have to allocate memory by hand, or free it once you don't need it any more. What's more, because the CPU organizes stack memory so efficiently, reading from and writing to stack variables is very fast.

An important apsect of the stack is the notion that when a function exits, all of its variables are popped off of the stack (and hence lost forever). Thus stack variables have local scopes in nature. In C programming, attempting to access a variable that was created on the stack inside some function, from a place in your program outside of that function (i.e. after that function has exited), will cause a bug in the program.

Another feature of the stack to keep in mind, is that there is a limit (varies with OS) on the size of variables that can be store on the stack. This is not the case for variables allocated on the heap.

**--Heap--**

The **Heap** is a region of your computer's memory that is not managed automatically for you, and is not as tightly managed by the CPU. It is a more free-floating region of memory (and is larger). To allocate memory on the heap, you must use *malloc()* or *calloc()* C functions. Once you have allocated memory on the heap, you are responsible for using *free()* to deallocate that memory once you don't need it any more. If you fail to do this, your program will have what is known as a memory leak. That is, memory on the heap will still be set aside (and won't be available to other processes). As we will see in the debugging section, there is a tool called valgrind that can help you detect memory leaks.

Unlike the stack, the heap does not have size restrictions on variable size (apart from the obvious physical limitations of your computer). Heap memory is slightly slower to be read from and written to, because one has to use pointers to access memory on the heap.

Unlike the stack, variables created on the heap are accessible by any function, anywhere in your program. Heap variables are essentially global in scope.

---

## 3. Queues

>A Queue, based on Lists and similar to Stacks, is a *dyanmic*, *sequential data structure*, where the elements of the structure *"form a line"* and follow the FIFO / LILO (**F**irst **I**n **F**irst **O**ut / **L**ast **I**n **L**ast **O**ut) principle. Insertion is limited only to one end of the queue (*back*) and deletion is limited only to the other end (*front*).

>When inserting an element to front of the queue, the operation is *"enquque"*, and when an element is deleted from back the queue, the operation is *"dequeue"*. Trying to delete an empty queue is refered to as *"queue underflow"* and trying to add an element to a full queue is a *"queue overflow"*.

![queue](/home/mdn/Data-Structures-and-Algorithms/ADT pics/queue.png  "queue")

A Queue can be imagined like a line of people. The first person to join the queue, is the first one to be serviced and then the first one to leave the queue. Then the next person is in front of the line and is serviced and so on.

#####---Applications---

- OS job scheduling
- Simulation of real world queues
- Multiprogramming
- Asynchronous data transfer (file IO, pipes, sockets)

#####---Pros---

- Dynamically changes size during runtime
- Easy access to the element on the front
- Ease of insertion in the back and deletion of the front
- Not easily corrupted, no easy insertion in the middle

#####---Cons---

- No random access
- Program needs more memory to run
- Have to traverse trough the whole queue to find a specific elements

#####---Time Complexity---

Access: **O(n)**
Search: **O(n)**
Insertion: **O(1)**
Deletion: **O(1)**

Space Complexity: **O(n)**

#####Basic Queue methods

~~~c
struct queue *en_queue(struct queue *que, int key);
struct queue *de_queue(struct queue *que);
struct queue *create_queue();

void display_queue(struct queue *que);
void delete_queue(struct queue *que);
~~~

---

**C/C++ bonus information**

*Extern:* Extern is a function in C++, which comes in useful when you have global variables.
The existance of globl variablesare declared in a header file, so that each source file
that includes the header knows about it, but the variables need to be defined only once in 
a source file

*Compiling a C++ program:* The precedence among the syntax rules of translation is specified by the following phases.

1. Physical source files characters are mapped, in an implementation-defined manner, to the basic 
source character set (introducing new-line characters for end-of-line indicators) if necessary.

2. Each instance of a backslash character **\\** immediately followed by a new-line character is deleted, splicing physycal source lines to form logical source lines.

3. The source file is decompressed into processing rokens and sequences of white-space
characters (including characters).

4. Preprocessing directives are executed, macro invocations are expanded, and _pragma unary
operator expressions are executed.

5. Each source character set member in a character literal or a string literal, as well as each escape
sequence and universal-character-name in a charecter literal or non-raw string literal, is converted
to the corresponding member of the execution character set.

6. Adjecent string literal tokens are concatenated.

7. White-space characters separating tokens are no longer significant. Each processing token
is converted into a token. The resulting tokens are syntatically and semantically analyzed
and translatedas a translation unit.

8. Translated translation units are combined as follows:

9. All external entity references are resolved. Library components are linked to satisfy 
external references to entities not defined in the current translaio. All suchtranslator
output is collected into a program image which contains information needed for execution
in its execution environment.

[Implementation must behave as if these separate phases occur, although in practice different
phases might be folded together]

---
####Useful Links: 
https://stackoverflow.com/questions/2229498/passing-by-reference-in-c

https://stackoverflow.com/questions/13654138/

what-exactly-is-the-difference-between-pass-by-reference-in-c-and-in-c
exit(EXIT_FAILURE);
http://

www.guideforschool.com/625348-memory-address-calculation-in-an-array/
"the duration of 9 192 631 770 periods of the radiation corresponding to the transition between the two hyperfine levels of the ground state of the caesium 133 atom"

erowid.org

stackoverflow.com/admin.php

https://wildlyinaccurate.com/a-hackers-guide-to-git/#tree-objects

---