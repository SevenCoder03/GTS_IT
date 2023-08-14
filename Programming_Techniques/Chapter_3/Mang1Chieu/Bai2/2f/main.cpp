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
    int Count_Chan=0;
    for (int i=0; i<n; i++)
    {
        if(a[i]%2 == 0)
        {
            Count_Chan++;
        }
    }
    int Count_Le = n - Count_Chan;
    if(Count_Chan > Count_Le) return -1;
    if(Count_Chan == Count_Le) return 0;
    return 1;
}
int main()
{
    int n,a[1000];
    nhap_Mang(a,n);
    cout<<check_Mang(a,n);
    return 0;
}
