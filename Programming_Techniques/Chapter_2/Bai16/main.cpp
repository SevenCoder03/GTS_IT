#include <iostream>
#include <math.h>
using namespace std;

int D2B(int n)
{
    double Result=0,m;
    for(int i=0;n>0;i++)
    {
        m=n%2;
        Result+=m*pow(10,i);
        n/=2;
    }
    return Result;
}

int D2O(int n)
{
    double Result=0,m;
    for(int i=0;n>0;i++)
    {
        m=n%8;
        Result+=m*pow(10,i);
        n/=8;
    }
    return Result;
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"So thap phan "<<n<<" chuyen sang nhi phan la: "<<D2B(n)<<endl;
    cout<<"So thap phan "<<n<<" chuyen sang bat phan la: "<<D2O(n)<<endl;
    return 0;
}
