#include <iostream>

using namespace std;

struct NGAY
{
    int Ngay, Thang, Nam;
};

struct HOPSUA
{
    char NhanHieu[20];
    double TrongLuong;
    NGAY HanSuDung;
};

void input(HOPSUA &x)
{
    cin.getline(x.NhanHieu, 20);
    cin>>x.TrongLuong;
    cin>>x.HanSuDung.Ngay>>x.HanSuDung.Thang>>x.HanSuDung.Nam;
}

void output(HOPSUA x)
{
    cout<<"\nNhan hieu: "<<x.NhanHieu<<endl;
    cout<<"Trong luong: "<<x.TrongLuong<<"g"<<endl;
    cout<<"Han su dung: "<<x.HanSuDung.Ngay<<"/"<<x.HanSuDung.Thang<<"/"<<x.HanSuDung.Nam<<endl;
}
int main()
{
    HOPSUA a;
    input(a);
    output(a);
    return 0;
}
