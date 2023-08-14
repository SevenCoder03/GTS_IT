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
int UCLN(int a, int b)
{
    if (b == 0) return a;
    return UCLN(b, a % b);
}
int UCLN_Arr(int a[], int b[], int n)
{
    int x = a[0];
    for(int i=0; i<n; i++)
    {
        x = UCLN(x, a[i]);
    }
    return x;
}
int main()
{
    int n;
    int *a = new int[1000];
    int b[10] = {0};
    nhap_Mang(a, n);
    cout<<"UCLN cua mang la: "<<UCLN_Arr(a, b, n);
    delete []a;
    return 0;
}

