#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee
{
    private:
        string firstName;
        string lastName;
        string socialSecurityNumber;
    public:
        Employee(string firstName, string lastName, string socialSecurityNumber);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setSocialSecurityNumber(string socialSecurityNumber);
        string getFirstName();
        string getLastName();
        string getSocialSecurityNumber();
        virtual double earnings()const = 0;
        virtual void print() const = 0;
        ~Employee();
};

#endif // EMPLOYEE_H
