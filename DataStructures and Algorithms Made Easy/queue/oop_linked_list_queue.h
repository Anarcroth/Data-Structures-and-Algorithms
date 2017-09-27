//
// Created by mdn on 22.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_OOP_LINKED_LIST_QUEUE_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_OOP_LINKED_LIST_QUEUE_H

struct node
{
    int key;
    node *next;
};

template<class T>
class Queue
{
public:
    Queue() = default;

    ~Queue();

    void en_queue(int key);

    void display_queue();

    void delete_queue();

    void de_queue();

private:
    node *front{}, *end{};
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_OOP_LINKED_LIST_QUEUE_H
