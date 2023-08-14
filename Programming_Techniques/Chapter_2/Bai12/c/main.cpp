#include <iostream>

using namespace std;

int main()
{
    int n;
    long long Sum=0;
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
            Sum+=1;
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
            Sum+=c;
        }
    }
    cout<<"Tong n so fibonacii: "<<Sum;
    return 0;
}
