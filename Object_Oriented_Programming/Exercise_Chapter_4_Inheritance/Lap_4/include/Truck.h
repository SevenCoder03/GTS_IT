#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle
{
    protected:
        double capacity;
        bool automaticTransmission;
    public:
        Truck(string mfgName, double dealerCost, double capacity, bool automaticTransmission);
        ~Truck();
        friend ostream &operator<<(ostream &out, Truck x);
};

#endif // TRUCK_H
