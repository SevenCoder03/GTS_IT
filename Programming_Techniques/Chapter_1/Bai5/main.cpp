#include <iostream>

using namespace std;

int main()
{
    double a, b, c, DTB;
    cout<<"Nhap diem Toan: ";
    cin>>a;
    cout<<"Nhap diem Ly: ";
    cin>>b;
    cout<<"Nhap diem Hoa: ";
    cin>>c;
    cout<<endl;
    cout<<"Diem trung binh: ";
    DTB=(a+b+c)/3;
    cout<<DTB<<endl;
    cout<<"Xep hang: ";
    if(DTB == 10)
    {
        cout<<"Xuat sac";
    }
    else if(DTB >= 8)
    {
        cout<<"Gioi";
    }
    else if(DTB >= 7)
    {
        cout<<"Kha";
    }
    else if(DTB >= 5)
    {
        cout<<"TB";
    }
    else
    {
        cout<<"Kém";
    }
    return 0;
}
