#include <iostream>

using namespace std;

void nhap_Mang(int a[], int &n)
{
   do
    {
        cout<<"\nNhap so phan tu: ";
        cin>>n;
        if(n <= 0 || n > 1000)
        {
            cout<<"So phan tu khong hop le. Xin kiem tra lai !\n";
        }
    }while(n <= 0 || n > 1000);
    for (int i=0; i<n; i++)
    {
        cout<<"Nhap phan tu "<<"a["<<i<<"]: ";
        cin>>a[i];
    }
}
bool check_Fibonacci(int n)
{
    if (n < 0)
        return false;

    if (n < 2)
        return true;

    int i=3, a=0, a1=1, a2=1;
    while (a <= n)
    {
        a = a1 + a2;
        a1 = a2;
        a2 = a;
        i++;
        if(n == a)
        {
            return true;
        }
    }
    return false;
}
int check_Mang(int a[], int n)
{
    int Count=0;
    for (int i=0;i<n;i++)
    {
        if(check_Fibonacci(a[i]) == true)
        {
            Count++;
        }
    }
    return Count;
}
int main()
{
    int n,a[1000];
    nhap_Mang(a,n);
    cout<<check_Mang(a,n);
    return 0;
}
