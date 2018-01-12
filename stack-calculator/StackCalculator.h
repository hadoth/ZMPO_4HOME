#ifndef ZMPO_4B_STACKCALCULATOR_H
#define ZMPO_4B_STACKCALCULATOR_H


#include "../stack-machine/StackMachine.h"

template <class T> class StackCalculator {
private:
    StackMachine<T> stackMachine;
    bool shouldContinue() {
        char answer[64];
        for (auto index = 0; index < 10; index++) {
            std::cout << "Would You like to continue? (Y/N)" << std::endl;
            std::cin >> answer;
            if (CharUtils::equals(answer, "y")) {
                std::cout << "---===|||===---" << std::endl;
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

    void readInput() {
        std::cout << "Please provide numbers and operators accordingly to the RPN rules." << std::endl;
        char userInput[64];

        for (auto index = 0; index < 124; index++) {
            try {
                std::cin >> userInput;
                if (CharUtils::equals(userInput, "+")) {
                    stackMachine.add();
                    continue;
                }
                if (CharUtils::equals(userInput, "-")) {
                    stackMachine.subtract();
                    continue;
                }
                if (CharUtils::equals(userInput, "*")) {
                    stackMachine.multiply();
                    continue;
                }
                if (CharUtils::equals(userInput, "/")) {
                    stackMachine.divide();
                    continue;
                }
                if (CharUtils::equals(userInput, "=")) {
                    T result = stackMachine.getResult();
                    std::cout << result << std::endl;
                    stackMachine.clear();
                    return;
                }
                std::stringstream stream;
                stream.clear();
                for (auto charIndex = 0; charIndex < 64; charIndex++) {
                    stream.put(userInput[charIndex]);
                    if (userInput[charIndex] == 0) {
                        break;
                    }
                }
                T value;
                stream >> value;
                stackMachine.value(value);
            } catch (std::invalid_argument e) {
                std::cout << e.what() << std::endl;
                stackMachine.clear();
                return;
            }
        }
        std::cout << "Maximum number of operators exceeded!" << std::endl;
    }
public:
    void run() {
        bool shouldContinue = true;

        while (shouldContinue) {
            readInput();
            shouldContinue = this->shouldContinue();
        }
    }
};


#endif //ZMPO_4B_STACKCALCULATOR_H
