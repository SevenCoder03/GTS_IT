#include <iostream>

using namespace std;

void inputArray(int n, int a[8][8])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"Nhap phan tu thu ["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
    cout<<endl;
}
void outputArray(int n, int a[8][8])
{
    cout<<"Mang da nhap la: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool check_SNT(int x)
{
    if(x < 2)
        return false;
    for(int i=2; i*i<=x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
int count_Array(int n, int a[8][8])
{
    int Count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(check_SNT(a[i][j]) == true)
                Count++;
        }
    }
    return Count;
}
int main()
{
    int n, a[8][8];
    cout<<"Nhap so hang/cot: ";
    cin>>n;
    inputArray(n, a);
    outputArray(n, a);
    cout<<"So luong so nguyen to la: "<<count_Array(n, a)<<endl;
}
