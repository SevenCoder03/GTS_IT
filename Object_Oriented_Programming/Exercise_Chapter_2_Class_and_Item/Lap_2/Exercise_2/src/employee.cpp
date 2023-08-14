#include "employee.h"

Employee::Employee(string lastname, string firstname, Date birthdate, Date hiredate) {
    this->lastname = lastname;
    this->firstname = firstname;
    this->birthdate = birthdate;
    this->hiredate = hiredate;
}

void Employee::print() {
    cout << "Last name: " << lastname << endl;
    cout << "First name: " << firstname << endl;
    cout << "Birth Date: ";
    birthdate.display();
    cout << endl;
    cout << "Hire Date: ";
    hiredate.display();
    cout << endl;
}

Employee::~Employee() {}
