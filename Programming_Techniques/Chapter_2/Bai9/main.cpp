#include <iostream>

using namespace std;

int main()
{
    for(int i=10; i<=99; i++)
    {
        int a, b, t=i;
        a = t%10;
        t/=10;
        b = t%10;
        if(a*b == 2*(a+b))
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
