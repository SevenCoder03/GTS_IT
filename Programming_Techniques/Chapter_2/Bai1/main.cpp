#include <iostream>

using namespace std;

int main()
{
    char s;
    cin>>s;
    if(s >= 'A' && s <= 'Z')
    {
        cout<<s<<" la chu in hoa";
    }
    else if(s >= 'a' && s <= 'z')
    {
        cout<<s<<" la chu thuong";
    }
    else
    {
        cout<<s<<" khong phai chu cai";
    }
    cout<<endl;
    return 0;
}
