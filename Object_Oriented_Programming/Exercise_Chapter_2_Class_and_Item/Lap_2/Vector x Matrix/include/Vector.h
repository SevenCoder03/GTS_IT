#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "Matrix.h"
using namespace std;

class Matrix;

class Vector
{
    private:
        int n;
        int *v;
    public:
        Vector();
        Vector(int n);
        ~Vector();
        void Import();
        void Display();
        friend Vector Multiply(Matrix x, Vector y);
};

#endif
