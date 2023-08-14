#include <iostream>
using namespace std;
#include "Employee.h"
#include "Salaried.h"
#include "Commission.h"
#include "Baseplus.h"
#include "Hourly.h"

int main() {
    cout << "=================== WEEKLY SALARY STATEMENT ====================";
    Employee **a = new Employee*[4];
    a[0] = new SalariedEmployee("Johan", "Cruyff", "080-203-001-773", 800);
    a[1] = new HourlyEmployee("Cristiano", "Ronaldo", "097-301-461-033", 16.75, 40);
    a[2] = new CommissionEmployee("Lionel", "Messi", "222-22-2222", 10000, 0.06);
    a[3] = new BasePlusCommissionEmployee("Robert", "Lewandowski", "333-33-3333",  5000, .04, 300);
    cout << endl;
    for(int i = 0; i < 4; i++) {
        a[i]->print();
    }
    cout << endl;
    return 0;
}
