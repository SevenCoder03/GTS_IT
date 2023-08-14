#include "Rational.h"

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
    do {
        if(denominator == 0) {
            cout << "\nDenominator other than 0 !!! Please enter denominator: "; cin >> denominator;
        }
    } while(denominator == 0);
    if(denominator < 0) {
        this->numerator = - numerator;
        this->denominator = - denominator;
    }
    else {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    if(this->numerator != 0) {
        this->Reduce();
    }
}

Rational::Rational(const Rational &x) {
    this->numerator = x.numerator;
    this->denominator = x.denominator;
}

int GCD(int a, int b) {
	while(a!=b){
		if(a>b)
            a-=b;
		else
            b-=a;
	}
	return a;
}

Rational Rational::Reduce() {
    int a = abs(this->numerator);
	int b = abs(this->denominator);
    int gcd = GCD(a, b);
	this->numerator /= gcd;
	this->denominator /= gcd;
	return *this;
}

Rational Rational::operator=(const Rational &x) {
    this->numerator = x.numerator;
    this->denominator = x.denominator;
}

Rational Rational::operator+(const Rational &x) {
    Rational res;
    res.numerator = this->numerator*x.denominator + x.numerator*this->denominator;
    res.denominator = this->denominator*x.denominator;
    res.Reduce();
    return res;
}

Rational Rational::operator-(const Rational &x) {
    Rational res;
    res.numerator = this->numerator*x.denominator - x.numerator*this->denominator;
    res.denominator = this->denominator*x.denominator;
    res.Reduce();
    return res;
}

Rational Rational::operator*(const Rational &x) {
    Rational res;
    res.numerator = this->numerator * x.numerator;
    res.denominator = this->denominator * x.denominator;
    res.Reduce();
    return res;
}

Rational Rational::operator/(const Rational &x)
{
    Rational res;
    if(x.numerator == 0) {
        res.denominator = 0;
    }
    else {
        res.numerator = this->numerator * x.denominator;
        res.denominator = this->denominator * x.numerator;
        res.Reduce();
    }
    return res;
}

bool Rational::operator==(const Rational &x) {
    double a = numerator * 1.0 / denominator;
    double b = x.numerator * 1.0 / x.denominator;
    if(a == b)
        return true;
    return false;
}

bool Rational::operator>(const Rational &x) {
    double a = numerator * 1.0 / denominator;
    double b = x.numerator * 1.0  / x.denominator;
    if(a > b)
        return true;
    return false;
}

bool Rational::operator<(const Rational &x) {
    double a = numerator * 1.0 / denominator;
    double b = x.numerator * 1.0 / x.denominator;
    if(a < b)
        return true;
    return false;
}

bool Rational::operator!=(const Rational &x) {
    double a = numerator * 1.0 / denominator;
    double b = x.numerator * 1.0 / x.denominator;
    if(a != b)
        return true;
    return false;
}

Rational Rational::operator+(const int &n) {
    Rational res;
    res.numerator = this->numerator + n*this->denominator;
    res.denominator = this->denominator;
    res.Reduce();
    return res;
}

Rational operator+(const int &n, const Rational &x) {
    Rational res;
    res.numerator = n*x.denominator + x.numerator;
    res.denominator = x.denominator;
    res.Reduce();
    return res;
}

istream &operator>>(istream &in, Rational &x) {
    cout << "Enter numerator: ";
    in >> x.numerator;
    cout << "Enter denominator: ";
    in >> x.denominator;
    if(x.denominator < 0) {
        x.numerator = - x.numerator;
        x.denominator = - x.denominator;
    }
    if(x.numerator != 0) {
        x.Reduce();
    }
    return in;
}

ostream &operator<<(ostream &out, Rational x) {
    if(x.denominator == 0) {
        out << "Invalid Rational !!!";
    }
    else if(x.numerator == 0) {
        out << 0;
    }
    else if(x.denominator == 1) {
        out << x.numerator;
    }
    else {
        out << x.numerator << "/" << x.denominator;
    }
    return out;
}

Rational::~Rational() {}
