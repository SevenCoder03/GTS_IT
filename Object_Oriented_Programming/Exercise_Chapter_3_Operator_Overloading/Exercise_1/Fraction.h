//Fraction.h
#include <iostream>
#pragma once
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        void inputFraction();
        void outputFraction();
        Fraction compactFraction();

        Fraction operator+(Fraction x);
        Fraction operator+(int x);
        friend Fraction operator+(int x, Fraction y);

        Fraction operator-(Fraction x);
        Fraction operator-(int x);
        friend Fraction operator-(int x, Fraction y);

        Fraction operator*(Fraction x);
        Fraction operator*(int x);
        friend Fraction operator*(int x, Fraction y);

        Fraction operator/(Fraction x);
        Fraction operator/(int x);
        friend Fraction operator/(int x, Fraction y);

        bool operator==(Fraction x);
        bool operator!=(Fraction x);
        bool operator>(Fraction x);
        bool operator<(Fraction x);
        bool operator>=(Fraction x);
        bool operator<=(Fraction x);

        friend istream &operator>>(istream &in, Fraction &x);
        friend ostream &operator<<(ostream &out, Fraction x);
};

