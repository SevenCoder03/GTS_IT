#include "complex.h"

Complex operator*(Complex a, Complex b) {
    Complex c;
    c.real = a.real*b.real - a.imag*b.imag;
    c.imag = a.real*b.imag + b.real*a.imag;
    return c;
}

bool operator==(Complex a, Complex b) {
    if(a.real == b.real) {
        if(a.imag == b.imag)
            return true;
    }
    return false;
}

bool operator!=(Complex a, Complex b){
    if(a.real == b.real) {
        if(a.imag == b.imag)
            return false;
    }
    return true;
}

istream &operator>>(istream &in, Complex &c) {
    cout << "Enter real part: "; in >> c.real;
    cout << "Enter imag part: "; in >> c.imag;
    return in;

}

ostream &operator<<(ostream &out, Complex c) {
    if(c.imag < 0) {
        out << c.real << c.imag << "i\n";
    }
    else {
        out << c.real << "+" << c.imag << "i\n";
    }
    return out;
}

int main()
{
    Complex x, y;
    cin >> x >> y;
    cout << x;
    cout << y;
    cout << x*y;
    if(x == y)
        cout << "YES";

    if(x != y)
        cout << "NO";

    return 0;
}
