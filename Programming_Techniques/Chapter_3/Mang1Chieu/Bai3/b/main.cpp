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
bool check_SNT(int x)
{
    if (x < 2)
        return false;

    for (int i = 2; i*i <= x; i++)
    {
        if (x%i==0)
        {
            return false;
        }
    }
    return true;
}
int check_Mang(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(check_SNT(a[i]) == true)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n, a[1000];
    nhap_Mang(a, n);
    int Result = check_Mang(a, n);
    cout<<Result;
    return 0;
}
