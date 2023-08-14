#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    if(n < 2)
        return false;

    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }

    return true;
}

int findPrimeAfterN(int n) {
    n++;
    if(isPrime(n)) {
        return n;
    }
    findPrimeAfterN(n);
}

int main()
{
    int n;
    cout << "Enter prime number N: "; cin >> n;
    cout << "Prime number after N: " << findPrimeAfterN(n);
    return 0;
}
