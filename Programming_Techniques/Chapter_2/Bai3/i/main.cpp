#include <iostream>
#include <math.h>
using namespace std;

double Solution(int n) {
    double Result = 0;
    for(int i=n; i>0; i--)
    {
        Result = sqrt(Result+i);
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
