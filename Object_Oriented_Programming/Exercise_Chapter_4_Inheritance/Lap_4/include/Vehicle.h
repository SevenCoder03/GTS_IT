#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string.h>
using namespace std;

class Vehicle
{
    protected:
        string mfgName;
        double dealerCost;
    public:
        Vehicle(string mfgName, double dealerCost);
        ~Vehicle();
        double retailPrice();
        friend ostream &operator<<(ostream &out, Vehicle x);
};

#endif // VEHICLE_H
