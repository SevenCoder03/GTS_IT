#include <iostream>

using namespace std;

int main()
{
    int h;
    cin>>h;
    cout<<endl;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=i; j++)
        {
           if(j==1 || j==i || i==h)
           {
               cout<<"* ";
           }
           else
           {
               cout<<"  ";
           }
        }
        cout<<endl;
    }
    return 0;
}
