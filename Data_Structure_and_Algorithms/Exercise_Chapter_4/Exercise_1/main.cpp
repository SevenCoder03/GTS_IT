#include <iostream>
#include<iomanip>
using namespace std;

class Student {
    private:
        int ID;
        string Name;
        string BD;
        double Avg;
    public:
        Student(){};

        void setID(int ID) {
            this->ID = ID;
        }

        void setName(string Name) {
            this->Name = Name;
        }

        void setBD(string BD) {
            this->BD = BD;
        }

        void setAvg(double Avg) {
            this->Avg = Avg;
        }

        int getID() {
            return ID;
        }

        string getName() {
            return Name;
        }

        string getBD() {
            return BD;
        }

        double getAvg() {
            return Avg;
        }

        friend istream &operator>>(istream &in, Student &x) {
            cout << "\tEnter ID: ";
            cin >> x.ID;
            cin.ignore();
            cout << "\tEnter Name: ";
            getline(in, x.Name);
            cout << "\tEnter Birthday: ";
            getline(in, x.BD);
            cout << "\tEnter average score: ";
            in >> x.Avg;
            return in;
        }

        friend ostream &operator<<(ostream &out, Student x) {
            out << "\t    " << x.ID << "\t\t" << left << setw(23) << x.Name << setw(21) << x.BD << "\t  " << setw(15) << x.Avg << endl;
        }

        ~Student(){};
};

class Element {
    private:
        Student Data;
        Element *pNext;
    public:
        Element *createElement(Student x) {
            Element *p = new Element;
            p->Data = x;
            p->pNext = nullptr;
            return p;
        }

        void setData(Student x) {
            this->Data = x;
        }

        void setpNext(Element *pNext) {
            this->pNext = pNext;
        }

        Student getData() {
            return Data;
        }

        Element *getpNext() {
            return pNext;
        }
};

class listStudent {
    private:
        Element *pHead;
        Element *pTail;
    public:
        listStudent() {
            pHead = nullptr;
            pTail = nullptr;
        }

        void importList(int Quantity) {
            for(int i = 1; i <= Quantity; i++) {
                Student x;
                cout << "\t\tEnter Student " << i << " :" << endl;
                cin >> x;
                importStudent(x);
            }
        }

        void importStudent(Student x) {
            Element *p = p->createElement(x);
            if(pHead == nullptr) {
                pHead = p;
                pTail = p;
            }
            else {
                pTail->setpNext(p);
                pTail = p;
            }
        }

        void importStudentOrder(Student x) {
            if(x.getID() < pHead->getData().getID()) {
                Element *p = p->createElement(x);
                if(pHead == nullptr) {
                    pHead = p;
                    pTail = p;
                }
                else {
                    p->setpNext(pHead);
                    pHead = p;
                }
            }
            else if(x.getID() > pTail->getData().getID()) {
                importStudent(x);
            }
            else {
                Element *K = pHead;
                while(!(x.getID() > K->getData().getID() && x.getID() < K->getpNext()->getData().getID())) {
                    K = K->getpNext();
                }
                Element *p = p->createElement(x);
                p->setpNext(K->getpNext());
                K->setpNext(p);
            }
        }

        void printList() {
            Element *K = pHead;
            while(K != nullptr) {
                cout << K->getData() << endl;
                K = K->getpNext();
            }
        }

        void sortList() {
            for(Element *K = pHead; K->getpNext()!= nullptr; K = K->getpNext()) {
                for(Element *Q = K->getpNext(); Q != nullptr; Q = Q->getpNext()) {
                    if(K->getData().getID() > Q->getData().getID()) {
                        Student tmp = K->getData();
                        K->setData(Q->getData());
                        Q->setData(tmp);
                    }
                }
            }
        }

        void findStudent(string findName) {
            Element *K = pHead;
            while(pHead != nullptr) {
                if(K->getData().getName() == findName) {
                    cout << "\t" << "Student ID" << "\t" << left << setw(22) << "Student Name" << setw(23) << "Date Of Birth" << setw(20) << "Average Score\n\n";
                    cout << K->getData() << endl;
                    break;
                }
                K = K->getpNext();
            }
        }

        int listLen() {
            Element *K = pHead;
            int i = 0;
            while (K != nullptr) {
                i++;
                K = K->getpNext();
            }
            return i;
        }

        int Position(int x) {
            Element *K = pHead;
            int i = 1;
            while (K != nullptr && K->getData().getID() != x) {
                i++;
                K = K->getpNext();
            }
            if(K != nullptr) {
                return i;
            }
            else {
                return 0;
            }
        }

        void deleteIndex(int index) {
            if(index == 1) {
                Element *K = pHead;
                pHead = pHead->getpNext();
                delete K;
            }
            else {
                Element *K = pHead;
                int i = 1;
                while(i != index - 1) {
                    K = K->getpNext();
                    i++;
                }
                Element *Q = K->getpNext();
                K->setpNext(Q->getpNext());
                delete Q;
            }
        }

        ~listStudent() {};
};

void menu() {
    cout << "\n\t\t ================ Student Management ================\n\n";
    cout << "\t\t\t    0. Exit\n";
    cout << "\t\t\t    1. Enter List Student\n";
    cout << "\t\t\t    2. Print List Student\n";
    cout << "\t\t\t    3. Sort List In Order Of ID\n";
    cout << "\t\t\t    4. Find Student By Name\n";
    cout << "\t\t\t    5. Add Student In Order\n";
    cout << "\t\t\t    6. Delete Student With ID\n";
    cout << "\n\t\t ======================= End ========================\n\n";
    cout << "\t\t\tEnter Select: ";
}

void managementStudent(listStudent L) {
    int select;
    do{
        system("cls");
        menu();
        cin >> select;
        switch (select){
        case 0: break;
        case 1:{
                int Quantity;
                cout << "\tEnter quantity of student: "; cin >> Quantity;
                L.importList(Quantity);
                break;}
        case 2:{
                cout << "\n\t\t\t\tLIST OF STUDENTS\n\n";
                cout << "\t" << "Student ID" << "\t" << left << setw(22) << "Student Name" << setw(23) << "Date Of Birth" << setw(20) << "Average Score\n\n";
                L.printList();
                cout << endl;
                break;}
        case 3:{
                L.sortList();
                cout << "\n\t\t\t\tLIST OF STUDENTS\n\n";
                cout << "\t" << "Student ID" << "\t" << left << setw(22) << "Student Name" << setw(23) << "Date Of Birth" << setw(20) << "Average Score\n\n";
                L.printList();
                cout << endl;
                break;}
        case 4:{
                string findName;
                cin.ignore();
                cout << "\t\tEnter name to find: ";
                getline(cin, findName);
                L.findStudent(findName);
                break;}
        case 5:{
                Student newStudent;
                cin >> newStudent;
                L.importStudentOrder(newStudent);
                cout << "\n\t\t\t\tLIST OF STUDENTS\n\n";
                cout << "\t" << "Student ID" << "\t" << left << setw(22) << "Student Name" << setw(23) << "Date Of Birth" << setw(20) << "Average Score\n\n";
                L.printList();
                break;}
        case 6:{
                int deleteID;
                cout << "\tEnter ID to find: ";
                cin >> deleteID;
                L.deleteIndex(L.Position(deleteID));
                cout << "\n\t\t\t\tLIST OF STUDENTS\n\n";
                cout << "\t" << "Student ID" << "\t" << left << setw(22) << "Student Name" << setw(23) << "Date Of Birth" << setw(20) << "Average Score\n\n";
                L.printList();
                break;}
        default:
            break;}
        system("pause");
    }while(select != 0);
}

int main()
{
    listStudent L;
    managementStudent(L);
    return 0;
}
