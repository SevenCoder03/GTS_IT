#include <iostream>
#include <math.h>
using namespace std;

double Solution(int n) {
    double Result = 0;
    while(n--)
    {
        Result = sqrt(Result+3);
    }
    return Result;
}
int main() {
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0);
    cout << "Ket qua la: " << Solution(n) <<endl;
    return 0;
}
