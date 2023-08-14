#include <iostream>
#include <string>
using namespace std;

int count_Number_S(string s)
{
    int Count = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            Count++;
        }
    }
    return Count;
}

void delete_S(string &s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            s.erase(i, 1);
            i--;
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    cout<<"So ky tu so: "<<count_Number_S(s)<<endl;
    delete_S(s);
    cout<<"Chuoi sau khi xoa: "<<s<<endl;
    return 0;
}
