/**
    COS: FDS
    b-tree.cpp
    Purpose:    Create a B-Tree implementation holding integers

    @author:    Martin Nestorov
    @version:   0.1.0 10/10/2017
*/

#include <iostream>
#include "b-tree.h"

node::node(int t, bool leaf) : t(t), is_leaf(leaf), keys(new int[2 * t - 1]), C(new node *[2 * t]), num_keys(0)
{

}

void node::traverse()
{
    int i;
    for (i = 0; i < num_keys; i++)
    {
        // If this isn't a leaf, then first go to the subtree.
        if (!is_leaf)
        {
            C[i]->traverse();
        }

        std::cout << " " << keys[i];
    }

    // Print the subtree rooted with last child
    if (!is_leaf)
    {
        C[i]->traverse();
    }
}

node *node::search(int k)
{
    int i = 0;
    while (i < num_keys && k > keys[i])
    {
        i++;
    }

    if (keys[i] == k)
    {
        return this;
    }

    if (!is_leaf)
    {
        return nullptr;
    }

    return C[i]->search(k);
}

BTree::BTree(int t) : t(t), root(nullptr)
{

}

void BTree::insert(int k)
{
    if (root == nullptr)
    {
        root = new node(t, true);
        root->keys[0] = k;
        root->num_keys = 1;
    }
    else
    {
        if (root->num_keys == 2 * t - 1)
        {
            auto *s = new node(t, false);

            // Make old root as child of new root.
            s->C[0] = root;

            // Split the old root and move 1 key to the new root
            s->splitChild(0, root);

            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            if (s->keys[0] < k)
            {
                i++;
            }

            s->C[i]->insertNonFull(k);

            root = s;
        }
        else
        {
            root->insertNonFull(k);
        }
    }
}


void node::insertNonFull(int k)
{
    int i = num_keys - 1;

    if (is_leaf)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        num_keys = num_keys + 1;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;

        if (C[i + 1]->num_keys == 2 * t - 1)
        {
            splitChild(i + 1, C[i + 1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is split into two.  See which of the two
            // is going to have the new key
            if (keys[i + 1] < k)
            {
                i++;
            }
        }

        C[i + 1]->insertNonFull(k);
    }
}

void node::splitChild(int i, node *y)
{
    auto *z = new node(y->t, y->is_leaf);
    z->num_keys = t - 1;

    for (int j = 0; j < t - 1; j++)
    {
        z->keys[j] = y->keys[j + t];
    }

    if (!y->is_leaf)
    {
        for (int j = 0; j < t; j++)
        {
            z->C[j] = y->C[j + t];
        }
    }

    y->num_keys = t - 1;

    for (int j = num_keys; j >= i + 1; j--)
    {
        C[j + 1] = C[j];
    }

    C[i + 1] = z;

    for (int j = num_keys - 1; j >= i; j--)
    {
        keys[j + 1] = keys[j];
    }

    keys[i] = y->keys[t - 1];

    num_keys = num_keys + 1;
}

int main()
{
    BTree tree(3);
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    std::cout << "Traversal of the constucted tree is ";
    tree.traverse();

    int k = 6;
    (tree.search(k) != nullptr) ? std::cout << "\nPresent" : std::cout << "\nNot Present";

    k = 15;
    (tree.search(k) != nullptr) ? std::cout << "\nPresent" : std::cout << "\nNot Present";
    return 0;
}
