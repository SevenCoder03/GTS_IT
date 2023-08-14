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
int sum_Array(int n, int a[8][8])
{
    int Sum = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i != j)
            {
                Sum += a[i][j];
            }
        }
    }
    return Sum;
}
int main()
{
    int n, a[8][8];
    cout<<"Nhap so hang/cot: ";
    cin>>n;
    inputArray(n, a);
    outputArray(n, a);
    cout<<"Tong phan tu ngoai duong cheo chinh la: "<<sum_Array(n, a)<<endl;
}
