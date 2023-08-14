#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void Compact(Fraction &x) {
    int GCD = gcd(x.numerator, x.denominator);
    x.numerator /= GCD;
    x.denominator /= GCD;
}

void Input(Fraction &x) {
    cout << "Enter numerator: "; cin >> x.numerator;
    cout << "Enter denominator: "; cin >> x.denominator;
}

void Output(Fraction x) {
    if(x.denominator == 0) {
        cout << "Error !!! Denominator != 0 !!!" << endl;
    }
    else if(x.denominator < 0) {
        cout << -x.numerator << "/" << -x.denominator << endl;
    }
    else {
         cout << x.numerator << "/" << x.denominator << endl;
    }
}

void Add(Fraction a, Fraction b) {
    Fraction Res;
    Res.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
    Res.denominator = a.denominator*b.denominator;
    Compact(Res);
    Output(Res);
}

void Sub(Fraction a, Fraction b) {
    Fraction Res;
    Res.numerator = a.numerator*b.denominator - b.numerator*a.denominator;
    Res.denominator = a.denominator*b.denominator;
    Compact(Res);
    Output(Res);
}

void Mul(Fraction a, Fraction b) {
    Fraction Res;
    Res.numerator = a.numerator*b.numerator;
    Res.denominator = a.denominator*b.denominator;
    Compact(Res);
    Output(Res);
}

void Div(Fraction a, Fraction b) {
    Fraction Res;
    Res.numerator = a.numerator*b.denominator;
    Res.denominator = a.denominator*b.numerator;
    Compact(Res);
    Output(Res);
}

void allocateArr(Fraction *&Arr, int &n) {
    cout << "Enter number of elements: "; cin >> n;
    Arr = new Fraction[n];
}

void deleteArr(Fraction *Arr) {
    delete []Arr;
}

void inputArr(Fraction *Arr, int n) {
    for(int i=0; i < n; i++) {
        cout << "Enter  Fraction " << i+1 << endl;
        Input(*(Arr + i));
        Compact(*(Arr + i));
    }
}

void outputArr(Fraction *Arr, int n) {
    for(int i=0; i < n; i++) {
        Output(*(Arr + i));
    }
}

void maxArr(Fraction *Arr, int n) {
    double Max = 1.0*(*(Arr + 0)).numerator / (*(Arr + 0)).denominator;
    int index = 0;
    for(int i = 1; i < n; i++) {
        double temp = 1.0*(*(Arr + i)).numerator / (*(Arr + i)).denominator;
        if(Max < temp) {
            Max = temp;
            index = i;
        }
    }
    cout << "The largest element of the array: ";
    Output(*(Arr + index));
}

void minArr(Fraction *Arr, int n) {
    double Min = 1.0*(*(Arr + 0)).numerator / (*(Arr + 0)).denominator;
    int index = 0;
    for(int i = 1; i < n; i++) {
        double temp = 1.0*(*(Arr + i)).numerator / (*(Arr + i)).denominator;
        if(Min > temp) {
            Min = temp;
            index = i;
        }
    }
    cout << "The smallest element of the array: ";
    Output(*(Arr + index));
}

void sortArr(Fraction *Arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            double temp1 = 1.0*(*(Arr + i)).numerator / (*(Arr + i)).denominator;
            double temp2 = 1.0*(*(Arr + j)).numerator / (*(Arr + j)).denominator;
            if(temp1 > temp2) {
                swap(*(Arr + i), *(Arr + j));
            }
        }
    }
}

int main() {
    Fraction F1, F2;
    int n;
    Fraction *Arr = nullptr;

    cout << "Enter Fraction 1: " << endl;
    Input(F1);
    cout << "Enter Fraction 2: " << endl;
    Input(F2);
    cout << "Fraction 1: ";
    Output(F1);
    cout << "Fraction 2: ";
    Output(F2);
    cout << endl;
    cout << "Sum of 2 fractions: ";
    Add(F1, F2);
    cout << "Subtract of 2 fractions: ";
    Sub(F1, F2);
    cout << "Multiplication of 2 fractions: ";
    Mul(F1, F2);
    cout << "Division of 2 fractions: ";
    Div(F1, F2);
    cout << endl;
    system("pause");
    system("cls");

    allocateArr(Arr, n);
    inputArr(Arr, n);
    system("cls");
    cout << "Array Fraction:" << endl;
    outputArr(Arr, n);
    maxArr(Arr, n);
    minArr(Arr, n);
    cout << endl;

    sortArr(Arr, n);
    cout << "Array after sorting: " << endl;
    outputArr(Arr, n);
    deleteArr(Arr);
    return 0;
}
