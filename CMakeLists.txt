cmake_minimum_required(VERSION 3.7)
project(ZMPO_4B)

set(CMAKE_CXX_STANDARD 11)

set(
        SOURCE_FILES
        main.cpp
        utils/Stack.h
        rational/Rational.cpp
        rational/Rational.h
        rational/RationalUtils.cpp
        rational/RationalUtils.h
        test/RationalTest.cpp
        test/RationalTest.h
        stack-machine/StackMachine.cpp
        stack-machine/StackMachine.h
        stack-machine/operators/ValueObject.cpp
        stack-machine/operators/ValueObject.h
        stack-machine/operators/Value.cpp
        stack-machine/operators/Value.h
        stack-machine/operators/Negate.cpp
        stack-machine/operators/Negate.h
        stack-machine/operators/Add.cpp
        stack-machine/operators/Add.h
        stack-machine/operators/Subtract.cpp
        stack-machine/operators/Subtract.h
        stack-machine/operators/Multiply.cpp
        stack-machine/operators/Multiply.h
        stack-machine/operators/Divide.cpp
        stack-machine/operators/Divide.h
        utils/CharUtils.cpp
        utils/CharUtils.h
        stack-calculator/StackCalculator.cpp stack-calculator/StackCalculator.h)
add_executable(ZMPO_4B ${SOURCE_FILES})