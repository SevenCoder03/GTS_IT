#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout<<"Nhap he so cua mat phang Ax + By + Cz + D: "<<endl;
    double A, B, C, D;
    cin>>A>>B>>C>>D;
    cout<<"Nhap diem M(x,y,z): "<<endl;
    double x, y, z;
    cin>>x>>y>>z;
    double d;
    d = abs(A*x + B*y + C*z +D)/sqrt(A*A + B*B + C*C);
    cout<<d;
    return 0;
}
