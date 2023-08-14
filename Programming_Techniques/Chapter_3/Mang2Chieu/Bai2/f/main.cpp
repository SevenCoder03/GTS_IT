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
int check_Array(int n, int a[8][8])
{
    int dem[10] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = abs(a[i][j]);
            while(a[i][j] != 0)
            {
                dem[a[i][j]%10]++;
                a[i][j]/=10;
            }
        }
    }
    int Max = 0;
    for(int i = 1; i < 10; i++)
    {
        if(dem[Max] < dem[i])
        {
            Max = i;
        }
    }
    cout<<"\nCac chu so xuat hien nhieu nhat: ";
    for(int i = 0; i < 10; i++)
    {
        if(dem[Max] == dem[i])
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int n, a[8][8];
    cout<<"Nhap so hang/cot: ";
    cin>>n;
    inputArray(n, a);
    outputArray(n, a);
    check_Array(n, a);
    return 0;
}
