#include <iostream>
#include <string>
using namespace std;

struct DOIBONG
{
    char MaDoiBong[5];
    char TenDoiBong[30];
    string DanhSach[30];
};

void input(DOIBONG &x, int &n)
{
    cin.getline(x.MaDoiBong,5);
    cin.getline(x.TenDoiBong,30);
    cout<<"So luong cau thu: ";
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        getline(cin, x.DanhSach[i]);
    }
}

void output(DOIBONG x, int n)
{
    cout<<"\nMa doi bong: "<<x.MaDoiBong<<endl;
    cout<<"Ten doi bong: "<<x.TenDoiBong<<endl;
    cout<<"Danh sach thanh vien: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". "<<x.DanhSach[i]<<endl;
    }
}

int main()
{
    int n;
    DOIBONG a;
    input(a, n);
    output(a, n);
    return 0;
}
