//
// Created by mdn on 22.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_LINKED_LIST_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_LINKED_LIST_H

struct node
{
    int data;
    node *next;
};

template<class T>
class LinkedList
{
public:
    LinkedList() = default;

    ~LinkedList();

    void insert_position(T value, T pos);

    void delete_position(T pos);

    void insert_start(T value);

    void insert_node(T value);

    void delete_first();

    void delete_last();

    void display();

private:
    node *head{}, *tail{};
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_LINKED_LIST_H
