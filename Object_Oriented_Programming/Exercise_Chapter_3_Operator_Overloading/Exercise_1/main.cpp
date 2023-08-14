#include <iostream>
#include "Fraction.h"
using namespace std;

Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

void Fraction::inputFraction()
{
    cout << "Enter numerator: "; cin >> this->numerator;
    cout << "Enter denominator: "; cin >> this->denominator;
}

void Fraction::outputFraction()
{
    cout << this->numerator << "/" << this->denominator << endl;
}

Fraction Fraction::compactFraction(){
	int a = abs(this->numerator);
	int b = abs(this->denominator);
	while(a!=b){
		if(a>b)
            a-=b;
		else
            b-=a;
	}
	this->numerator /= a;
	this->denominator /= a;
	return *this;
}

//Add
Fraction Fraction::operator+(Fraction x)
{
    Fraction res;
    res.numerator = this->numerator*x.denominator + x.numerator*this->denominator;
    res.denominator = this->denominator*x.denominator;
    res.compactFraction();
    return res;
}

Fraction Fraction::operator+(int x)
{
    Fraction res;
    res.numerator = this->numerator + x*this->denominator;
    res.denominator = this->denominator;
    res.compactFraction();
    return res;
}

Fraction operator+(int x, Fraction y)
{
    Fraction res;
    res.numerator = x*y.denominator + y.numerator;
    res.denominator = y.denominator;
    res.compactFraction();
    return res;
}

//Sub
Fraction Fraction::operator-(Fraction x)
{
    Fraction res;
    res.numerator = this->numerator*x.denominator - x.numerator*this->denominator;
    res.denominator = this->denominator*x.denominator;
    res.compactFraction();
    return res;
}

Fraction Fraction::operator-(int x)
{
    Fraction res;
    res.numerator = this->numerator - x*this->denominator;
    res.denominator = this->denominator;
    res.compactFraction();
    return res;
}

Fraction operator-(int x, Fraction y)
{
    Fraction res;
    res.numerator = x*y.denominator - y.numerator;
    res.denominator = y.denominator;
    res.compactFraction();
    return res;
}

//Mul
Fraction Fraction::operator*(Fraction x)
{
    Fraction res;
    res.numerator = this->numerator * x.numerator;
    res.denominator = this->denominator * x.denominator;
    res.compactFraction();
    return res;
}

Fraction Fraction::operator*(int x)
{
    Fraction res;
    res.numerator = this->numerator * x;
    res.denominator = this->denominator;
    res.compactFraction();
    return res;
}

Fraction operator*(int x, Fraction y)
{
    Fraction res;
    res.numerator = x*y.numerator;
    res.denominator = y.denominator;
    res.compactFraction();
    return res;
}

//Div
Fraction Fraction::operator/(Fraction x)
{
    Fraction res;
    res.numerator = this->numerator * x.denominator;
    res.denominator = this->denominator * x.numerator;
    res.compactFraction();
    return res;
}

Fraction Fraction::operator/(int x)
{
    Fraction res;
    res.numerator = this->numerator;
    res.denominator = this->denominator * x;
    res.compactFraction();
    return res;
}

Fraction operator/(int x, Fraction y)
{
    Fraction res;
    res.numerator = x*y.denominator;
    res.denominator = y.numerator;
    res.compactFraction();
    return res;
}

//Com
bool Fraction::operator==(Fraction x)
{
    double a = (double)x.numerator / x.denominator;
    double b = (double)numerator / denominator;
    if(a == b)
        return true;
    return false;
}

bool Fraction::operator!=(Fraction x)
{
    double a = (double)x.numerator / x.denominator;
    double b = (double)numerator / denominator;
    if(a != b)
        return true;
    return false;
}

bool Fraction::operator>(Fraction x)
{
    double a = (double)x.numerator / x.denominator;
    double b = (double)numerator / denominator;
    if(a > b)
        return true;
    return false;
}

bool Fraction::operator<(Fraction x)
{
    double a = (double)x.numerator / x.denominator;
    double b = (double)numerator / denominator;
    if(a < b)
        return true;
    return false;
}

bool Fraction::operator>=(Fraction x)
{
    double a = (double)x.numerator / x.denominator;
    double b = (double)numerator / denominator;
    if(a >= b)
        return true;
    return false;
}

bool Fraction::operator<=(Fraction x)
{
    double a = (double)x.numerator / x.denominator;
    double b = (double)numerator / denominator;
    if(a <= b)
        return true;
    return false;
}

//In, Out
istream &operator>>(istream &in, Fraction &x)
{
    cout << "Enter numerator: ";
    in >> x.numerator;
    cout << "Enter denominator: ";
    in >> x.denominator;
    return in;
}

ostream &operator<<(ostream &out, Fraction x)
{
    out << x.numerator << "/" << x.denominator << endl;
    return out;
}

int main()
{
    Fraction a;
    int b;
    cin >> a >> b;
    Fraction c = b + a;
    cout << c << endl;
    cout << b + a;
    return 0;
}
