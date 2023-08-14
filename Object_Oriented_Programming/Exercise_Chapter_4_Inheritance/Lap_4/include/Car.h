#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle
{
    private:
        string modelName;
        bool sunRoof;
    public:
        Car(string mfgName, double dealerCost, string modelName, bool sunRoof);
        ~Car();
        friend ostream &operator<<(ostream &out, Car x);
};

#endif // CAR_H
