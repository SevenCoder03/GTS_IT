#include <iostream>

using namespace std;

int main()
{
    int a, b, *ptr1, *ptr2;
    cout << "Enter a: "; cin >> a;
    cout << "Enter b: "; cin >> b;
    ptr1 = &a;
    ptr2 = &b;
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    cout << "After swaping" << endl;
    cout << a << " " << b;
    return 0;
}
