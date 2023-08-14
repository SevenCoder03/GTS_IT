#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "date.h"

class Employee
{
    private:
        string lastname;
        string firstname;
        Date birthdate;
        Date hiredate;
    public:
        Employee(string lastname, string firstname, Date birthdate, Date hiredate);
        void print();
        ~Employee();
};

#endif // EMPLOYEE_H
