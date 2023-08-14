#include<iostream>
using namespace std;
int sum(int n) {
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        if(i % 2 ==0)
        {
           sum += i;
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
    cout << "Tong so chan cua day so la: " << sum(n)<<endl;
    return 0;
}
