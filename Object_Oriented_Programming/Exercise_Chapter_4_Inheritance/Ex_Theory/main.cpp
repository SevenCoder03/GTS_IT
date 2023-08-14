#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

int main()
{
    Student Nhan("21H1120013", "Ho Chi Nhan", "30/08/2003", 9.0);
    Teacher Lam("21H1120042", "Do Kim Lam", "24/08/2003", 4.0);
    cout << Lam;
    cout << Nhan;
    return 0;
}
