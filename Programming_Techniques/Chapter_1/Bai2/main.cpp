#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, Max;
    cin>>a>>b>>c>>d;
    Max = a;
    (b>Max) ? Max=b : (c>Max) ? Max=c : Max=d;
    cout<<Max;
    return 0;
}
