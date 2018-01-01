#include <iostream>
#include <stdexcept>
#include "test/RationalTest.h"
#include "utils/Stack.h"
#include "rational/RationalUtils.h"
#include "rational/Rational.h"

int main() {
    RationalTest::run();

    Stack<int> stack;
    stack.push(10);
    stack.push(12);

    std::cout << stack.isEmpty() << " " << stack.pop() << std::endl;
    std::cout << stack.isEmpty() << " " << stack.pop() << std::endl;
    try {
        std::cout << stack.isEmpty() << " " << stack.pop() << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}