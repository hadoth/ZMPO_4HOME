#include <iostream>
#include "RationalTest.h"
#include "../rational/Rational.h"

namespace RationalTest {
    void run() {
        std::cout << "Constructor" << std::endl;
        Rational r1(2, 4);
        Rational r2(1, 3);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "+" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 = r1 + 2;
        r2 = r2 + Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "+=" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 += 2;
        r2 += Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "-" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 = r1 - 2;
        r2 = r2 - Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "-=" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 -= 2;
        r2 -= Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "*" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 = r1 * 2;
        r2 = r2 * Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "*=" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 *= 2;
        r2 *= Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "/" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 = r1 / 2;
        r2 = r2 / Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "/=" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(1, 3);
        r1 /= 2;
        r2 /= Rational(1, 6);
        std::cout << r1 << std::endl;
        std::cout << r2 << std::endl;

        std::cout << "input" << std::endl;
        std::cin >> r1;
        std::cout << r1 << std::endl;
        std::cin >> r2;
        std::cout << r2 << std::endl;

        std::cout << "==" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(4, 2);
        std::cout << (r1 == r1) << std::endl;
        std::cout << (r2 == r2) << std::endl;
        std::cout << (r1 == r2) << std::endl;
        std::cout << (r2 == r1) << std::endl;
        std::cout << (r1 == 2) << std::endl;
        std::cout << (r2 == 2) << std::endl;
        std::cout << (2 == r1) << std::endl;
        std::cout << (2 == r2) << std::endl;
        std::cout << ">=" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(4, 2);
        std::cout << (r1 >= r1) << std::endl; //1
        std::cout << (r2 >= r2) << std::endl; //1
        std::cout << (r1 >= r2) << std::endl; //0
        std::cout << (r2 >= r1) << std::endl; //1
        std::cout << (r1 >= 2) << std::endl; //0
        std::cout << (r2 >= 2) << std::endl; //1
        std::cout << (2 >= r1) << std::endl; //1
        std::cout << (2 >= r2) << std::endl; //1
        std::cout << "<=" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(4, 2);
        std::cout << (r1 <= r1) << std::endl;
        std::cout << (r2 <= r2) << std::endl;
        std::cout << (r1 <= r2) << std::endl;
        std::cout << (r2 <= r1) << std::endl;
        std::cout << (r1 <= 2) << std::endl;
        std::cout << (r2 <= 2) << std::endl;
        std::cout << (2 <= r1) << std::endl;
        std::cout << (2 <= r2) << std::endl;
        std::cout << ">" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(4, 2);
        std::cout << (r1 > r1) << std::endl;
        std::cout << (r2 > r2) << std::endl;
        std::cout << (r1 > r2) << std::endl;
        std::cout << (r2 > r1) << std::endl;
        std::cout << (r1 > 2) << std::endl;
        std::cout << (r2 > 2) << std::endl;
        std::cout << (2 > r1) << std::endl;
        std::cout << (2 > r2) << std::endl;
        std::cout << "<" << std::endl;
        r1 = Rational(2, 4);
        r2 = Rational(4, 2);
        std::cout << (r1 < r1) << std::endl;
        std::cout << (r2 < r2) << std::endl;
        std::cout << (r1 < r2) << std::endl;
        std::cout << (r2 < r1) << std::endl;
        std::cout << (r1 < 2) << std::endl;
        std::cout << (r2 < 2) << std::endl;
        std::cout << (2 < r1) << std::endl;
        std::cout << (2 < r2) << std::endl;
    }
}