//
// Created by mdn on 22.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H

struct node
{
    int key;
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

    void find_key(node *root, T key);

    void display_tree(node *root, int indent);

    void insert(node *root, T key);

    void delete_tree(node *root);

    void level_order_traversal(node *root);

    void post_order_traversal(node *root);

    void pre_order_traversal(node *root);

    void in_order_traversal(node *root);

    node *root{};
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H
