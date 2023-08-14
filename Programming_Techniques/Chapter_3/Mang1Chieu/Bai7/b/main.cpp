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
void check_Arr(int a[], int b[], int n)
{
    for(int i=0; i<n; i++)
    {
        while(a[i] != 0)
        {
            b[a[i]%10]++;
            a[i]/=10;
        }
    }
}
void xuat_Mang(int arr[])
{
    int Max = arr[0], index = 0;
    for(int i = 0; i < 10; i++)
    {
        cout<<"Chu so "<<i<<" xuat hien: "<<arr[i]<<" lan"<<endl;
        if(Max < arr[i])
        {
            Max = arr[i];
            index = i;
        }
    }
    cout<<"So xuat hien nhieu nhat la: "<<index;
}
int main()
{
    int n;
    int *a = new int[1000];
    int b[10] = {0};
    nhap_Mang(a, n);
    check_Arr(a, b, n);
    xuat_Mang(b);
    delete []a;
    return 0;
}

