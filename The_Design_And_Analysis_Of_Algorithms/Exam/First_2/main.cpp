#include <iostream>

using namespace std;

struct Date {
    int day, month, year;
};

struct Student {
    string name;
    Date dateOfBirth;
};

bool checkDate (Date x) {
    if (x.year < 0 || x.year > 2023 || x.month < 0 || x.month > 12 || x.day < 0 || x.day > 31)
    {
        return false;
    }
    else
    {
        int daymax;
        switch(x.month)
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
                if ((x.year % 4 == 0 && x.year % 100 != 0) || (x.year % 400 == 0))
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
        if (x.day > daymax)
        {
            return false;
        }
        return true;
    }
}

void inputAStudent (Student &x) {
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, x.name);
    do {
        cout << "Day of birth" << endl;
        cout << "\tEnter day: ";
        cin >> x.dateOfBirth.day;
        cout << "\tEnter month: ";
        cin >> x.dateOfBirth.month;
        cout << "\tEnter year: ";
        cin >> x.dateOfBirth.year;
        if(!checkDate(x.dateOfBirth)) {
             cout << "Invalid date !!! Please enter again !!!\n";
        }
    }while(!checkDate(x.dateOfBirth));
}

void outputAStudent (Student x) {
    cout << "\tName: " << x.name << endl;
    cout << "\tDate of birth: " << x.dateOfBirth.day << "/" << x.dateOfBirth.month << "/" << x.dateOfBirth.year << endl;
}

void inputListStudent (Student listStudent[], int n) {
    cout << "\t\tInput List Student" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nEnter information student " << i + 1 << endl;
        inputAStudent(listStudent[i]);
    }
}

void outputListStudent (Student listStudent[], int n) {
    cout << "\t\tOuput List Student" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nInformation student " << i + 1 << endl;
        outputAStudent(listStudent[i]);
    }
}

int countWord (string x) {
    int Count = 0;
    for(int i = 0; i < x.length(); i++) {
        if(x[i] == ' ') {
            Count++;
        }
    }
    return Count+1;
}

void findStudentMostWord (Student listStudent[], int n) {
    int checkWord[n], Max = 0;
    for(int i = 0; i < n; i++) {
        checkWord[i] = countWord(listStudent[i].name);
        if(checkWord[i] > Max) {
            Max = checkWord[i];
        }
    }
    cout << "\nStudents whose names contain the most words: " << endl;
    for(int i = 0; i < n; i++) {
        if(checkWord[i] == Max) {
            cout << listStudent[i].name << endl;
        }
    }
}

void findStudentEarliestBorn (Student listStudent[], int n) {
    int index = 0;
    for(int i = 1; i < n; i++) {
        if(listStudent[i].dateOfBirth.year < listStudent[i-1].dateOfBirth.year) {
            index = i;
        }
        else if (listStudent[i].dateOfBirth.year == listStudent[i-1].dateOfBirth.year) {
            if(listStudent[i].dateOfBirth.month < listStudent[i-1].dateOfBirth.month) {
                index = i;
            }
            else if (listStudent[i].dateOfBirth.month == listStudent[i-1].dateOfBirth.month) {
                if(listStudent[i].dateOfBirth.day < listStudent[i-1].dateOfBirth.day) {
                    index = i;
                }
            }
        }
    }

    cout << "\nThe student was born the earliest: " << endl;
    for(int i = 1; i < n; i++) {
        if(listStudent[index].dateOfBirth.year == listStudent[i].dateOfBirth.year && listStudent[index].dateOfBirth.month == listStudent[i].dateOfBirth.month && listStudent[index].dateOfBirth.day == listStudent[i].dateOfBirth.day) {
            cout << listStudent[i].name << endl;
        }
    }
}

void findStudentStartName (Student listStudent[], int n) {
    char x;
    cout << "\nEnter start name: "; cin >> x;
    if(x >= 'a' && x <= 'z') {
        x -= 32;
    }

    bool checkName[n];

    for(int i = 0; i < n; i++) {
        checkName[i] = false;
    }

    cout << "Students whose names start with a certain letter enter from the keyboard: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = listStudent[i].name.length() - 1; j >= 0; j--) {
            if(listStudent[i].name[j] == ' ') {
                if(listStudent[i].name[j+1] == x) {
                    checkName[i] = true;
                }
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(checkName[i] == true) {
            cout << listStudent[i].name << endl;
        }
    }
}

string cutName(string x) {
    string name = "";
    int index;
    for(int i = x.length() - 1; i >= 0; i--) {
        if(x[i] == ' ') {
            index = i;
            break;
        }
    }

    for(int i = index + 1; i < x.length(); i++) {
        name += x[i];
    }

    return name;
}


void sortListStudent(Student listStudent[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << cutName(listStudent[j].name) << endl;
            if (cutName(listStudent[j].name) > cutName(listStudent[j + 1].name)) {
                string temp = listStudent[j].name;
                listStudent[j].name = listStudent[j + 1].name;
                listStudent[j + 1].name = temp;
            }
        }
    }
    outputListStudent(listStudent, n);
}

int main()
{
    int n;
    cout << "Enter number student: "; cin >> n;
    Student listStudent[n];
    inputListStudent(listStudent, n);
    outputListStudent(listStudent, n);
    findStudentMostWord(listStudent, n);
    findStudentEarliestBorn(listStudent, n);
    findStudentStartName(listStudent, n);
    sortListStudent(listStudent, n);
    return 0;
}
