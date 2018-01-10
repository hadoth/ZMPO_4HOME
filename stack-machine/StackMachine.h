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
    void run() {
        bool shouldContinue = true;

        while (shouldContinue) {
            bool fillSuccessful = fillStack();
            shouldContinue = this->shouldContinue();
        }
    }

private:
    Stack<ValueObject<T>> stack;
    bool shouldContinue() {
        char answer[64];
        for (auto index = 0; index < 10; index++) {
            std::cout << "Would You like to continue? (Y/N)" << std::endl;
            std::cin >> answer;
            if (CharUtils::equals(answer, "y")) {
                return true;
            }
            if (CharUtils::equals(answer, "n")) {
                std::cout << "Bye!" << std::endl;
                return false;
            }
            std::cout << "Communicate not recognized!" << std::endl;
        }
        std::cout << "Critical number of iterations exceeded, the program will finish." << std::endl;
        return false;
    }
    bool fillStack() {
        char userInput[64];

        for (auto index = 0; index < 124; index++){
            std::cin >> userInput;
            if (CharUtils::equals(userInput, "+")) {
                Add<T> object;
                stack.push(object);
                continue;
            }
            if (CharUtils::equals(userInput, "-")) {
                Subtract<T> object;
                stack.push(object);
                continue;
            }
            if (CharUtils::equals(userInput, "*")) {
                Multiply<T> object;
                stack.push(object);
                continue;
            }
            if (CharUtils::equals(userInput, "/")) {
                Divide<T> object;
                stack.push(object);
                continue;
            }
            if (CharUtils::equals(userInput, "=")) {
                return true;
            }
            std::stringstream stream;
            for (auto charIndex = 0; charIndex < 64; charIndex++) {
                stream.put(userInput[charIndex]);
                if (userInput[charIndex] == 0) {
                    break;
                }
            }
            T value;
            stream >> value;
            Value<T> object(value);
            this->stack.push(object);
        }
        std::cout << "Maximum number of operators exceeded!" << std::endl;
        return false;
    }
};

#endif //ZMPO_4B_STACKMACHINE_H
