#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string FileName;
    char s;
    cout<<"Nhap ten file: ";
    cin>>FileName;

    ofstream FileOut;
    FileOut.open(FileName, ios_base::out);
    do
    {
        cin>>s;
        if(s != '/')
        FileOut << s << " ";
    }while(s != '/');
    FileOut << endl;

    ifstream FileIn;
    FileIn.open(FileName, ios_base::in);
    while(FileIn)
    {
        FileIn >> s;
        cout <<s;
    }
    cout<<endl;

    FileIn.close();
    FileOut.close();
    return 0;
}
