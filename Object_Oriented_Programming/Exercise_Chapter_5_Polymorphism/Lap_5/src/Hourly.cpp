#include "Hourly.h"

HourlyEmployee::HourlyEmployee(string firstName, string lastName, string socialSecurityNumber, double wage, double hours) : Employee(firstName, lastName, socialSecurityNumber) {
    this->wage = wage;
    this->hours = hours;
}

void HourlyEmployee::setWage(double wage) {
    this->wage = wage;
}

void HourlyEmployee::setHours(double hours) {
    this->hours = hours;
}

double HourlyEmployee::getWage() {
    return wage;
}

double HourlyEmployee::getHours() {
    return hours;
}

double HourlyEmployee::earnings() const {
    if(hours <= 40) {
        return wage*hours;
    }
    else {
        return wage*40 + wage*(hours - 40)*1.5;
    }
}

void HourlyEmployee::print() const {
    cout << "\nHourly Employee: " << endl;
    Employee::print();
    cout << "Earned Salary: " << earnings() << "$" << endl;
}

HourlyEmployee::~HourlyEmployee() {}
