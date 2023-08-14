#include <iostream>
#include <math.h>
using namespace std;

double Sum(int n, double x)
{
    if(n==0)
        return 0;
    else
        return 1.0/(n*pow(x, n+1)) + Sum(n-1, x);
}
int main()
{
    int n;
    double x;
    cout<<"Nhap n: ";
    do
    {
        cin>>n;
        if(n<=0)
        {
            cout<<"Vui long nhap n > 0: ";
        }
    }while(n <= 0);
    cout<<"Nhap x: ";
    cin>>x;
    cout<<Sum(n,x);
    return 0;
}
