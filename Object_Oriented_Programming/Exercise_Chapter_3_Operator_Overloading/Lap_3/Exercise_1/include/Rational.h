#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational
{
    private:
        int numerator;
        int denominator;
        Rational Reduce();
    public:
        Rational();
        Rational(int numerator, int denominator);
        Rational(const Rational &x);
        Rational operator=(const Rational &x);
        Rational operator+(const Rational &x);
        Rational operator-(const Rational &x);
        Rational operator*(const Rational &x);
        Rational operator/(const Rational &x);
        bool operator==(const Rational &x);
        bool operator>(const Rational &x);
        bool operator<(const Rational &x);
        bool operator!=(const Rational &x);
        Rational operator+(const int &n);
        friend Rational operator+(const int &n, const Rational &x);
        friend istream &operator>>(istream &in, Rational &x);
        friend ostream &operator<<(ostream &out, Rational x);
        ~Rational();
};

#endif // RATIONAL_H
