#include "BasePlus.h"

BasePlusCommissionEmployee::BasePlusCommissionEmployee(string firstName, string lastName, string socialSecurityNumber, double grossSales, double commissionRate, double baseSalary) : CommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate) {
    this->baseSalary = baseSalary;
}

void BasePlusCommissionEmployee::setBaseSalary(double baseSalary) {
    this->baseSalary = baseSalary;
}

double BasePlusCommissionEmployee::getBaseSalary() {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "\nBasePlus Commission Employee: " << endl;
    Employee::print();
    cout << "Earned Salary: " << earnings() << "$" << endl;
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {}
