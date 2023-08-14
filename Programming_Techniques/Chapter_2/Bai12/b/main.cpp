#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Nhap n: ";
    do
    {
        cin>>n;
        if(n<=0)
        {
            cout<<"Vui long nhap n <= 0: ";
        }
    }while(n<=0);

    for(int i = 1; i<=n; i++)
    {
        if(i == 1 || i == 2)
        {
            cout<<"F("<<i<<")= "<<1<<endl;
        }
        else
        {
            long long j = 3, a = 1, b = 1, c;
            while(j<=i)
            {
                c = a + b;
                a = b;
                b = c;
                j++;
            }
            cout<<"F("<<i<<")= "<<c<<endl;
        }
    }

    return 0;
}
