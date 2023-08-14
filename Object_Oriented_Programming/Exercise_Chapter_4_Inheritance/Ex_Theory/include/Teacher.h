#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher : public Person
{
    private:
        double hsl;
    public:
        Teacher(string id, string name, string birthday, double hsl);
        friend ostream &operator<<(ostream &out, Teacher x);
        void setHsl(double hsl);
        double getHsl();
        double CalSalary();
        ~Teacher();
};

#endif // TEACHER_H
