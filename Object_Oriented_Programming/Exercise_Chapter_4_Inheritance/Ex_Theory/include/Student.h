#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person
{
    private:
        double dtb;
    public:
        Student(string id, string name, string birthday, double dtb);
        friend ostream &operator<<(ostream &out, Student x);
        void setDtb(double dtb);
        double getDtb();
        string Rank();
        ~Student();
};

#endif // STUDENT_H
