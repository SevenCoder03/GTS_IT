#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

struct Date
{
    int Day;
    int Month;
    int Year;
};

struct Employee
{
    char Code[10];
    char Name[50];
    Date Birthday;
    double Wage;
    int Workday;
    double RealWage;
};

int check_EmployeeCode(Employee ListEmployee[], char CodeNew[], int EmployeeNumber, int index)
{
    for(int i = 0; i < EmployeeNumber; i++)
    {
        if(strcmp(ListEmployee[i].Code, CodeNew) == 0 && i != index)
        {
            return i;
        }
    }
    return -1;
}

int check_ListEmployeeCode(string ListCodeEmployee[], char CodeNew[], int EmployeeNumber)
{
    for(int i = 0; i < EmployeeNumber; i++)
    {
        if(strcmp(ListCodeEmployee[i].c_str(), CodeNew) == 0)
        {
            return i;
        }
    }
    return -1;
}

void input_Employee(Employee &myEmployee, string &myEmployeCode, string ListCodeEmployee[], int EmployeeNumber)
{
    cin.ignore();
    cout << "Code: ";
    cin.getline(myEmployee.Code, 10);
    do {
        if (check_ListEmployeeCode(ListCodeEmployee ,myEmployee.Code, EmployeeNumber) != -1){
            cout << "\n\t!Employee Code Coincident !!!\n";
            cout << "   Re-Enter Employee Code New: ";
            cin.getline(myEmployee.Code, 10);
            }
    }while (check_ListEmployeeCode(ListCodeEmployee, myEmployee.Code, EmployeeNumber) != -1);
    myEmployeCode = myEmployee.Code;
    cout << "Name: ";
    cin.getline(myEmployee.Name, 50);
    cout << "Day of birth: ";
    cin >> myEmployee.Birthday.Day;
    cout << "Month of birth: ";
    cin >> myEmployee.Birthday.Month;
    cout << "Year of birth: ";
    cin >> myEmployee.Birthday.Year;
    cout << "Basic wage: ";
    cin >> myEmployee.Wage;
    cout << "Work day: ";
    cin >> myEmployee.Workday;
    myEmployee.RealWage = myEmployee.Wage * myEmployee.Workday;
}

void output_Employee(Employee myEmployee)
{
    cout << "\t   " << setw(17) << myEmployee.Code << setw(26) << left << myEmployee.Name << setw(2)
    << left << myEmployee.Birthday.Day << "/" << setw(2) << left << myEmployee.Birthday.Month << "/" << setw(15) << myEmployee.Birthday.Year
    << setw(15) << myEmployee.Wage << setw(10) << myEmployee.Workday << "\t" << setw(10) << myEmployee.RealWage << endl;
}

void write_File(fstream &file, int EmployeeNumber, string ListCodeEmployee[])
{
    file.open("NHANVIEN", ios::out | ios::binary);
    if(!file)
    {
        cout << "Error file";
    }
    else
    {
        for(int i = 0; i < EmployeeNumber; i++)
        {
            Employee myEmployee;
            cout << "Enter employee " << i + 1<< "\n";
            input_Employee(myEmployee, ListCodeEmployee[i], ListCodeEmployee, EmployeeNumber);
            file.write(reinterpret_cast<char*>(&myEmployee), sizeof(myEmployee));
        }
        file.close();
    }
}

void read_File(fstream &file, Employee ListEmployee[], int EmployeeNumber)
{
    file.open("NHANVIEN", ios::in | ios::binary);
    if(!file)
    {
        cout << "Erorr file";
    }
    else
    {
        int n = 0;
        while(file.read(reinterpret_cast<char*>(& ListEmployee[n]), sizeof(ListEmployee[n])))
        {
            n++;
        }
        file.close();
    }
}

void output_ListEmployee(Employee ListEmployee[], int EmployeeNumber)
{
    cout<< "\n\t\t\t\tLIST EMPLOYEE\n\n" << "\t" << setw(20) << left << "Code Employee" << setw(25) << left << "Name Employee" << setw(20)
    << left << "Date Of Birth" << setw(15) << left << "Wage basic" << setw(13) << left << "Day Work" << setw(10)<< left << "Real Wage" << "\n";
    for(int i=0; i < EmployeeNumber; i++)
    {
        output_Employee(ListEmployee[i]);
    }
}

void sort_ListEmployee(Employee ListEmployee[], int EmployeeNumber, fstream &file)
{
    for(int i = 0; i < EmployeeNumber - 1; i++)
    {
        for(int j = i + 1; j < EmployeeNumber; j++)
        {
            if(ListEmployee[i].RealWage > ListEmployee[j].RealWage)
            {
                swap(ListEmployee[i], ListEmployee[j]);
            }
        }
    }
    file.open("TANGDAN", ios::out | ios::binary);
    if(!file)
    {
        cout << "Error file";
    }
    else
    {
        for(int i = 0; i < EmployeeNumber; i++)
        {
            file.write(reinterpret_cast<char*>(&ListEmployee[i]), sizeof(ListEmployee[i]));
        }
        file.close();
    }
}

void fix_Employee(Employee ListEmployee[], char CodeNew[], int EmployeeNumber)
{
    int index = check_EmployeeCode(ListEmployee, CodeNew, EmployeeNumber, -1);
    if(index == -1)
    {
        cout << "Not found employee !!!";
    }
    else
    {
        int select;
    do{
        system("cls");
        cout << "\n0. Exit\n";
        cout << "1. Fix Employee Code\n";
        cout << "2. Fix Employee Name\n";
        cout << "3. Fix Date Of Birth\n";
        cout << "4. Fix Wage basic\n";
        cout << "5. Fix Work Day\n";
        cout << "Enter Select: ";
        cin >> select;
        switch (select){
        case 0: break;
        case 1:{
                cin.ignore();
                cout<<"\nEmployee Code Old: "<<ListEmployee[index].Code;
                cout<<"\nEnter Employee Code New: ";
                cin.getline(ListEmployee[index].Code, 10);
                do {
                    if (check_EmployeeCode(ListEmployee, ListEmployee[index].Code, EmployeeNumber, index) != -1) {
                        cout << "\n\tEmployee Code Coincident !!!\n";
                        cout << "   Re-Enter Employee Code New: ";
                        cin.getline(ListEmployee[index].Code, 10);
                    }
                }while (check_EmployeeCode(ListEmployee, ListEmployee[index].Code, EmployeeNumber, index) != -1);
                break;}
        case 2:{
                cin.ignore();
                cout << "\nEmployee Name Old: "<<ListEmployee[index].Name;
                cout << "\nEnter Employee Name New: ";
                cin.getline(ListEmployee[index].Name, 50);
                break;}
        case 3:{
                cout << "\nEnter Date Of Birth New: ";
                cout << "\nDay of birth: ";
                cin >> ListEmployee[index].Birthday.Day;
                cout << "\nMonth of birth: ";
                cin >> ListEmployee[index].Birthday.Month;
                cout << "\nYear of birth: ";
                cin >> ListEmployee[index].Birthday.Year;
                break;}
        case 4:{
                cout << "Enter new wage basic: ";
                cin >> ListEmployee[index].Wage;
                ListEmployee[index].RealWage = ListEmployee[index].Wage * ListEmployee[index].Workday;
                break;}
        case 5:{
                cout << "Enter new work day: ";
                cin >> ListEmployee[index].Workday;
                ListEmployee[index].RealWage = ListEmployee[index].Wage * ListEmployee[index].Workday;
                break;}
        default:
            break;}
            system("pause");
        }while(select != 0);
    }
}

int main()
{
    fstream file;
    Employee ListEmployee[10];
    string ListCodeEmployee[10];
    int EmployeeNumber;
    cout << "Enter number of employees: ";
    cin >> EmployeeNumber;
    write_File(file, EmployeeNumber, ListCodeEmployee);
    read_File(file, ListEmployee, EmployeeNumber);
    output_ListEmployee(ListEmployee, EmployeeNumber);
    sort_ListEmployee(ListEmployee, EmployeeNumber, file);
    cout << "\n\nAfter sorting: ";
    output_ListEmployee(ListEmployee, EmployeeNumber);
    cout << "\n\nEnter code employee want to fix: ";
    char CodeNew[10];
    cin.ignore();
    cin.getline(CodeNew, 10);
    fix_Employee(ListEmployee, CodeNew, EmployeeNumber);
    cout << "\n\nAfter fixing: ";
    output_ListEmployee(ListEmployee, EmployeeNumber);
    return 0;
}
