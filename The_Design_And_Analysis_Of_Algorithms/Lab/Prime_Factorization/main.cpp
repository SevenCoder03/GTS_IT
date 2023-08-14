#include <iostream>

using namespace std;

void primeFactorization(long long i, long long n) {
    if(n == 1) {
        return;
    }
    while(n % i == 0) {
        cout << i;
        n /= i;
        if(n != 1) {
            cout << " * ";
        }
    }
    primeFactorization(i + 1, n);
}

int main()
{
    long long n;
    cout << "Enter n: "; cin >> n;
    primeFactorization(2, n);
    return 0;
}
