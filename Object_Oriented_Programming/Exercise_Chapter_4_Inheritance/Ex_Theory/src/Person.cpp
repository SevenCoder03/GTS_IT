#include "Person.h"

Person::Person(string id, string name, string birthday) {
    this->id = id;
    this->name = name;
    this->birthday = birthday;
}

ostream &operator<<(ostream &out, Person x) {
    out << "ID: " << x.getId() << endl;
    out << "Name: " << x.getName() << endl;
    out << "Birth day: " << x.getBirthday() << endl;
    return out;
}

void Person::setId(string id) {
    this->id = id;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setBirthday(string birthday) {
    this->birthday = birthday;
}

string Person::getId() {
    return id;
}

string Person::getName() {
    return name;
}

string Person::getBirthday() {
    return birthday;
}

Person::~Person() {}
