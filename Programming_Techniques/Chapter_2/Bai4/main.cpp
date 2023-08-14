#include<iostream>
using namespace std;

int main()
{
    int a, b, n, s=0;
    cout<<"Nhap n: ";
    cin>>n;
    do
    {
        cout<<"Nhap a: ";
        cin>>a;
    }while(a >= n);
    do
    {
        cout<<"Nhap b: ";
        cin>>b;
    }while(b >= n);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((i+j) % a == 0 && (i+j) % b != 0)
                cout<< "(" <<i<< " ," <<j<<")"<<endl;
        }
    }
    return 0;
}
