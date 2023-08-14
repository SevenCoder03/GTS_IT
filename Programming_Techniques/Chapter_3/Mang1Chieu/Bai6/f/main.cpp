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
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                for(int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = temp;
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
    int n;
    int *a = new int[1000];
    nhap_Mang(a, n);
    cout<<"\nMang ket qua: ";
    xuat_Mang(a, n);
    delete []a;
    return 0;
}

