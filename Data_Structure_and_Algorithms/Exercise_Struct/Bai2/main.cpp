#include <iostream>
#include <math.h>
using namespace std;

struct Complex {
    double real;
    double imag;
};

void Input(Complex &x) {
    cout << "Enter real part: "; cin >> x.real;
    cout << "Enter imag part: "; cin >> x.imag;
}

void Output(Complex x) {
    if(x.imag < 0) {
        cout << x.real << x.imag << "i\n";
    }
    else {
        cout << x.real << "+" << x.imag << "i\n";
    }
}

void Add(Complex a, Complex b) {
    Complex Res;
    Res.real = a.real + b.real;
    Res.imag = a.imag + b.imag;
    Output(Res);
}

void Sub(Complex a, Complex b) {
    Complex Res;
    Res.real = a.real - b.real;
    Res.imag = a.imag - b.imag;
    Output(Res);
}

void Mul(Complex a, Complex b) {
    Complex Res;
    Res.real = a.real*b.real - a.imag*b.imag;
    Res.imag = a.real*b.imag + b.real*a.imag;
    Output(Res);
}

void Div(Complex a, Complex b) {
    Complex Res;
    Res.real = 1.0*(b.real*a.real + b.imag*a.imag)/(pow(b.real, 2) + pow(b.imag, 2));
    Res.imag = 1.0*(b.real*a.imag - a.real*b.imag)/(pow(b.real, 2) + pow(b.imag, 2));
    Output(Res);
}

void allocateArr(Complex *&Arr, int &n) {
    cout << "Enter number of elements: "; cin >> n;
    Arr = new Complex[n];
}

void deleteArr(Complex *Arr) {
    delete []Arr;
}

void inputArr(Complex *Arr, int n) {
    for(int i=0; i < n; i++) {
        cout << "Enter  Complex " << i+1 << endl;
        Input(*(Arr + i));
    }
}

void outputArr(Complex *Arr, int n) {
    for(int i=0; i < n; i++) {
        Output(*(Arr + i));
    }
}

void maxArr(Complex *Arr, int n) {
    double Max = sqrt(pow((*(Arr + 0)).real, 2) + pow(((*(Arr + 0)).imag), 2));
    int index = 0;
    for(int i = 1; i < n; i++) {
        double temp = sqrt(pow((*(Arr + i)).real, 2) + pow(((*(Arr + i)).imag), 2));
        if(Max < temp) {
            Max = temp;
            index = i;
        }
    }
    cout << "The largest element of the array: ";
    Output(*(Arr + index));
}

void minArr(Complex *Arr, int n) {
    double Min = sqrt(pow((*(Arr + 0)).real, 2) + pow(((*(Arr + 0)).imag), 2));
    int index = 0;
    for(int i = 1; i < n; i++) {
        double temp = sqrt(pow((*(Arr + 0)).real, 2) + pow(((*(Arr + 0)).imag), 2));
        if(Min > temp) {
            Min = temp;
            index = i;
        }
    }
    cout << "The smallest element of the array: ";
    Output(*(Arr + index));
}

void sortArr(Complex *Arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            double temp1 = sqrt(pow((*(Arr + i)).real, 2) + pow(((*(Arr + i)).imag), 2));
            double temp2 = sqrt(pow((*(Arr + j)).real, 2) + pow(((*(Arr + j)).imag), 2));
            if(temp1 > temp2) {
                swap(*(Arr + i), *(Arr + j));
            }
        }
    }
}

int main()
{
    Complex C1, C2;
    int n;
    Complex *Arr = nullptr;

    cout << "Enter Complex 1: " << endl;
    Input(C1);
    cout << "Enter Complex 2: " << endl;
    Input(C2);
    cout << "Complex 1: ";
    Output(C1);
    cout << "Complex 2: ";
    Output(C2);
    cout << endl;
    cout << "Sum of 2 complexs: ";
    Add(C1, C2);
    cout << "Subtract of 2 complexs: ";
    Sub(C1, C2);
    cout << "Multiplication of 2 complexs: ";
    Mul(C1, C2);
    cout << "Division of 2 complexs: ";
    Div(C1, C2);
    cout << endl;
    system("pause");
    system("cls");

    allocateArr(Arr, n);
    inputArr(Arr, n);
    system("cls");
    cout << "Array Complex:" << endl;
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
