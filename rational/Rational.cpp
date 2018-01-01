#include <stdexcept>
#include <iostream>
#include "Rational.h"
#include "RationalUtils.h"

Rational::Rational(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("denominator must not be equal to 0!");
    }
    if (denominator < 0) {
        denominator *= -1;
        numerator *= -1;
    }
    int rationalGcd = gcd(numerator, denominator);
    if (rationalGcd != 1) {
        this->numerator = numerator/rationalGcd;
        this->denominator = denominator/rationalGcd;
    } else {
        this->numerator = numerator;
        this->denominator = denominator;
    }
}

Rational Rational::operator+(const Rational &rational) {
    int newNumerator = this->numerator * rational.denominator + rational.numerator * this->denominator;
    int newDenominator = this->denominator * rational.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator+(const int integer) {
    return Rational(this->denominator * integer + this->numerator, this->denominator);
}

Rational &Rational::operator+=(const Rational &rational) {
    int newNumerator = this->numerator * rational.denominator + rational.numerator * this->denominator;
    int newDenominator = this->denominator * rational.denominator;

    int rationalGcd = gcd(newNumerator, newDenominator);

    if (rationalGcd != 1) {
        this->numerator = newNumerator/rationalGcd;
        this->denominator = newDenominator/rationalGcd;
    } else {
        this->numerator = newNumerator;
        this->denominator = newDenominator;
    }

    return *this;
}

Rational &Rational::operator+=(const int integer) {
    this->numerator += integer * this->denominator;
    return *this;
}

Rational Rational::operator-(const Rational &rational) {
    int newNumerator = this->numerator * rational.denominator - rational.denominator * this->denominator;
    int newDenominator = this->denominator * rational.denominator;
    return Rational(newNumerator, newDenominator);
}

Rational Rational::operator-(const int integer) {
    return Rational(this->numerator - this->denominator * integer, this->denominator);
}

Rational &Rational::operator-=(const Rational &rational) {
    int newNumerator = this->numerator * rational.denominator - rational.numerator * this->denominator;
    int newDenominator = this->denominator * rational.denominator;

    int rationalGcd = gcd(newNumerator, newDenominator);

    if (rationalGcd != 1) {
        this->numerator = newNumerator/rationalGcd;
        this->denominator = newDenominator/rationalGcd;
    } else {
        this->numerator = newNumerator;
        this->denominator = newDenominator;
    }

    return *this;
}

Rational &Rational::operator-=(const int integer) {
    this->numerator += integer * this->denominator;
    return *this;
}

Rational Rational::operator*(const Rational &rational) {
    return Rational(this->numerator * rational.numerator, this->denominator * rational.denominator);
}

Rational Rational::operator*(const int integer) {
    return Rational(this->numerator * integer, this->denominator);
}

Rational &Rational::operator*=(const Rational &rational) {
    int newNumerator = this->numerator * rational.numerator;
    int newDenominator = this->denominator * rational.denominator;

    int rationalGcd = gcd(newNumerator, newDenominator);

    if (rationalGcd != 1) {
        this->numerator = newNumerator/rationalGcd;
        this->denominator = newDenominator/rationalGcd;
    } else {
        this->numerator = newNumerator;
        this->denominator = newDenominator;
    }

    return *this;
}

Rational &Rational::operator*=(const int integer) {
    int newNumerator = this->numerator * integer;

    int rationalGcd = gcd(newNumerator, this->denominator);

    if (rationalGcd != 1) {
        this->numerator = newNumerator/rationalGcd;
        this->denominator /= rationalGcd;
    } else {
        this->numerator = newNumerator;
    }

    return *this;
}

Rational Rational::operator/(const Rational &rational) {
    if (rational.denominator == 0) {
        throw std::invalid_argument("Cannot divide by 0!");
    } else {
        return Rational(this->numerator * rational.denominator, this->denominator * rational.numerator);
    }
}

Rational Rational::operator/(const int integer) {
    if (integer == 0) {
        throw std::invalid_argument("Cannot divide by 0!");
    } else {
        return Rational(this->numerator, this->denominator * integer);
    }
}

Rational &Rational::operator/=(const Rational &rational) {
    if (rational.denominator == 0) {
        throw std::invalid_argument("Cannot divide by 0!");
    } else {
        int newNumerator = this->numerator * rational.denominator;
        int newDenominator = this->denominator * rational.numerator;

        if (newDenominator < 0) {
            newDenominator *= -1;
            newNumerator *= -1;
        }

        int rationalGcd = gcd(newNumerator, newDenominator);

        if (rationalGcd != 1) {
            this->numerator = newNumerator/rationalGcd;
            this->denominator = newDenominator/rationalGcd;
        } else {
            this->numerator = newNumerator;
            this->denominator = newDenominator;
        }

        return *this;
    }
}

Rational &Rational::operator/=(const int integer) {
    if (integer == 0) {
        throw std::invalid_argument("Cannot divide by 0!");
    } else {
        int newDenominator = this->denominator * integer;

        if (newDenominator < 0) {
            newDenominator *= -1;
            this->numerator *= -1;
        }

        int rationalGcd = gcd(this->numerator, newDenominator);

        if (rationalGcd != 1) {
            this->numerator /= rationalGcd;
            this->denominator = newDenominator/rationalGcd;
        } else {
            this->denominator = newDenominator;
        }

        return *this;
    }
}


bool Rational::operator==(const Rational &rational) {
    return this->numerator == rational.numerator && this->denominator == rational.denominator;
}

bool Rational::operator==(const int integer) {
    return this->denominator == 1 && this->numerator == integer;
}

bool operator==(const int integer, const Rational &rational) {
    return rational.denominator == 1 && rational.numerator == integer;
}

bool Rational::operator>=(const Rational &rational) {
    if (this->denominator == rational.denominator) {
        return this->numerator >= rational.numerator;
    } else {
        return this->numerator * rational.denominator >= rational.numerator * this->denominator;
    }
}

bool Rational::operator>=(const int integer) {
    return this->numerator >= this->denominator * integer;
}

bool operator>=(const int integer, const Rational &rational) {
    return rational.denominator * integer >= rational.numerator;
}

bool Rational::operator<=(const Rational &rational) {
    if (this->denominator == rational.denominator) {
        return this->numerator <= rational.numerator;
    } else {
        return this->numerator * rational.denominator <= rational.numerator * this->denominator;
    }
}

bool Rational::operator<=(const int integer) {
    return this->numerator <= this->denominator * integer;
}

bool operator<=(const int integer, const Rational &rational) {
    return rational.denominator * integer <= rational.numerator;
}

bool Rational::operator<(const Rational &rational) {
    return !(*this >= rational);
}

bool Rational::operator<(const int integer) {
    return !(*this >= integer);
}

bool operator<(const int integer, const Rational &rational) {
    return !(integer >= rational);
}

bool Rational::operator>(const Rational &rational) {
    return !(*this <= rational);
}

bool Rational::operator>(const int integer) {
    return !(*this <= integer);
}

bool operator>(const int integer, const Rational &rational) {
    return !(integer <= rational);
}

std::ostream &operator<<(std::ostream &o, const Rational &rational) {
    o << rational.numerator;
    if (rational.denominator != 1) {
        o << "/" << rational.denominator;
    }
    return  o;
}

std::istream &operator>>(std::istream &i, Rational &rational) {
    std::string temp = "";
    getline(std::cin, temp);
    std::size_t slashPos = temp.find("/");
    if (slashPos != std::string::npos) {
        int tempNumerator = std::stoi(temp.substr(0, slashPos));
        int tempDenominator = std::stoi(temp.substr(slashPos + 1));

        if (tempDenominator < 0) {
            tempDenominator *= -1;
            tempNumerator *= -1;
        }

        int rationalGcd = gcd(tempNumerator, tempDenominator);

        if (rationalGcd != 1) {
            rational.numerator = tempNumerator/rationalGcd;
            rational.denominator = tempDenominator/rationalGcd;
        } else {
            rational.numerator = tempNumerator;
            rational.denominator = tempDenominator;
        }
    } else {
        int tempNumerator = std::stoi(temp);
        rational.numerator = tempNumerator;
        rational.denominator = 1;
    }
    return i;
}
