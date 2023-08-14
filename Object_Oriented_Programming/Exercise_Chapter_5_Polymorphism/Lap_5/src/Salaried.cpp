#include "Salaried.h"

SalariedEmployee::SalariedEmployee(string firstName, string lastName, string socialSecurityNumber, double weeklySalary) : Employee(firstName, lastName, socialSecurityNumber) {
    this->weeklySalary = weeklySalary;
}

void SalariedEmployee::setWeeklySalary(double weeklySalary) {
    this->weeklySalary = weeklySalary;
}

int SalariedEmployee::getWeeklySalary() {
    return weeklySalary;
}

double SalariedEmployee::earnings() const {
    return weeklySalary;
}

void SalariedEmployee::print() const {
    cout << "\nSalaried Employee: " << endl;
    Employee::print();
    cout << "Earned Salary: " << earnings() << "$" << endl;
}

SalariedEmployee::~SalariedEmployee() {}
