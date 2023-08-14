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
    int Count = 0, Flag;
    for(int i = 0; i < n; i++)
    {
        Flag = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                Flag = 0;
                break;
            }
        }
        if(Flag == 1)
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
