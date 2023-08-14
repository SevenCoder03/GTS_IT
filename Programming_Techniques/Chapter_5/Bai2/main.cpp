#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

struct ToaDo
{
    ll x, y;
};

void Input(ToaDo& t)
{
    cin >> t.x >> t.y;
}

void Output(const ToaDo& t)
{
    cout << "(" << t.x << ", " << t.y << ")";
}

double Dis(const ToaDo& a, const ToaDo& b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    ToaDo a, b;
    cout << "Nhap toa do diem A: ";
    Input(a);
    cout << "Nhap toa do diem B: ";
    Input(b);
    cout << "Toa do diem A: ";
    Output(a);
    cout << endl;
    cout << "Toa do diem B: ";
    Output(b);
    cout << endl;
    cout << "Khoang cach giua hai diem: " << Dis(a, b);
    return 0;
}
