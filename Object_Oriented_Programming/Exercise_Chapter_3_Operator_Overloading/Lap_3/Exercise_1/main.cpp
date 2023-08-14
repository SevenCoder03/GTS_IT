#include "Rational.h"
#include <iostream>
using namespace std;

int main()
{
    Rational a(3,5);
    Rational b(2,5);
    Rational c(2,1);
    Rational d(c);
    Rational e;
    Rational i;
    cout << "The first rational (A) should be 2/5 : " << a << endl;
    cout << "The second rational (B) should be 8/5 : " << b << endl;
    cout << "The third rational (C) should be 2 : " << c << endl;
    cout << "The fourth rational (D) should be like (c) = 2 : " << d << endl;
    cout << "The fifth rational (E) should be 0 : " << e << endl;
    cout << "\n\nEnter I " << endl;
    cin >> i;
    cout << i << endl;
    cout << "\n\nArithmathics operations"<< endl;
    cout << "========================"<< endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << c << " - " << b << " = " << c - b << endl;
    cout << b << " - " << c << " = " << b - c << endl;
    cout << c << " * " << b << " = " << c * b << endl;
    cout << b << " / " << a << " = " << b / a << endl;
    cout << "\n\nLogical operations" << endl;
    cout << "===================" << endl;
    cout << a << " > " << b << " should be False: " << (a>b) << endl;
    cout << a << " < " << b << " should be True: " << (a<b) << endl;
    cout << a << " == " << b << " should be False: " << (a==b) << endl;
    cout << a << " != " << b << " should be True: " << (a!=b) << endl;
    cout << c << " == " << d << " should be True: " << (c==d) << endl;
    cout << "\n\nArithmathics operations" << endl;
    cout << "========================" << endl;
    cout << a <<" + 2 = " << a + 2 << endl;
    cout << "2 + " << a << " = " << 2 + a << endl;
    cout << "\n\nDivision by Zero" << endl;
    cout << "=================" << endl;
    cout << "Rational g(3,0): ";
    Rational g(3,0);
    cout << g << endl;
    Rational h(0,1);
    cout << "\n\nDivide by zero - a/h should not give abnormal exit: " << a/h << endl;
    cout << "============================== " << endl;
    cout << "Good Luck" << endl;
}
