#include <iostream>

using namespace std;

void cap_Arr2D(int **&a, int n, int m)
{
    a = new int* [n];
    for(int i=0; i<n; i++)
    {
        a[i] = new int [m];
    }
}
void input_Arr2D(int **a, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>*(*(a+i)+j);
        }
    }
}
void output_Arr2D(int **a, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<*(*(a+i)+j)<<" ";
        }
        cout<<endl;
    }
}
void thu_Arr(int **a, int n)
{
    for(int i=0; i < n; i++)
    {
        delete []a[i];
    }
    delete []a;
}

int main()
{
    int **a = nullptr;
    int n, m;
    cout<<"Nhap so hang: ";
    cin>>n;
    cout<<"Nhap so cot: ";
    cin>>m;
    cap_Arr2D(a, n, m);
    input_Arr2D(a, n, m);
    output_Arr2D(a, n, m);
    thu_Arr(a, n);
    return 0;
}
