#Fundamental Data Structures and Algorithms

***
***
***

*Documentation for different data structures and algorithms implemented in C/C++*

>###Index:

1. Linked Lists
	
	1.1 Array Linked List  in **C**
	1.2 Dynamic Linked List in **C**
	1.3 Linked List in **C++**

2. Queues
	
	2.1 Array Queue in **C**
	2.2 Dynamic Array Queue in **C**
	2.3 Linked List Queue in **C++**
	
3. Stacks

	3.1 Array Stack in **C**
	3.2 Dynamic Array Stack in **C**
	3.3 Linked List Stack in **C++**
	
4. Binray Trees

5. B-Trees

6. Practice problems

7. Basic concepts of C/C++

***

## 1. Linked List

A Linked List is a *dynamic*, *sequential data structure*, where the elements are not stored in a contiguous location in memory, but are scattered around the memory, and are connected via pointers. Each element of the list can be represented with a **node** structure. The **node** holds a key, which we want to store, and a pointer to the next **node**.
 
Linked lists are useful for when we do not know the number of the elements we will be storing. Because of its dynamic nature we can, during runtime, allocate new space and continually delete and insert new elements anywhere we want.
 
~~~c
 struct node
 {
 	int key;
 	struct node *next;
 };
~~~

Although a Linked List is very flexible, it has several limitations. Unlike an array, a linked list doesn't have random access to the elements (you cannot directly access any element) . The program will also taken in more memory to execute, because of the extra allocation for the pointers.

####Pros: 

- Dynamically changes size during runtime
- Easy access to the first and last element
- Ease of insertion and deletion
- Very efficient in dynamic memory allocation (Outperforms an array when it comes to a fragmented memory usage)

####Cons: 

- No random access (ex: cannot performe a binary search)
- Program needs more memory to run
- Have to traverse trough the whole list to find a specific elements

###Time Complexity:
>Access:  **O(n)**
Search: **O(n)**
Insertion: **O(1)**
Deletion:  **O(1)**

>Space Complexity: **O(n)**

***

## 2. Queues

A Queue is

###Pros:

###Cons:

###Time Complexity:

***

## 2. Stacks

A Stack is

###Pros:

###Cons:

###Time Complexity: