#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Vector.h"
using namespace std;

class Vector;

class Matrix
{
    private:
        int m;
        int n;
        int **a;
    public:
        Matrix();
        Matrix(int m, int n);
        ~Matrix();
        void Import();
        void Display();
        friend Vector Multiply(Matrix x, Vector y);
};

#endif
