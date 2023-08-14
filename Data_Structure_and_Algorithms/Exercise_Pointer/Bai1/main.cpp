#include <iostream>

using namespace std;

int main()
{
    int *ptr1, *ptr2, a, b;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    ptr1 = &a;
    ptr2 = &b;
    cout << "Total of 2 numbers: " << *ptr1 + *ptr2 << endl;
    return 0;
}
