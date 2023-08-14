#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
using namespace std;

int main()
{
    Car c1( "Ford", 10000, "Mustang", false );
    Car c2( "Chevy", 15000, "Camaro", true );
    Truck t1( "Ford", 12000, 1.5, true );
    Truck t2( "Dodge", 14000, 2.0, false );
    cout << "Dealer inventory:" << endl << endl;
    cout << c1;
    cout << c2;
    cout << t1;
    cout << t2;
    return 0;
}
