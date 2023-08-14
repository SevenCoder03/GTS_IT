#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    string fileName;
    char input;
    cout << "Ten tap tin: ";
    cin>>fileName;

    ofstream fileOut(fileName);
    do
    {
        input=cin.get();
        fileOut << input << ' ';
    }while(input != '.');
    fileOut << endl;

    ifstream fileIn(fileName);
    while(fileIn)
    {
        char input;
        fileIn >> input;
        cout << input;
    }
    cout << endl;

    fileOut.close();
    fileIn.close();
    return 0;
}
