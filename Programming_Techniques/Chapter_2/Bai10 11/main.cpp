#include <iostream>

using namespace std;

int USCLN(int a, int b) {
    if (b == 0) return a;
    return USCLN(b, a % b);
}

int BSCNN(int a, int b) {
    return (a * b) / USCLN(a, b);
}


int main() {
 int a, b;
    cout << "Nhap so nguyen duong a = ";
    cin >> a;
    cout << "Nhap so nguyen duong b = ";
    cin >> b;
    cout<<"USCLN cua "<< a<<" va "<< b<<" la:"<<USCLN(a, b)<<endl;
    cout<<"BSCNN cua "<< a<<" va "<< b<<" la:"<<BSCNN(a, b);
    return 0;
}
