#include "Employee.h"

Employee::Employee(string firstName, string lastName, string socialSecurityNumber) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->socialSecurityNumber = socialSecurityNumber;
}

void Employee::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Employee::setLastName(string lastName) {
    this->lastName = lastName;
}

void Employee::setSocialSecurityNumber(string socialSecurityNumber) {
    this->socialSecurityNumber = socialSecurityNumber;
}

string Employee::getFirstName() {
    return firstName;
}

string Employee::getLastName() {
    return lastName;
}

string Employee::getSocialSecurityNumber() {
    return socialSecurityNumber;
}

void Employee::print() const {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Social Security Number: " << socialSecurityNumber << endl;
}

Employee::~Employee() {}
