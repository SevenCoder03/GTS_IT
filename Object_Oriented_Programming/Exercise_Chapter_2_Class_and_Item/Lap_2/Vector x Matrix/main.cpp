#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

int main()
{
    Vector a;
    a.Import();
    a.Display();
    Matrix b;
    b.Import();
    b.Display();
    Multiply(b, a);
    return 0;
}
