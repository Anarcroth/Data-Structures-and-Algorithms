//
// Created by mdn on 28.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H

// A BTree node
class node
{
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    node **C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    node(int _t, bool _leaf);   // Constructor

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
    BTree(int _t)
    {  root = nullptr;  t = _t; }

    // function to traverse the tree
    void traverse()
    {  if (root != nullptr) root->traverse(); }

    // function to search a key in this tree
    node* search(int k)
    {  return (root == nullptr)? nullptr : root->search(k); }
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
