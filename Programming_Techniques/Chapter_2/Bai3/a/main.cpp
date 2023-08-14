#include<iostream>
using namespace std;

int sum(int n) {
    if (n == 1) return 1;
    return sum(n - 1) + n;
}
int main() {
    int n;
    do {
        cout << "Nhap n: ";
        cin >> n;
    } while (n <= 0);
    cout << "Tong cua day so la: " << sum(n)<<endl;
    return 0;
}
