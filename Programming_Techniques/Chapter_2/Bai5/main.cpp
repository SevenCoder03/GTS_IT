#include <iostream>
#include <math.h>
using namespace std;

bool checkSNT(int num)
{
    int Count = 0;
    for (int j = 2; j <= sqrt(num); j++)
    {
            if (num % j == 0)
            {
                Count++;
            }
    }
    if (Count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    for (int i = 2; i < 1000; i++)
    {
        if(checkSNT(i) == true && checkSNT(i+2) == true)
        {
            cout<<"("<<i<<" ,"<<i+2<<")"<<endl;
        }
    }
    return 0;
}
