#ifndef ZMPO_4B_VALUE_H
#define ZMPO_4B_VALUE_H


#include "ValueObject.h"

template <class T> class Value: public ValueObject<T> {
public:
    Value(T value) { this->setValue(value);}
    inline void accept(Stack<ValueObject<T>*>& stack) {};
};


#endif //ZMPO_4B_VALUE_H
