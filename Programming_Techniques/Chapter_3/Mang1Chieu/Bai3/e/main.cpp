#include <iostream>

using namespace std;

void nhap_Mang(int a[], int &n, int &x)
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
    cout<<"Nhap x: ";
    cin>>x;
}
int check_Mang(int a[], int n, int x)
{
    int Value = abs(x - a[0]), Result = a[0];
    for (int i=0; i<n; i++)
    {
        if(Value < abs(x - a[i]))
        {
            Value = abs(x - a[i]);
            Result = a[i];
        }
    }
    return Result;
}
int main()
{
    int n, a[1000], x;
    nhap_Mang(a, n, x);
    cout<<"Phan tu co gia tri cach xa x nhat: "<<check_Mang(a, n, x);
    return 0;
}
