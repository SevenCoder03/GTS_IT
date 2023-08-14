#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

struct BD {
    int day;
    int month;
    int year;
};

struct Student {
    string id;
    string name;
    BD birthDay;
    double avgScore;
};

bool checkDate (int day, int month, int year) {
    if (year < 0 || year > 2022 || month < 0 || month > 12 || day < 0 || day > 31)
    {
        return false;
    }
    else
    {
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
            return false;
        }
        return true;
    }
}

void inputStudent(Student &S) {
    cin.ignore();
    cout << "Enter Student ID: "; getline(cin, S.id);
    cout << "Enter Student Name: "; getline(cin, S.name);
    cout << "Enter Birth Day" << endl;
    cout << "Day: "; cin >> S.birthDay.day;
    cout << "Month: "; cin >> S.birthDay.month;
    cout << "Year: "; cin >> S.birthDay.year;
    do {
        if (checkDate(S.birthDay.day, S.birthDay.month, S.birthDay.year) == false) {
            cout << "\nDate Error!!!\n";
            cout << "\nRe-Enter Date Of Birth\n";
            cout << "Day: "; cin >> S.birthDay.day;
            cout << "Month: "; cin >> S.birthDay.month;
            cout << "Year: "; cin >> S.birthDay.year;
        }
	}while (checkDate(S.birthDay.day, S.birthDay.month, S.birthDay.year) == false);

    cout << "Enter Average Score: "; cin >> S.avgScore;
}

void inputList(Student *&List, int StudentNumber) {
    for(int i=0; i < StudentNumber; i++) {
        cout << "\tEnter Student " << i + 1 << endl;
        inputStudent(List[i]);
    }
}

string toStringBD(Student S) {
    string day = to_string(S.birthDay.day);
    string month = to_string(S.birthDay.month);
    string year = to_string(S.birthDay.year);
    if(day.length() == 1) {
        day = "0" + day;
    }
    if(month.length() == 1) {
        month = "0" + month;
    }
    return day + "/" + month + "/" + year;
}

void outputStudent(Student S) {

    cout << endl << "\t" << S.id << "\t" << left << setw(29) << S.name << setw(20)<< toStringBD(S) << setw(6) << S.avgScore << endl;
}

void outputList(Student *List, int StudentNumber) {
    cout << "\n\t\t\t\t\tLIST OF STUDENTS\n\n";
    cout << "\t" << "Student Code" << setw(20) << "Student Name" << setw(25) << "Date Of Birth" << setw(20) << "Average Score\n";
    for(int i=0; i < StudentNumber; i++) {
        outputStudent(List[i]);
    }
}

void sortList(Student *List, int StudentNumber){
    for(int i = 0; i < StudentNumber - 1; i++){
        for(int j = i + 1; j < StudentNumber; j++){
            if(List[i].avgScore < List[j].avgScore){
                swap(List[i], List[j]);
            }
        }
    }
}

int main()
{
    int StudentNumber;
    cout << "Enter number student: "; cin >> StudentNumber;
    Student *List = new Student[StudentNumber];
    inputList(List, StudentNumber);
    system("cls");
    sortList(List, StudentNumber);
    outputList(List, StudentNumber);
    delete []List;
    return 0;
}
