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
        ValueObject<T>* object = new Value<T>(value);
        this->stack.push(object);
    }
    void add() {
        ValueObject<T>* object = new Add<T>;
        handleOperation(object);
    }

    void subtract() {
        ValueObject<T>* object = new Subtract<T>;
        handleOperation(object);

    }
    void multiply() {
        ValueObject<T>* object = new Multiply<T>;
        handleOperation(object);
    }
    void divide() {
        ValueObject<T>* object = new Divide<T>;
        handleOperation(object);
    }
    T getResult() {
        if (this->stack.isEmpty()) {
            throw std::invalid_argument("Invalid expression: stack is empty!");
        } else if (this->stack.size() > 1) {
            this->stack.clear();
            throw std::invalid_argument("Invalid expression: too many arguments!");
        } else {
            ValueObject<T>* pObject = this->stack.pop();
            T returnValue = pObject->getValue();
            delete(pObject);
            return returnValue;
        }
    }

    void clear() {
        while (!stack.isEmpty()) {
            ValueObject<T>* value = stack.pop();
            delete(value);
        }
    }
private:
    void handleOperation(ValueObject<T>* object) {
        if (stack.size() >= 2) {
            object->accept(stack);
            this->stack.push(object);
        } else {
            throw std::invalid_argument("Invalid expression: not enough arguments!");
        }
    }
    Stack<ValueObject<T>*> stack;
};

#endif //ZMPO_4B_STACKMACHINE_H
