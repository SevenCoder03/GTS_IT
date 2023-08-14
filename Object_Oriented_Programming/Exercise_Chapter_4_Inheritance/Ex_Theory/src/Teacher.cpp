#include "Teacher.h"

Teacher::Teacher(string id, string name, string birthday, double hsl) : Person(id, name, birthday) {
    this->hsl = hsl;
}

ostream &operator<<(ostream &out, Teacher x) {
    out << "ID: " << x.getId() << endl;
    out << "Name: " << x.getName() << endl;
    out << "Birth day: " << x.getBirthday() << endl;
    out << "Hsl: " << x.getHsl() << endl;
    out << "Salary: " << x.CalSalary() << endl;
    out << endl;
    return out;
}

void Teacher::setHsl(double hsl) {
    this->hsl = hsl;
}

double Teacher::getHsl() {
    return hsl;
}

double Teacher::CalSalary() {
    return 10000*hsl;
}

Teacher::~Teacher() {}
