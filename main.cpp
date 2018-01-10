#include <iostream>
#include <stdexcept>
#include "test/RationalTest.h"
#include "utils/Stack.h"
#include "stack-machine/operators/Value.h"
#include "stack-machine/operators/Add.h"
#include "stack-machine/StackMachine.h"
#include "stack-calculator/StackCalculator.h"

int main() {
//    RationalTest::run();

    Value<int>* val1 = new Value<int>(10);
    Value<int>* val2 = new Value<int>(12);
    Add<int>* result = new Add<int>;

    Stack<ValueObject<int>*> stack;

    stack.push(val1);
    stack.push(val2);
    stack.push(result);

    ValueObject<int>* object = stack.pop();
    object->accept(stack);

    std::cout << stack.isEmpty() << std::endl;
    std::cout << object->getValue() << std::endl;

    StackCalculator<int> stackCalculator;
    stackCalculator.run();
}