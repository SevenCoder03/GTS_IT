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
int check_Array(int n, int a[8][8])
{
    int dem[8] = {0};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] % 2 == 0)
            {
                dem[i]++;
            }
        }
    }
    int Max = dem[0];
    for(int i = 1; i < n; i++)
    {
        Max = (Max > dem[i]) ? Max : dem[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(Max == dem[i])
        {
            cout<<"\nDong "<<i<<" co so chan nhieu nhat: "<<Max<<" so \n";
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
