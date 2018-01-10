#ifndef ZMPO_4B_VALUEOBJECT_H
#define ZMPO_4B_VALUEOBJECT_H

#include "../../utils/Stack.h"

template <class T> class ValueObject {
private:
    T value;
protected:
    inline void setValue(T value) { this->value = value;}
    inline void handleEmptyStack(Stack<ValueObject<T>>& stack) {if (stack.isEmpty()) {throw std::out_of_range("Illegal argument: the stack is empty");}}
public:
    inline T getValue() { return this->value;}
    virtual void accept(Stack<ValueObject<T>>& stack) = 0;
};


#endif //ZMPO_4B_VALUEOBJECT_H