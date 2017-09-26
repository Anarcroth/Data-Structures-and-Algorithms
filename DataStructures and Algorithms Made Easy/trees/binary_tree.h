//
// Created by mdn on 22.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H

template<class T>
struct node
{
    T key;
    node *left;
    node *right;
};

template<class T>
class BinaryTree
{
public:
    BinaryTree() = default;

    ~BinaryTree();

    void find_key(T key);

    void display_tree();

    void insert(T key);

    void level_order_traversal();

    void post_order_traversal();

    void pre_order_traversal();

    void in_order_traversal();

private:

    void find_key(node<T> *root, T key);

    void display_tree(node<T> *root, int indent);

    void insert(node<T> *root, T key);

    void delete_tree(node<T> *root);

    void level_order_traversal(node<T> *root);

    void post_order_traversal(node<T> *root);

    void pre_order_traversal(node<T> *root);

    void in_order_traversal(node<T> *root);

    node<T> *root{};
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H
