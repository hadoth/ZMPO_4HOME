#ifndef ZMPO_4B_SUBTRACT_H
#define ZMPO_4B_SUBTRACT_H


#include "ValueObject.h"

template <class T> class Subtract: public ValueObject<T> {
public:
    void accept(Stack<ValueObject<T>*>& stack) {
        this->handleEmptyStack(stack);
        ValueObject<T>* right = stack.pop();
        this->handleEmptyStack(stack);
        ValueObject<T>* left = stack.pop();
        this->setValue(left->getValue() - right->getValue());
        delete(left);
        delete(right);
    }
};


#endif //ZMPO_4B_SUBTRACT_H
