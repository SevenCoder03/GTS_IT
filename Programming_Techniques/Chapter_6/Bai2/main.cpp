#include <iostream>
#include <fstream>

using namespace std;

bool check_Prime(int x)
{
    if(x < 2)
        return false;
    for(int i=2; i*i<=x; i++)
    {
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    string FileName;
    int x;
    cout<<"Nhap ten file: ";
    cin>>FileName;

    //Câu a
    fstream FileOut(FileName, ios::out|ios::binary);
    int Count = 0;
    for(int i = 1; ; i++)
    {
        if(check_Prime(i) == true)
        {
             FileOut.write(reinterpret_cast <char *>(&i), sizeof(int));
             Count++;
        }
        if(Count == 50)
        {
            break;
        }
    }
    FileOut << endl;
    FileOut.close();

    //Câu b
    fstream FileIn(FileName, ios::in|ios::binary);
    while(FileIn.read(reinterpret_cast<char *>(&x), sizeof(int)))
    {
        cout << x << " ";
    }
    cout<<endl;
    FileIn.close();

    /*Câu c
    ofstream FileOut1, FileOut2;
    FileIn.open(FileName, ios::in);
    FileOut1.open("FileChan", ios::out);
    FileOut2.open("FileLe", ios::out);
    while(!FileIn.eof())
    {
        FileIn >> x;
        if(x % 2 == 0)
        {
            FileOut1 << x <<" ";
        }
        else
        {
            FileOut2 << x <<" ";
        }
    }
    FileOut1 << endl;
    FileOut2 << endl;
    FileIn.close();
    FileOut1.close();
    FileOut2.close();

    //Câu d
    FileOut2.open("FileLe", ios::app);
    FileOut2 << 2015 << " ";
    FileOut2.close();*/
    return 0;
}
