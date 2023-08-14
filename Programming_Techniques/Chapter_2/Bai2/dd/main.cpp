#include<iostream>
#include<math.h>

using namespace std;

int numberMax(int n) {
    if (n == 0) return 0;
    n = abs(n);
    int Max = 0;
    while (n > 0) {
        int tmp = n % 10;
        n /= 10;
        if (tmp > Max)
            Max = tmp;
    }
    return Max;
}

int main() {
    int n;
    cout << "Nhap vao so nguyen n: ";
    cin >> n;
    cout << "Chu so lon nhat la: " << numberMax(n) << endl;
    return 0;
}
