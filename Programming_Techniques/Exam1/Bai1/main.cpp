#include <iostream>
#include <math.h>
using namespace std;

double Bai1a(double x, int n)
{
    double Sum = 0;
    for(int i = 0; i <= n; i++)
    {
        Sum += pow(x, 2*i + 1);
    }
    return Sum;
}

double Bai1b(double x, int n)
{
    if(n == 0)
        return x;
    return pow(x, 2*n + 1) + Bai1b(x, n-1);
}

int main()
{
    double x;
    int n;
    cout<<"Nhap x: ";
    cin>>x;
    cout<<"Nhap n: ";
    cin>>n;
    cout<<"1a: "<<Bai1a(x, n)<<endl;
    cout<<"1b: "<<Bai1b(x, n)<<endl;
    return 0;
}
