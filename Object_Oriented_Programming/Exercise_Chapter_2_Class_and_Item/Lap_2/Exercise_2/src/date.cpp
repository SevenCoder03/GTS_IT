#include "date.h"

Date::Date() {
    day = 1;
    month = 1;
    year = 1900;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->checkDate();
}

void Date::display() {
    cout << day << "/" << month << "/" << year;
}

void Date::checkDate() {
    if (year < 0 || year > 2022) {
        cout << "Invalid Year !!!" << endl;
    }
    if (month < 0 || month > 12) {
        cout << "Ivalid Month !!!" << endl;
    }
    if (day < 0 || day > 31) {
        cout << "Ivalid Day !!!" << endl;
    }
    else {
        int daymax;
        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                daymax = 31;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                    daymax = 29;
                else
                    daymax = 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                daymax = 30;
                break;
        }
        if (day > daymax)
        {
            cout << "Ivalid Day !!!" << endl;
        }
    }
}

Date::~Date() {}
