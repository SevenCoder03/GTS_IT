#include <iostream>

using namespace std;

int main()
{
    for(int i=1001; i<=9999; i++)
    {
        int t = i;
        int a, b, c, d;
        d = t%10;
        t/=10;
        c = t%10;
        t/=10;
        b = t%10;
        t/=10;
        a = t%10;
        if((a+b) % 2 != 0 && (c+d) % 2 ==0)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
