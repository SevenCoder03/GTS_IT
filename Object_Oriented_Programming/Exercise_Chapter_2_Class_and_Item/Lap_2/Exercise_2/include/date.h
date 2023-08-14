#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int day, int month, int year);
        void display();
        void checkDate();
        ~Date();
};

#endif // DATE_H
