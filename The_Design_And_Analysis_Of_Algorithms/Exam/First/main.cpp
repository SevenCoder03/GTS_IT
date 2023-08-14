#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    int yearOfBirth;
    int group;
    string getLastName() {
        string last_name = name.substr(name.rfind(" ") + 1);
        return last_name;
    }
};

void inputList(vector<Student>& students) {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Student s;
        cout << "Nhap thong tin sinh vien thu " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> s.id;
        cout << "Ten: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Nam sinh: ";
        cin >> s.yearOfBirth;
        cout << "Nhom: ";
        cin >> s.group;

        students.push_back(s);
    }
}

void outputList(vector<Student>& students) {
    cout << "Danh sach sinh vien:" << endl;

    for (Student s : students) {
        cout << "ID: " << s.id << endl;
        cout << "Ten: " << s.name << endl;
        cout << "Nam sinh: " << s.yearOfBirth << endl;
        cout << "Nhom: " << s.group << endl;
        cout << endl;
    }
}

void sortByLastName(vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; ++i) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].getLastName() > key.getLastName()) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

void addStudent(vector<Student>& students, const Student& s) {
    students.push_back(s);
    int n = students.size();
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        Student temp = students[i];
        while (j >= 0 && students[j].getLastName() > temp.getLastName()) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = temp;
    }
}

void deleteStudent(vector<Student>& students, int id) {
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            break;
        }
    }
}


int main() {
    vector<Student> students;

    inputList(students);
    sortByLastName(students);
    outputList(students);

    Student s {10, "Dinh Thanh Tan", 2000, 2};
    addStudent(students, s);
    outputList(students);

    deleteStudent(students, 3);
    outputList(students);

    return 0;
}

