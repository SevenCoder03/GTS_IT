#ifndef COMMISSION_H
#define COMMISSION_H
#include "Employee.h"

class CommissionEmployee : public Employee
{
    private:
        double grossSales;
        double commissionRate;
    public:
        CommissionEmployee(string firstName, string lastName, string socialSecurityNumber, double grossSales = 0, double commissionRate = 0);
        void setGrossSales(double grossSales);
        void setCommissionRate(double grossSales);
        double getGrossSales();
        double getCommission();
        double earnings() const;
        void print() const;
        ~CommissionEmployee();
};

#endif // COMMISSION_H
