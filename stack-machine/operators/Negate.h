#ifndef ZMPO_4B_NEGATE_H
#define ZMPO_4B_NEGATE_H


#include "../../utils/Stack.h"
#include "ValueObject.h"

template <class T> class Negate: public ValueObject<T> {
public:
    void accept(Stack<ValueObject<T>>& stack) {
        handleEmptyStack(stack);
        this->setValue(-stack.pop().getValue());
    }
};


#endif //ZMPO_4B_NEGATE_H
