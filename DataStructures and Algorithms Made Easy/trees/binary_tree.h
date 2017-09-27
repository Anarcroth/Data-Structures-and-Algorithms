//
// Created by mdn on 22.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H

template<class T>
struct node
{
    const T key;

    node *left;
    node *right;

    int height;

    node(T new_key, node<T> *l, node<T> *r, int h = 0) : key(new_key), left(l), right(r), height(h)
    {}
};

template<class T>
class BinaryTree
{
public:
    BinaryTree() = default;

    ~BinaryTree();

    void find_key(const T &key);

    void display_tree();

    void insert(const T &key);

    void level_order_traversal();

    void post_order_traversal();

    void pre_order_traversal();

    void in_order_traversal();

private:

    void find_key(node<T> *&root, const T &key);

    void display_tree(node<T> *&root, int indent);

    void insert(node<T> *&root, const T &key);

    void delete_tree(node<T> *&root);

    void level_order_traversal(node<T> *&root);

    void post_order_traversal(node<T> *&root);

    void pre_order_traversal(node<T> *&root);

    void in_order_traversal(node<T> *&root);

    void right_rotation(node<T> *&root);

    void double_right_rotation(node<T> *&root);

    void left_rotation(node<T> *&root);

    void double_left_rotation(node<T> *&root);

    int height(node<T> *&root);

    node<T> *root{};
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_BINARY_TREE_H
