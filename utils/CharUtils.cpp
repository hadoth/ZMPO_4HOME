#include "CharUtils.h"

char ::CharUtils::toLowerCase(const char charToCheck) {
    if (charToCheck >= 65 && charToCheck <=90) {
        return charToCheck + 32;
    } else {
        return charToCheck;
    }
}

bool ::CharUtils::equals(const char *left, const char *right) {
    auto index = 0;

    while (left[index] != 0 || right[index] != 0) {
        if (toLowerCase(left[index]) != toLowerCase(right[index])) {
            return false;
        } else {
            index++;
        }
    }

    return true;
}