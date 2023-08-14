#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    ll r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

struct PhanSo
{
    ll Tu, Mau;
};

void Input(PhanSo& p)
{
    cin >> p.Tu >> p.Mau;
}

void Output(const PhanSo& p)
{
    cout << p.Tu << "/" << p.Mau << endl;
}

void Rutgon(PhanSo& p)
{
    ll l = gcd(p.Tu, p.Mau);
    p.Tu /= l;
    p.Mau /= l;
}

PhanSo Sum(const PhanSo& a, const PhanSo& b)
{
    PhanSo result;
    ll Mauchung = lcm(a.Mau, b.Mau);
    result.Tu = Mauchung / a.Mau * a.Tu + Mauchung / b.Mau * b.Tu;
    result.Mau = Mauchung;
    Rutgon(result);
    return result;
}

PhanSo Sub(const PhanSo& a, const PhanSo& b)
{
    PhanSo result;
    ll Mauchung = lcm(a.Mau, b.Mau);
    result.Tu = Mauchung / a.Mau * a.Tu - Mauchung / b.Mau * b.Tu;
    result.Mau = Mauchung;
    Rutgon(result);
    return result;
}

PhanSo Mul(const PhanSo& a, const PhanSo& b)
{
    PhanSo result;
    result.Tu = a.Tu * b.Tu;
    result.Mau = a.Mau * b.Mau;
    Rutgon(result);
    return result;
}

PhanSo Div(const PhanSo& a, const PhanSo& b)
{
    PhanSo result;
    result.Tu = a.Tu * b.Mau;
    result.Mau = a.Mau * b.Tu;
    Rutgon(result);
    return result;
}

int main()
{
    PhanSo a, b, tmp;
    cout << "Nhap phan so a: ";
    Input(a);
    cout << "Nhap phan so b: ";
    Input(b);
    tmp = Sum(a, b);
    cout << "Tong 2 phan so: ";
    Output(tmp);
    tmp = Sub(a, b);
    cout << "Hieu 2 phan so: ";
    Output(tmp);
    tmp = Mul(a, b);
    cout << "Tich 2 phan so: ";
    Output(tmp);
    tmp = Div(a, b);
    cout << "Thuong 2 phan so: ";
    Output(tmp);
    return 0;
}
