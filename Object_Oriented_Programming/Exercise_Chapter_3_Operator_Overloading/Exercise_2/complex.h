#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}
    friend Complex operator*(Complex a, Complex b);
    friend bool operator==(Complex a, Complex b);
    friend bool operator!=(Complex a, Complex b);
    friend istream &operator>>(istream &in, Complex &c);
    friend ostream &operator<<(ostream &on, Complex c);
};
