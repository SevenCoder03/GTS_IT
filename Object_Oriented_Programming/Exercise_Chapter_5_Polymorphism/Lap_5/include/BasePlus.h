#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "Commission.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
    private:
        double baseSalary;
    public:
        BasePlusCommissionEmployee(string firstName, string lastName, string socialSecurityNumber, double grossSales, double commissionRate, double baseSalary = 0);
        void setBaseSalary(double baseSalary);
        double getBaseSalary();
        double earnings() const;
        void print() const;
        ~BasePlusCommissionEmployee();
};

#endif // BASEPLUS_H
