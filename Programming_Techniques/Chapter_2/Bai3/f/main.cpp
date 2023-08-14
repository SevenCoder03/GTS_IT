#include<iostream>
using namespace std;
double sum(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {   if(i % 2 != 0)
        {
            sum += 1.0/i;
        }
    }
    return sum;
}
int main() {
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0);
    cout << "Ket qua la: " << sum(n)<<endl;
    return 0;
}
