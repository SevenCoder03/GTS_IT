#ifndef HOURLY_H
#define HOURLY_H
#include "Employee.h"

class HourlyEmployee : public Employee
{
    private:
        double wage;
        double hours;
    public:
        HourlyEmployee(string firstName, string lastName, string socialSecurityNumber, double wage = 0, double hours = 0);
        void setWage(double wage);
        void setHours(double hours);
        double getWage();
        double getHours();
        double earnings() const;
        void print() const;
        ~HourlyEmployee();
};

#endif // HOURLY_H
