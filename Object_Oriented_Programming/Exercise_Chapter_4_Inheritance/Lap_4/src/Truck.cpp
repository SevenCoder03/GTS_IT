#include "Truck.h"

Truck::Truck(string mfgName, double dealerCost, double capacity, bool automaticTransmission) : Vehicle(mfgName, dealerCost)
{
    this->capacity = capacity;
    this->automaticTransmission = automaticTransmission;
}

ostream &operator<<(ostream &out, Truck x) {
    out << "Manufacturer name: " << x.mfgName << endl;
    out << "Retail price: " << x.retailPrice() << endl;
    out << "Capacity: " << x.capacity << endl;
    out << "Automatic Transmission: ";
    if(x.automaticTransmission == true) {
        out << "Yes";
    }
    else {
        out << "No";
    }
    out << endl;
    return out;
}

Truck::~Truck() {}
