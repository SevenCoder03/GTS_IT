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
void check_Mang(int a[], int b[], int c[], int na, int nb, int &nc)
{
    nc = na + nb;
    int i = na-1, j = nb-1;
    for(int k = 0; k < nc; k++)
    {
        if(i != 0 && j != 0)
        {
            if(a[i] > b[j])
            {
                c[k] = a[i--];
            }
            else
            {
                c[k] = b[j--];
            }
        }
        else if(j < 0)
        {
            c[k] = a[i--];
        }
        else
        {
            c[k] = b[j--];
        }
    }
}
void xuat_Mang(int c[], int nc)
{
    for(int i = 0; i < nc; i++)
    {
        cout<<c[i]<<" ";
    }
}
int main()
{
    int na, nb, nc;
    int *a = new int[1000], *b = new int[1000], *c = new int[1000];
    nhap_Mang(a, na);
    nhap_Mang(b, nb);
    check_Mang(a, b, c, na, nb, nc);
    cout<<"\nMang ket qua: ";
    xuat_Mang(c, nc);
    delete []a;
    delete []b;
    delete []c;
    return 0;
}
