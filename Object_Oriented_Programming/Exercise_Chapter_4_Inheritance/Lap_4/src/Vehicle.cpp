#include "Vehicle.h"

Vehicle::Vehicle(string mfgName, double dealerCost) {
    this->mfgName = mfgName;
    this->dealerCost = dealerCost;
}

double Vehicle::retailPrice() {
    return dealerCost + dealerCost*0.2;
}

ostream &operator<<(ostream &out, Vehicle x) {
    out << "Manufacturer name: " << x.mfgName << endl;
    out << "Retail price: " << x.retailPrice() << endl;
    return out;
}

Vehicle::~Vehicle() {}
