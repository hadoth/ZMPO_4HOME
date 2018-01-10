#ifndef ZMPO_4B_STACKMACHINE_H
#define ZMPO_4B_STACKMACHINE_H


#include <iostream>
#include <sstream>
#include "../utils/Stack.h"
#include "operators/ValueObject.h"
#include "../utils/CharUtils.h"
#include "operators/Add.h"
#include "operators/Subtract.h"
#include "operators/Multiply.h"
#include "operators/Divide.h"
#include "operators/Value.h"

//const char *PLUS = "+";
//const char *MINUS = "-";
//const char *MULT = "*";
//const char *DIV = "/";
//const char *EQALS = "=";
//const char *YES = "y";
//const char *NO = "n";
//const char *CONTINUE = "Would You like to continue? (Y/N)";
//const char *INVALID = "Communicate not recognized!";
//const char *INSTRUCTION = "Please provide numbers and operators accordingly to the RPN rules.";
//const char *BREAK = "---===|||===---";

template <class T> class StackMachine {
public:
    StackMachine()  {}
    void value(T value) {
        Value<T> object(value);
        this->stack.push(object);
    }
    void add() {
        Add<T> object;
        handleOperation(object);
    }

    void subtract() {
        Subtract<T> object;
        handleOperation(object);

    }
    void multiply() {
        Multiply<T> object;
        handleOperation(object);
    }
    void divide() {
        Divide<T> object;
        handleOperation(object);
    }
    T getResult() {
        if (this->stack.isEmpty()) {
            throw std::invalid_argument("Invalid expression: stack is empty!");
        } else if (this->stack.size() > 1) {
            throw std::invalid_argument("Invalid expression: too many arguments!");
        } else {
            return this->stack.pop().getValue();
        }
    }
    void clear() {
        this->stack.clear();
    }
private:
    void handleOperation(ValueObject<T>& object) {
        if (stack.size() >= 2) {
            object.accept(stack);
            this->stack.push(object);
        } else {
            throw std::invalid_argument("Invalid expression: not enough arguments!");
        }
    }
    Stack<ValueObject<T>> stack;
};

#endif //ZMPO_4B_STACKMACHINE_H
