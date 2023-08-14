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
bool check_SNT(int t)
{
    if(t < 2)
        return false;
    for(int i=2; i*i <= t; i++){
        if(t % i == 0)
            return false;
    }
    return true;
}
void add_x(int i, int &n, int x, int a[])
{
    for(int j=n; j > i; j--)
    {
        a[j] = a[j-1];
    }
    a[i] = x;
    n++;
}
void fix_Arr(int a[], int &n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(check_SNT(a[i]) == true)
        {
            add_x(i+1, n, x, a);
            i++;
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

