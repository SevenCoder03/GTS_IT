#include <iostream>

using namespace std;

int main()
{
    int h;
    cin>>h;
    cout<<endl;
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=h+i-1; j++)
        {
            if(j == h - i + 1 || j == h + i - 1 || i == h)
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
