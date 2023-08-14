#include <iostream>
#include <string>
using namespace std;

struct TINH
{
    short int MaTinh;
    char TenTinh[30];
    double DienTich;
};
void input(TINH &x)
{
    cin>>x.MaTinh;
    cin.ignore();
    cin.getline(x.TenTinh, 30);
    cin>>x.DienTich;
}

void output(TINH x)
{
    cout<<"\nMa Tinh: "<<x.MaTinh<<endl;
    cout<<"Ten Tinh: "<<x.TenTinh<<endl;
    cout<<"Dien Tich: "<<x.DienTich<<" Km^2"<<endl;
}
int main()
{
    TINH a;
    input(a);
    output(a);
    return 0;
}
