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
        cout<<"Nhap phan tu "<<"["<<i<<"]: ";
        cin>>arr[i];
    }
}
void Sap_Xep(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
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
    int n;
    int *a = new int[1000];
    nhap_Mang(a, n);
    Sap_Xep(a, n);
    cout<<"\nMang ket qua: ";
    xuat_Mang(a, n);
    delete []a;
    return 0;
}
