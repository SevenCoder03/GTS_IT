#include <iostream>

using namespace std;

void nhap_Mang(int arr[], int &n)
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
        cin>>arr[i];
    }
}
void add_x(int i, int &n, int a[], int x)
{
    for(int j=n; j>i; j--)
    {
        a[j] = a[j-1];
    }
    a[i] = x;
    n++;
}
void fix_Arr(int a[], int &n, int x)
{
    if(x >= a[n-1])
    {
        a[n] = x;
        n++;
    }
    else
    {
        for(int i=0; i<n-1; i++)
        {
            if(x >= a[i] && x <= a[i+1])
            {
                add_x(i+1, n, a, x);
                break;
            }
        }
    }
}
void xuat_Mang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n, x;
    int *a = new int[1000];
    nhap_Mang(a, n);
    cout<<"\nNhap x: ";
    cin>>x;
    fix_Arr(a, n, x);
    cout<<"\nMang ket qua: ";
    xuat_Mang(a, n);
    delete []a;
    return 0;
}

