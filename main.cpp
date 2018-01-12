#include "test/RationalTest.h"
#include "stack-calculator/StackCalculator.h"
#include "rational/Rational.h"

int main() {
//    RationalTest::run();

    StackCalculator<Rational> stackCalculator;
    stackCalculator.run();
}