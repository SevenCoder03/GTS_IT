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
bool ktdoixung(int a[100][100], int n, int m)
{
    if (n!=m) return false;
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
            if (a[i][j]!=a[j][i])
                return false;
    return true;
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
    outputArray(n, m, a);
    if(ktdoixung(a, n, m) == true)
        cout<<"\nMa tran doi xung!!!\n";
    else
        cout<<"\nMa tran khong doi xung!!!\n";
    return 0;
}
