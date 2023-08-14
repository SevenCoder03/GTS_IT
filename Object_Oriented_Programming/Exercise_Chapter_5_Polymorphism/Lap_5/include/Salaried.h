#ifndef SALARIED_H
#define SALARIED_H
#include "Employee.h"

class SalariedEmployee : public Employee
{
    private:
        double weeklySalary;
    public:
        SalariedEmployee(string firstName, string lastName, string socialSecurityNumber, double weeklySalary = 0);
        void setWeeklySalary(double weeklySalary);
        int getWeeklySalary();
        double earnings() const;
        void print() const;
        ~SalariedEmployee();
};

#endif // SALARIED_H
