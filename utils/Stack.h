#ifndef ZMPO_4B_STACK_H
#define ZMPO_4B_STACK_H

template <class T> class Stack {
private:
    class Node {
    public:
        T value;
        Node* next;
        Node(T& value, Node* next): value(value), next(next) {}
        ~Node() {delete next;}
    };
    Node* head;
    unsigned int sizeOf;
public:
    Stack(): sizeOf(0), head(nullptr) {};
    ~Stack();
    void push(T t);
    T pop();
    inline bool isEmpty() { return this->sizeOf <= 0;}
    inline unsigned int size() { return this->sizeOf;}

};

#include "Stack.cpp"

#endif //ZMPO_4B_STACK_H
