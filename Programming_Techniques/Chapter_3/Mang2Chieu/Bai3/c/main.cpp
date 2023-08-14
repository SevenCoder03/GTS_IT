#include <iostream>

using namespace std;

void inputArray(int n, int m, int a[100][100])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<"Nhap phan tu thu ["<<i<<"]["<<j<<"]: ";
            cin>>a[i][j];
        }
    }
    cout<<endl;
}
void sum_Row(int a[100][100],int b[100],int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            b[i]+=a[i][j];
        }
    }
}
void swap_Row(int a[100][100], int n, int m, int row1, int row2)
{
    for(int j=0;j<n;j++)
        swap(a[row1][j],a[row2][j]);
}
bool fix_Arr(int a[100][100], int b[100], int n, int m)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(b[i] > b[j])
            {
                swap_Row(a, n, m, i, j);
            }
        }
    }
}
void outputArray(int n, int m, int a[100][100])
{
    cout<<"Mang da nhap la: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n, m, a[100][100], b[100] = {0};
    cout<<"Nhap so hang: ";
    cin>>n;
    cout<<"Nhap so cot: ";
    cin>>m;
    inputArray(n, m, a);
    sum_Row(a, b, n, m);
    fix_Arr(a, b, n, m);
    outputArray(n, m, a);
    return 0;
}
