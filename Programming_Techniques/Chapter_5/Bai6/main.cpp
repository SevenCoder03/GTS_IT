#include <iostream>

using namespace std;

struct NGAY
{
    int Ngay, Thang, Nam;
};

struct THOIGIAN
{
    int Gio, Phut;
};

struct VE
{
    char TenPhim[20];
    int GiaTien;
    THOIGIAN XuatChieu;
    NGAY NgayXem;
};

void input(VE &x)
{
    cin.getline(x.TenPhim, 20);
    cin>>x.GiaTien;
    cin>>x.XuatChieu.Gio>>x.XuatChieu.Phut;
    cin>>x.NgayXem.Ngay>>x.NgayXem.Thang>>x.NgayXem.Nam;
}

void output(VE x)
{
    cout<<"\nTen Phim: "<<x.TenPhim<<endl;
    cout<<"Gia Tien: "<<x.GiaTien<<"VND"<<endl;
    cout<<"Xuat Chieu: "<<x.XuatChieu.Gio<<":"<<x.XuatChieu.Phut<<endl;
    cout<<"Ngay xem: "<<x.NgayXem.Ngay<<"/"<<x.NgayXem.Thang<<"/"<<x.NgayXem.Nam<<endl;
}
int main()
{
    VE a;
    input(a);
    output(a);
    return 0;
}
