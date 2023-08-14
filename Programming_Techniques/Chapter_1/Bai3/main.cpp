#include <iostream>

using namespace std;

int main()
{
    char n;
    cin>>n;
    if (n >= 'A' && n <= 'Z')
    {
        n+=32;
    }
    else if (n >='a' && n <= 'z')
    {
        n-=32;
    }
    cout<<n;
    return 0;
}
