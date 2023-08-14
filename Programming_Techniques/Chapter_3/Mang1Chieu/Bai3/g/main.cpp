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
int check_Mang(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        if((a[i] % 10) % 2 != 0)
        {
            return a[i];
        }
    }
}
int main()
{
    int n, a[1000];
    nhap_Mang(a, n);
    cout<<"Phan tu co gia tri ma so cuoi la so le: "<<check_Mang(a, n);
    return 0;
}
