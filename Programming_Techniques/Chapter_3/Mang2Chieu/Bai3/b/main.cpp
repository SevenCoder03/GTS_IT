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
void swap_Row(int a[100][100], int n, int m, int row1, int row2)
{
    for(int j=0;j<n;j++)
        swap(a[row1][j],a[row2][j]);
}
bool fix_Arr(int a[100][100], int n, int m)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i][0] > a[j][0])
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
    int n, m, a[100][100];;
    cout<<"Nhap so hang: ";
    cin>>n;
    cout<<"Nhap so cot: ";
    cin>>m;
    inputArray(n, m, a);
    fix_Arr(a, n, m);
    outputArray(n, m, a);
    return 0;
}
