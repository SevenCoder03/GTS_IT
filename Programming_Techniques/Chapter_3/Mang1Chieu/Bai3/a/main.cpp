#include <iostream>

using namespace std;

void nhap_Mang(int a[], int &n,int &x)
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
    for(int i = n-1; i >= 0; i--)
    {
        if(a[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n, a[1000], x;
    nhap_Mang(a, n, x);
    int Result = check_Mang(a, n, x);
    cout<<Result;
    return 0;
}
