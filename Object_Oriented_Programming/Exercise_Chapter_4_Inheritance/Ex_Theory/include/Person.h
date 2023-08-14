#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person
{
    private:
        string id;
        string name;
        string birthday;
    public:
        Person(string id, string name, string birthday);
        friend ostream &operator<<(ostream &out, Person x);
        void setId(string id);
        void setName(string name);
        void setBirthday(string birthday);
        string getId();
        string getName();
        string getBirthday();
        ~Person();
};

#endif // PERSON_H
