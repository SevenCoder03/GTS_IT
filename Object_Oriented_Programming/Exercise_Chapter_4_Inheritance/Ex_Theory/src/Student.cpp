#include "Student.h"

Student::Student(string id, string name, string birthday, double dtb) : Person(id, name, birthday) {
    this->dtb = dtb;
}

ostream &operator<<(ostream &out, Student x) {
    out << "ID: " << x.getId() << endl;
    out << "Name: " << x.getName() << endl;
    out << "Birth day: " << x.getBirthday() << endl;
    out << "Dtb: " << x.getDtb() << endl;
    out << "Rank: " << x.Rank() << endl;
    out << endl;
    return out;
}

void Student::setDtb(double dtb) {
    this->dtb = dtb;
}

double Student::getDtb() {
    return dtb;
}

string Student::Rank() {
    if(dtb < 4) {
        return "Weak";
    }
    else if(dtb < 5.5) {
        return "Below average";
    }
    else if(dtb < 7) {
        return "Average";
    }
    else if(dtb < 8.5) {
        return "Good";
    }
    else {
        return "Excellent";
    }
}

Student::~Student() {}
