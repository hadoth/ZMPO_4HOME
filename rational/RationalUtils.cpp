#include "RationalUtils.h"

int gcd(int l, int r) {
    int left = absolute(l);
    int right = absolute(r);

    int temp;
    while (right != 0) {
        temp = left % right;
        left = right;
        right = temp;
    }

    return  left;
}

int lcm(int l, int r) {
    int left = absolute(l);
    int right = absolute(r);
    return  left * right / (gcd(left, right));
}

int absolute(int value) {
    if (value < 0) {
        return  -value;
    } else {
        return value;
    }
}