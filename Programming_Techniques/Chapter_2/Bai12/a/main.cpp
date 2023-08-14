#include <iostream>

using namespace std;

int Fibo1(int n)
{
    if (n == 1 || n == 2)
    return 1;
    return Fibo1(n - 1) + Fibo1(n - 2);
}
int Fibo2a(int n)
{
    int a[n];
    a[0] = 1;
    a[1] = 1;
    for(int i=2; i<n; i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    return a[n-1];
}
int Fibo2b(int n)
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        long long i = 3, a = 1, b = 1, c;
        while(i<=n)
        {
            c = a + b;
            a = b;
            b = c;
            i++;
        }
        return c;
    }
}

int Fibo2c(int n)
{
    int a[n][2];
    a[0][0]=1;
    a[0][1]=1;
    for(int i=1; i<n; i++)
    {
        a[i][0] = a[i-1][1];
        a[i][1] = a[i-1][0] + a[i-1][1];
    }
    return a[n-1][0];
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
            cout<<"Vui long nhap n <= 0: ";
        }
    }while(n<=0);
    cout<<Fibo1(n)<<endl;
    cout<<Fibo2a(n)<<endl;
    cout<<Fibo2b(n)<<endl;
    cout<<Fibo2c(n)<<endl;
    return 0;
}
