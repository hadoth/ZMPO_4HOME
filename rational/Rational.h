#ifndef ZMPO_4B_RATIONAL_H
#define ZMPO_4B_RATIONAL_H

/**
 *
 */
class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int numerator, int denominator);
    Rational(int numerator): numerator(numerator), denominator(1) {};
    Rational operator +(const Rational& rational);
    Rational operator +(const int integer);
    Rational& operator +=(const Rational& rational);
    Rational& operator +=(const int integer);
    Rational operator -(const Rational& rational);
    Rational operator -(const int integer);
    Rational& operator -=(const Rational& rational);
    Rational& operator -=(const int integer);
    Rational operator *(const Rational& rational);
    Rational operator *(const int integer);
    Rational& operator *=(const Rational& rational);
    Rational& operator *=(const int integer);
    Rational operator /(const Rational& rational);
    Rational operator /(const int integer);
    Rational& operator /=(const Rational& rational);
    Rational& operator /=(const int integer);
    bool operator ==(const Rational& rational);
    bool operator ==(const int integer);
    friend bool operator ==(const int integer, const Rational& rational);
    bool operator <=(const Rational& rational);
    bool operator <=(const int integer);
    friend bool operator <=(const int integer, const Rational& rational);
    bool operator >=(const Rational& rational);
    bool operator >=(const int integer);
    friend bool operator >=(const int integer, const Rational& rational);
    bool operator <(const Rational& rational);
    bool operator <(const int integer);
    friend bool operator <(const int integer, const Rational& rational);
    bool operator >(const Rational& rational);
    bool operator >(const int integer);
    friend bool operator >(const int integer, const Rational& rational);
    friend std::ostream& operator<<(std::ostream& o, const Rational& rational);
    friend std::istream& operator>>(std::istream& o, Rational& rational);
};


#endif //ZMPO_4B_RATIONAL_H
