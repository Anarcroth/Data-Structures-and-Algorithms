/**
    COS: FDS
    b-tree.h
    Purpose:    Create a B-Tree implementation holding integers

    @author:    Martin Nestorov
    @version:   0.1.0 10/10/2017
*/

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H

// A BTree node
class node
{
public:
    explicit node(int t, bool is_leaf);

    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);

    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, node *y);

    void traverse();

    node *search(int k);   // returns NULL if k is not present.

    friend class BTree;

private:
    int t;
    int *keys;
    int num_keys;

    node **C;

    bool is_leaf;
};

class BTree
{
public:
    explicit BTree(int t);

    void traverse()
    { if (root != nullptr) root->traverse(); }

    node *search(int k)
    { return (root == nullptr) ? nullptr : root->search(k); }

    void insert(int k);

private:
    node *root;
    int t;
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
