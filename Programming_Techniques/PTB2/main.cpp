#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c, del, x1, x2;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "Nhap c = ";
    cin >> c;
    if(a == 0)
    {
        if(b == 0)
        {
            if (c == 0)
                {
                cout << "Phuong trinh vo so nghiem" << endl;
            } else
            {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else
        {
            cout << "Phuong trinh co nghiem duy nhat: x=" << -c/b << endl;
        }
    }
    else
    {
        del = pow(b, 2) - 4*a*c;
        if(del > 0)
        {
            x1 = (float)(-b+sqrt(del))/(2*a);
            x2 = (float)(-b-sqrt(del))/(2*a);
            cout << "Nghiem thu nhat x1 = " << x1 << endl;
            cout << "Nghiem thu hai x2 = " << x2 << endl;
        }
        else if ( del == 0)
        {
            cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -b/2*a << endl;
        }
        else
        {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    }
    return 0;
}
