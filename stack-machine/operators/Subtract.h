#ifndef ZMPO_4B_SUBTRACT_H
#define ZMPO_4B_SUBTRACT_H


#include "ValueObject.h"

template <class T> class Subtract: public ValueObject<T> {
public:
    void accept(Stack<ValueObject<T>>& stack) {
        this->handleEmptyStack(stack);
        T left = stack.pop().getValue();
        this->handleEmptyStack(stack);
        T right = stack.pop().getValue();
        this->setValue(left - right);
    }
};


#endif //ZMPO_4B_SUBTRACT_H
