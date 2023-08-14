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
int check_Mang(int a[], int b[], int c[], int d[], int n, int &x, int &y, int &z)
{
    for(int i=0; i < n; i++)
    {
        if(a[i] > 0)
        {
            b[x] = a[i];
            x++;
        }
        else if(a[i] < 0)
        {
            c[y] = a[i];
            y++;
        }
        else
        {
            d[z] = a[i];
            z++;
        }
    }
}
void xuat_Mang(int q[], int p)
{
    for(int i = 0; i < p; i++)
    {
        cout<<q[i]<<" ";
    }
}
int main()
{
    int n, x = 0, y = 0, z = 0;
    int *a = new int[1000], *b = new int[1000], *c = new int[1000], *d = new int[1000];
    nhap_Mang(a, n);
    check_Mang(a, b, c, d, n, x, y, z);
    cout<<"\nMang so duong: ";
    xuat_Mang(b, x);
    cout<<"\nMang so am: ";
    xuat_Mang(c, y);
    cout<<"\nMang so 0: ";
    xuat_Mang(d, z);
    delete []a;
    delete []b;
    delete []c;
    delete []d;
    return 0;
}
