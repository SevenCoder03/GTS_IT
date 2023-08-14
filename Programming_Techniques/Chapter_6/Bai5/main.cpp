#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

struct SubjectScore{
    float Word;
	float Excel;
	float Pp;
};

struct Student{
    string StudentCode;
	string StudentName;
	string BirthDay;
	string Gender;
	SubjectScore Score;
	float SumScore;
};

struct List{
    Student *St = nullptr;
    int StudentNumber;
};

bool check_Student_Code(List ListStudent, string StudentCode_new){
    for(int i = 0; i < ListStudent.StudentNumber; i++){
        if(ListStudent.St[i].StudentCode == StudentCode_new)
        {
            return true;
        }
    }
    return false;
}

bool check_Student_Code_Fix(List ListStudent, string StudentCode_new, int index){
    for(int i = 0; i < ListStudent.StudentNumber; i++)
    {
        if(ListStudent.St[i].StudentCode == StudentCode_new && i != index)
        {
            return true;
        }
    }
    return false;
}

void standard_StudentCode (string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -= 32;
		}
	}
}

void delete_Space_First (string &s) {
	while (true) {
		if (s[0] == ' ') {
			s.erase(s.begin());
		}
		else {
			break;
		}
	}
}

void delete_Space_Last (string &s) {
	while (true) {
		if (s[s.length() - 1] == ' ') {
			s.erase(s.end() - 1);
		}
		else {
			break;
		}
	}
}

void delete_Space (string &s) {
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == ' ') {
			for (int j = i + 1; j < s.length(); j++) {
				if (s[j] == ' ') {
					s.erase(s.begin() + j);
					j--;
				}
				else {
					break;
				}
			}
		}
	}
}

void Upper (string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] += 32;
		}
	}
	s[0] -= 32;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == ' ') {
			if (s[i+1] >= 97 && s[i+1] <= 122) {
				s[i+1] -= 32;
			}
		}
	}
}

void standard_Name (string &s) {
	delete_Space_First(s);
	delete_Space_Last(s);
	delete_Space(s);
	Upper(s);
}

void standard_Gender (string &s) {
    delete_Space_First(s);
	delete_Space_Last(s);
	delete_Space(s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	s[0] -= 32;
}

bool check_Date (string s) {
    if(s.length() != 10)
    {
        return false;
    }
	int day = atoi(s.substr(0,2).c_str());
	int month = atoi(s.substr(3,5).c_str());
	int year = atoi(s.substr(6,10).c_str());
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

bool check_Gender(string gender){
    if (gender != "Nam" && gender != "Nu"){
        return false;
    }
    return true;
}

bool check_Score(float &Score){
    if (Score < 0 || Score > 10) {
		return false;
    }
    return true;
}

void read_Student(ifstream &filein, Student &St){
    string temp;
    getline(filein, temp);
    getline(filein, St.StudentCode);
    standard_StudentCode(St.StudentCode);
	getline(filein, St.StudentName);
	standard_Name(St.StudentName);
	getline(filein, St.BirthDay);
    getline(filein, St.Gender);
    standard_Gender(St.Gender);
	filein >> St.Score.Word;
	filein >> St.Score.Excel;
	filein >> St.Score.Pp;
	St.SumScore = St.Score.Word + St.Score.Excel + St.Score.Pp;
}

void read_File(ifstream &filein, List ListStudent){
    for(int i = 0; i < ListStudent.StudentNumber; i++){
		read_Student(filein, ListStudent.St[i]);
	}
}

void output_Student_List(Student St){
	cout << endl << "\t" << St.StudentCode << "\t" << left << setw(29) << St.StudentName << setw(20)<< St.BirthDay << setw(14) << St.Gender << setw(16) << St.Score.Word << setw(17) << St.Score.Excel << setw(18) << St.Score.Pp << setw(6) << St.SumScore << endl;
}

void output_Student(Student St){
    cout << "\n\t\t\tStudent Code: " << St.StudentCode;
    cout << "\n\t\t\tStudent Name: " << St.StudentName;
    cout << "\n\t\t\tDate Of Birth: " << St.BirthDay;
    cout << "\n\t\t\tGender: " << St.Gender;
    cout << "\n\t\t\tScore Word: " << St.Score.Word;
    cout << "\n\t\t\tScore Excel: " << St.Score.Excel;
    cout << "\n\t\t\tScore PowerPoint: " << St.Score.Pp;
    cout << "\n\t\t\tSum Score: " << St.SumScore;
    cout << endl << endl;
}

void input_Student(Student &St, List ListStudent){
    cin.ignore();
	cout << "\n\t\tEnter Student Code: ";
	getline(cin, St.StudentCode);
	standard_StudentCode(St.StudentCode);
	do {
		if (check_Student_Code(ListStudent, St.StudentCode) == true) {
			cout << "\n\t\tStudent Code Coincident !!!\n";
			cout << "\n\t\t   Re-Enter Student Code: ";
			getline(cin, St.StudentCode);
			standard_StudentCode(St.StudentCode);
		}
	}while (check_Student_Code(ListStudent, St.StudentCode) == true);

	cout << "\n\t\tEnter Student Name: ";
	getline(cin, St.StudentName);
	standard_Name(St.StudentName);

	cout << "\n\t\tEnter Student's Date Of Birth (DD/MM/YYYY): ";
	getline(cin, St.BirthDay);
	do {
        if (check_Date(St.BirthDay) == false) {
            cout << "\n\t\tDate Format Error!!!\n";
            cout << "\n\t\t   Re-Enter Date Of Birth (DD/MM/YYYY): ";
            cin >> St.BirthDay;
        }
	}while (check_Date(St.BirthDay) == false);

	cout << "\n\t\tEnter Student's Gender: ";
	getline(cin, St.Gender);
	standard_Gender(St.Gender);
	do {

		if (check_Gender(St.Gender) == false) {
			cout << "\n\t\t   Re-Enter Gender (Nam/Nu): ";
			cin >> St.Gender;
			standard_Gender(St.Gender);
		}
	}while (check_Gender(St.Gender) == false);

	cout << "\n\t\tEnter Score Word: ";
	cin >> St.Score.Word;
	do {
		if (check_Score(St.Score.Word) == false) {
			cout << "\n\t\t   Re-Enter Score Word 0 to 10: ";
			cin >> St.Score.Word;
		}
	}while (check_Score(St.Score.Word) == false);

	cout << "\n\t\tEnter Score Excel: ";
	cin >> St.Score.Excel;
	do {
		if (check_Score(St.Score.Excel) == false) {
			cout << "\n\t\t   Re-Enter Score Excel 0 to 10: ";
			cin >> St.Score.Excel;
		}
	}while (check_Score(St.Score.Excel) == false);

	cout << "\n\t\tEnter Score Power Point: ";
	cin >> St.Score.Pp;
	do {
		if (check_Score(St.Score.Pp) == false) {
			cout << "\n\t\t   Re-Enter Score Power Point 0 to 10: ";
			cin >> St.Score.Pp;
		}
	}while (check_Score(St.Score.Pp) == false);

	St.SumScore = St.Score.Word + St.Score.Excel + St.Score.Pp;
}

void output_All_Student(List ListStudent){
	for (int i = 0; i < ListStudent.StudentNumber; i++){
		output_Student_List(ListStudent.St[i]);
	}
}

void find_StudentCode(List ListStudent, string StudentCode_new){
	for (int i = 0; i < ListStudent.StudentNumber; i++){
		if (ListStudent.St[i].StudentCode == StudentCode_new){
			output_Student(ListStudent.St[i]);
			return;
		}
	}
	cout<<"\t\t\tNot Found Student !!!"<<endl;
}

void resize_ListStudent(List &ListStudent, int Oldsize, int Newsize){
    Student *StTmp = new Student[Oldsize];
    for (int i = 0; i < Oldsize; i++){
        StTmp[i] = ListStudent.St[i];
    }
    delete[] ListStudent.St;
    ListStudent.St = new Student[Newsize];
    int Min = Oldsize < Newsize ? Oldsize : Newsize;
    for (int i = 0; i < Min; i++){
        ListStudent.St[i] = StTmp[i];
    }
    delete[] StTmp;
}

void add_Student(List &ListStudent){
    int index = ListStudent.StudentNumber;
    resize_ListStudent(ListStudent, ListStudent.StudentNumber, ListStudent.StudentNumber + 1);
    input_Student(ListStudent.St[index], ListStudent);
    ListStudent.StudentNumber++;
}

void delete_Student(List &ListStudent, string StudentCode_new){
    int index = -1;
    for (int i = 0; i < ListStudent.StudentNumber; i++){
		if(stricmp(ListStudent.St[i].StudentCode.c_str(), StudentCode_new.c_str()) == 0){
			index = i;
			break;
		}
	}
	if(index == -1)
    {
        cout<<"\t\t\tNot Found Student Want To Delete!!!"<<endl;
        return;
    }
    for(int i = index; i < ListStudent.StudentNumber - 1; i++){
        ListStudent.St[i] = ListStudent.St[i + 1];
    }
    resize_ListStudent(ListStudent, ListStudent.StudentNumber, ListStudent.StudentNumber - 1);
    ListStudent.StudentNumber--;
}

void fix_Student(List &ListStudent, string StudentCode_new){
    int index;
    for (int i = 0; i < ListStudent.StudentNumber; i++){
		if (stricmp(ListStudent.St[i].StudentCode.c_str(), StudentCode_new.c_str()) == 0){
			index = i;
			break;
		}
	}
    int select;
    do{
        system("cls");
        cout << "\n0. Exit\n";
        cout << "1. Fix Student Code\n";
        cout << "2. Fix Student Name\n";
        cout << "3. Fix Date Of Birth\n";
        cout << "4. Fix Gender\n";
        cout << "5. Fix Score Word\n";
        cout << "6. Fix Score Excel\n";
        cout << "7. Fix Score PowerPoint\n";
        cout << "Enter Select: ";
        cin >> select;
        switch (select){
        case 0: break;
        case 1:{
                cin.ignore();
                cout<<"\nStudent Code Old: "<<ListStudent.St[index].StudentCode;
                cout<<"\nEnter Student Code New: ";
                getline(cin,ListStudent.St[index].StudentCode);
                standard_StudentCode(ListStudent.St[index].StudentCode);
                do {
                    if (check_Student_Code_Fix(ListStudent, ListStudent.St[index].StudentCode, index) == true) {
                        cout << "\n\t!Student Code Coincident !!!\n";
                        cout << "   Re-Enter Student Code New: ";
                        getline(cin, ListStudent.St[index].StudentCode);
                        standard_StudentCode(ListStudent.St[index].StudentCode);
                    }
                }while (check_Student_Code_Fix(ListStudent, ListStudent.St[index].StudentCode, index) == true);
                break;}
        case 2:{
                cin.ignore();
                cout << "\nStudent Name Old: "<<ListStudent.St[index].StudentName;
                cout << "\nEnter Student Name New: ";
                getline(cin, ListStudent.St[index].StudentName);
                standard_Name(ListStudent.St[index].StudentName);
                break;}
        case 3:{
                cin.ignore();
                cout<<"\nDate Of Birth Old: "<<ListStudent.St[index].BirthDay;
                cout<<"\nEnter Date Of Birth New: ";
                getline(cin, ListStudent.St[index].BirthDay);
                do {
                    if (check_Date(ListStudent.St[index].BirthDay) == false) {
                        cout << "\n\tDate Format Error!!!\n";
                        cout << "   Re-Enter Date Of Birth (DD/MM/YYYY): ";
                        getline(cin, ListStudent.St[index].BirthDay);
                    }
                }while (check_Date(ListStudent.St[index].BirthDay) == false);
                break;}
        case 4:{
                cout << "\nGender Old: " << ListStudent.St[index].Gender;
                cout << "\nEnter Gender New: ";
                cin >> ListStudent.St[index].Gender;
                standard_Gender(ListStudent.St[index].Gender);
                do {
                    if (check_Gender(ListStudent.St[index].Gender) == false) {
                        cout << "   Re-Enter Gender (Nam/Nu): ";
                        cin >> ListStudent.St[index].Gender;
                        standard_Gender(ListStudent.St[index].Gender);
                    }
                }while (check_Gender(ListStudent.St[index].Gender) == false);
                break;}
        case 5:{
                cout << "\nScore Word Old: "<<ListStudent.St[index].Score.Word;
                cout << "\nEnter Score Word New: ";
                cin >> ListStudent.St[index].Score.Word;
                do {
                    if (check_Score(ListStudent.St[index].Score.Word) == false) {
                        cout << "   Re-Enter Score Excel 0 to 10: ";
                        cin >> ListStudent.St[index].Score.Word;
                    }
                }while (check_Score(ListStudent.St[index].Score.Word) == false);
                break;}
        case 6:{
                cout << "\nScore Exce Old: "<<ListStudent.St[index].Score.Excel;
                cout << "\nEnter Score Excel New: ";
                cin >> ListStudent.St[index].Score.Excel;
                do {
                    if (check_Score(ListStudent.St[index].Score.Excel) == false) {
                        cout << "   Re-Enter Score Excel 0 to 10: ";
                        cin >> ListStudent.St[index].Score.Excel;
                    }
                }while (check_Score(ListStudent.St[index].Score.Excel) == false);
                break;}
        case 7:{
                cout << "\nScore Word Old: "<<ListStudent.St[index].Score.Pp;
                cout << "\nEnter Score PowerPoint New: ";
                cin >> ListStudent.St[index].Score.Pp;
                do {
                    if (check_Score(ListStudent.St[index].Score.Pp) == false) {
                        cout << "   Re-Enter Score Excel 0 to 10: ";
                        cin >> ListStudent.St[index].Score.Pp;
                    }
                }while (check_Score(ListStudent.St[index].Score.Pp) == false);
                break;}
        default:
            break;}
        system("pause");
    }while(select != 0);
}

bool check_File_Student(List ListStudent){
    bool Flag = true;
    for(int i = 0; i < ListStudent.StudentNumber; i++){
            cout << "\n\tStudent " << i+1 << ":";
        if(check_Student_Code_Fix(ListStudent, ListStudent.St[i].StudentCode, i) == true){
            cout << "\n\t\tStudent Code Coincident!!!\n";
            Flag = false;
        }
        if(check_Date(ListStudent.St[i].BirthDay) == false){
            cout << "\n\t\tDate Format Error!!!\n";
            Flag = false;
        }
        if(check_Gender(ListStudent.St[i].Gender) == false){
            cout << "\n\t\tGender Error\n";
            Flag = false;
        }
        if(check_Score(ListStudent.St[i].Score.Word) == false){
            cout << "\n\t\tScore Word Error\n";
            Flag = false;
        }
        if(check_Score(ListStudent.St[i].Score.Excel) == false){
            cout << "\n\t\tScore Excel Error\n";
            Flag = false;
        }
        if(check_Score(ListStudent.St[i].Score.Pp) == false){
            cout << "\n\t\tScore PowerPoint Error\n";
            Flag = false;
        }
    }
    if(Flag == false){
        cout << "\n\t*Please Check The File Again\n";
    }
    return Flag;
}

int index_S(string S){
    int index;
    for(int i = S.length() - 1; i >= 0; i--){
        if(S[i] == ' '){
            index = i + 1;
            break;
        }
    }
    return index;
}

void find_Student_FirstName(List ListStudent, string FirstName){
    bool Flag = false;
    for (int i = 0; i < ListStudent.StudentNumber; i++){
        string S = ListStudent.St[i].StudentName;
		if (S.substr(index_S(S), S.length() - index_S(S)) == FirstName){
			output_Student(ListStudent.St[i]);
			Flag = true;
		}
	}
	if(Flag == false)
	cout<<"\t\t\tNot Found Student !!!"<<endl;
}

void Sort_ListStudent_SumScore(List ListStudent){
    for(int i = 0; i < ListStudent.StudentNumber - 1; i++){
        for(int j = i + 1; j < ListStudent.StudentNumber; j++){
            if(ListStudent.St[i].SumScore > ListStudent.St[j].SumScore){
                swap(ListStudent.St[i], ListStudent.St[j]);
            }
        }
    }
}

int main(){
    List ListStudent;
	ifstream filein;
	filein.open("SINHVIEN.TXT", ios_base::in);
	filein >> ListStudent.StudentNumber;
	ListStudent.St = new Student[ListStudent.StudentNumber];
	read_File(filein, ListStudent);
    if(check_File_Student(ListStudent) == false){
        return 0;
    }
	int select;
    do{
        system("cls");
        cout << "\n\t\t ================ Student Management ================\n\n";
        cout << "\t\t\t0. Exit\n";
        cout << "\t\t\t1. Find Information 1 Student (Use Student Code)\n";
        cout << "\t\t\t2. Find Information 1 Student (Use First Name)\n";
        cout << "\t\t\t3. Add Student\n";
        cout << "\t\t\t4. Delete Student\n";
        cout << "\t\t\t5. Fix Information Student\n";
        cout << "\t\t\t6. Sort Sum Score\n";
        cout << "\t\t\t7. List All Student\n";
        cout << "\n\t\t ======================= End ========================\n\n";
        cout << "\t\t\tEnter Select: ";
        cin >> select;
        switch (select){
        case 0: break;
        case 1:{
                string StudentCode_new;
                cout <<"\n\t\tEnter Student Code Want To See: ";
                cin >> StudentCode_new;
                find_StudentCode(ListStudent, StudentCode_new);
                break;}
        case 2:{
                string FirstName;
                cout <<"\n\t\tEnter First Name Want To See: ";
                cin >> FirstName;
                standard_Name(FirstName);
                find_Student_FirstName(ListStudent, FirstName);
                break;}
        case 3:{
                cout << "\n\t\tEnter Information Student Want To Add: " << endl;
                add_Student(ListStudent);
                break;}
        case 4:{
                string StudentCode_new;
                cout << "\n\t\tEnter Information Student Want To Delete: ";
                cin >> StudentCode_new;
                delete_Student(ListStudent, StudentCode_new);
                break;}
        case 5:{
                string StudentCode_new;
                cout << "\n\t\tEnter Information Student Want To Fix: ";
                cin >> StudentCode_new;
                fix_Student(ListStudent, StudentCode_new);
                break;}
        case 6:{
                Sort_ListStudent_SumScore(ListStudent);
                cout << "\n\t\t\t\t\t\t\tLIST OF STUDENTS\n\n";
                cout << "\t" << "Student Code" << setw(20) << "Student Name" << setw(25) << "Date Of Birth" << setw(13) << "Gender" << setw(15) << "Score Word" << setw(16) << "Score Excel" << setw(22) << "Score PowerPoint" << setw(14) << "Sum Score\n";
                output_All_Student(ListStudent);
                cout << endl;
                break;}
        case 7:{
                cout << "\n\t\t\t\t\t\t\tLIST OF STUDENTS\n\n";
                cout << "\t" << "Student Code" << setw(20) << "Student Name" << setw(25) << "Date Of Birth" << setw(13) << "Gender" << setw(15) << "Score Word" << setw(16) << "Score Excel" << setw(22) << "Score PowerPoint" << setw(14) << "Sum Score\n";
                output_All_Student(ListStudent);
                cout << endl;
                break;}
        default:
            break;}
        system("pause");
    }while(select != 0);
	delete []ListStudent.St;
	filein.close();
	return 0;
}
