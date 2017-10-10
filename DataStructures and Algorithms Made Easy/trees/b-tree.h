//
// Created by mdn on 28.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H

// A BTree node
class node
{
private:
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    node **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false

public:
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);

    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, node *y);

    node(int t, bool leaf);   // Constructor

    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();

    // A function to search a key in subtree rooted with this node.
    node *search(int k);   // returns NULL if k is not present.

// Make BTree friend of this so that we can access private members of this
// class in BTree functions
    friend class BTree;
};

// A BTree
class BTree
{
    node *root; // Pointer to root node
    int t;  // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    explicit BTree(int _t)
    {  root = nullptr;  t = _t; }

    // function to traverse the tree
    void traverse()
    {  if (root != nullptr) root->traverse(); }

    // function to search a key in this tree
    node* search(int k)
    {  return (root == nullptr)? nullptr : root->search(k); }

    // The main function that inserts a new key in this B-Tree
    void insert(int k);
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
