cmake_minimum_required(VERSION 3.7)
project(ZMPO_4B)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp utils/Stack.h rational/Rational.cpp rational/Rational.h rational/RationalUtils.cpp rational/RationalUtils.h test/RationalTest.cpp test/RationalTest.h)
add_executable(ZMPO_4B ${SOURCE_FILES})