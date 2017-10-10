/**
    COS: FDS
    b-tree.h
    Purpose:    Create a B-Tree implementation holding integers

    @author:    Martin Nestorov
    @version:   0.1.0 10/10/2017
*/

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H

class node
{
public:
    explicit node(int t, bool is_leaf);

    void insertNonFull(int k);

    void splitChild(int i, node *y);

    void traverse();

    node *search(int k);

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

    void traverse();

    void insert(int k);

    node *search(int k);

private:
    node *root;

    int t;
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_B_TREE_H
