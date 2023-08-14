#include <iostream>
#include <math.h>
using namespace std;
int sum(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
         sum+=pow(i, 2);
    }
    return sum;
}
int main() {
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0);
    cout << "Ket qua la: " << (double)sqrt(sum(n))<<endl;
    return 0;
}
