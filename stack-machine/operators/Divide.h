#ifndef ZMPO_4B_DIVIDE_H
#define ZMPO_4B_DIVIDE_H


#include "ValueObject.h"

template <class T> class Divide: public ValueObject<T> {
public:
    void accept(Stack<ValueObject<T>*>& stack) {
        this->handleEmptyStack(stack);
        ValueObject<T>* right = stack.pop();
        this->handleEmptyStack(stack);
        ValueObject<T>* left = stack.pop();
        this->setValue(left->getValue() / right->getValue());
        delete(left);
        delete(right);
    }
};


#endif //ZMPO_4B_DIVIDE_H
