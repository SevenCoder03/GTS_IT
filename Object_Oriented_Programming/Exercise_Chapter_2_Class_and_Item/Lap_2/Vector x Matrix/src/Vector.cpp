#include "Vector.h"

Vector::Vector() {
    n = 0;
    v = nullptr;
}

Vector::Vector(int n) {
    this->n = n;
    if(n == 0) {
        v = nullptr;
    }
    else {
        v = new int[n];
    }
}

void Vector::Import() {
    if(n == 0) {
        cout << "Enter quantity of vector: "; cin >> n;
        v = new int[n];
    }
    cout << "\tImport vector" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Enter v[" << i << "]: "; cin >> v[i];
    }
}

void Vector::Display() {
    if(n == 0) {
        cout << "Vector of no values !!!";
    }
    else {
        cout << "\nVector: ";
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
    }
    cout << endl << endl;
}

Vector Multiply(Matrix x, Vector y) {
    cout << "\tStart Multiply Vector x Matrix" << endl;
    cout << "Please Enter Styles Of Vector" << endl;
    cout << "1. 1xN" << endl;
    cout << "2. Nx1" << endl;
    int s;
    cout << "Enter select: "; cin >> s;
    if(s == 1) {
        if(x.m != y.n) {
            cout << "\nError! The number of columns in the first matrix should be equal to the number of rows in the second!" << endl;
        }
        else {
            cout << "\nResult " << endl;
            Vector z(x.n);
            for(int i = 0; i < x.n; i++) {
                int Sum = 0;
                for(int j = 0; j < x.m; j++) {
                    Sum += x.a[j][i] * y.v[j];
                }
                z.v[i] = Sum;
            }
            z.Display();
        }
    }
    else {
        if(x.m != 1) {
            cout << "\nError! The number of columns in the first matrix should be equal to the number of rows in the second!" << endl;
        }
        else {
            cout << "\nResult " << endl;
            Matrix t(y.n, x.n);
            for(int i = 0; i < y.n; i++) {
                for(int j = 0; j < x.n; j++) {
                    t.a[i][j] = y.v[i] * x.a[0][j];
                }
            }
            t.Display();
        }
    }
}

Vector::~Vector(){
    delete []v;
}
