#include <iostream>

using namespace std;

double Sum(int n)
{
    if(n==1)
        return 1;
    else
        return 1.0/(n*(n+1)/2) + Sum(n-1);
}
int main()
{
    int n;
    cout<<"Nhap n: ";
    do
    {
        cin>>n;
        if(n<=0)
        {
            cout<<"Vui long nhap n > 0: ";
        }
    }while(n <= 0);

    cout<<Sum(n);
    return 0;
}
