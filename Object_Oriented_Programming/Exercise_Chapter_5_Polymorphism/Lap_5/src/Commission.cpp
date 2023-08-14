#include "Commission.h"

CommissionEmployee::CommissionEmployee(string firstName, string lastName, string socialSecurityNumber, double grossSales, double commissionRate) : Employee(firstName, lastName, socialSecurityNumber) {
    this->grossSales = grossSales;
    this->commissionRate = commissionRate;
}

void CommissionEmployee::setGrossSales(double grossSales) {
    this->grossSales = grossSales;
}

void CommissionEmployee::setCommissionRate(double grossSales) {
    this->commissionRate = commissionRate;
}

double CommissionEmployee::getGrossSales() {
    return grossSales;
}

double CommissionEmployee::getCommission() {
    return commissionRate;
}

double CommissionEmployee::earnings() const {
    return grossSales*commissionRate;
}

void CommissionEmployee::print() const {
    cout << "\nCommission Employee: " << endl;
    Employee::print();
    cout << "Earned Salary: " << earnings() << "$" << endl;
}

CommissionEmployee::~CommissionEmployee() {}
