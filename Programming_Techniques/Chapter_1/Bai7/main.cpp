#include <iostream>

using namespace std;

int main()
{
    double tt, dm, gia, Total;
    cin>>tt>>dm>>gia;
    Total = tt*gia;
    if(tt > 3*dm)
    {
        Total = Total + Total*0.3;
    }
    else if(tt > 2*dm)
    {
        Total+=Total*0.2;
    }
    else if(tt > dm)
    {
        Total+=Total*0.1;
    }
    cout<<Total;
    return 0;
}
