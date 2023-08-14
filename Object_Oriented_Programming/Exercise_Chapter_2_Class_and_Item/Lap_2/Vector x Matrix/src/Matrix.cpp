#include "Matrix.h"

Matrix::Matrix() {
    m = 0;
    n = 0;
    a = nullptr;
}

Matrix::Matrix(int m, int n){
    this->m = m;
    this->n = n;
    if(m == 0 || n == 0) {
        a = nullptr;
    }
    else {
        a = new int *[m];
        for(int i = 0; i < m; i++) {
            a[i] = new int [n];
        }
    }
}

void Matrix::Import() {
    cout << "\tImport Matrix" << endl;
    if(m == 0 || n == 0) {
        if(m == 0) {
            cout << "Enter number rows: "; cin >> m;
        }
        if(n == 0) {
            cout << "Enter number columns: "; cin >> n;
        }
        a = new int *[m];
        for(int i = 0; i < m; i++) {
            a[i] = new int [n];
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Enter a[" << i << "][" << j << "]: "; cin >> a[i][j];
        }
    }
}

void Matrix::Display() {
    if(m == 0 || n == 0) {
        cout << "Matrix of no values !!!" << endl;
    }
    else {
        cout << "\nMatrix: " << endl;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

Matrix::~Matrix(){
    for(int i = 0; i < m; i++) {
        delete []a[i];
    }
    delete []a;
}
