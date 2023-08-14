#include "Car.h"

Car::Car(string mfgName, double dealerCost, string modelName, bool sunRoof) : Vehicle(mfgName, dealerCost) {
    this->modelName = modelName;
    this->sunRoof = sunRoof;
}

ostream &operator<<(ostream &out, Car x) {
    out << "Manufacturer name: " << x.mfgName << endl;
    out << "Retail price: " << x.retailPrice() << endl;
    out << "Model name: " << x.modelName << endl;
    out << "Sun roof: ";
    if(x.sunRoof == true) {
        out << "Yes";
    }
    else {
        out << "No";
    }
    out << endl;
    return out;
}

Car::~Car() {}
