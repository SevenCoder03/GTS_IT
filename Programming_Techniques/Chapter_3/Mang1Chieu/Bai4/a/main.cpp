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
    if(x < 2)
        return false;
    for(int i=2; i*i<=x; i++)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int check_Mang(int a[], int n, int b[], int &j)
{
    for(int i=0; i < n; i++)
    {
        if(check_SNT(a[i]) == true)
        {
            b[j] = a[i];
            j++;
        }
    }
}
void xuat_Mang(int b[], int j)
{
    for(int i = 0; i < j; i++)
    {
        cout<<b[i]<<" ";
    }
}
int main()
{
    int n, j = 0;
    int *a = new int[1000], *b = new int[1000];
    nhap_Mang(a, n);
    check_Mang(a, n, b, j);
    cout<<"\nMang so nguyen to: ";
    xuat_Mang(b, j);
    delete []a;
    delete []b;
    return 0;
}
