//
// Created by mdn on 22.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_OOP_LINKED_LIST_STACK_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_OOP_LINKED_LIST_STACK_H

struct node
{
    node *next;
    int key;
};

template<class T>
class Stack
{
public:
    Stack() = default;

    ~Stack();

    void display_stack();

    void push(int &key);

    bool inline is_empty();

    int pop();

    int top();

private:
    void delete_stack();

    node *top_of_stack{};
};

#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_OOP_LINKED_LIST_STACK_H
