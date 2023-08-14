#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    cout << "Nhap n = ";
    cin >> n;
    int sqr = sqrt(n);
    if(sqr*sqr == n){
        cout << n << " la so chinh phuong!\n";
    }
    else {
        cout << n << " khong phai so chinh phuong!\n";
    }
    return 0;
}
