#include <iostream>

using namespace std;

class Element {
    private:
        int Data;
        Element *pNext;
    public:
        Element *createElement(int x);
        void setData(int x) {
            this->Data = x;
        }
        void setpNext(Element *pNext) {
            this->pNext = pNext;
        }
        int getData() {
            return Data;
        }
        Element *getpNext() {
            return pNext;
        }
};

Element* Element::createElement(int x) {
    Element *p = new Element;
    p->Data = x;
    p->pNext = nullptr;
    return p;
}

class Stack {
    private:
        Element *pHead;
        Element *pTail;
    public:
        Stack() {
            pHead = nullptr;
            pTail = nullptr;
        }

        int size() {
            Element *K = pHead;
            int i = 0;
            while (K != nullptr) {
                i++;
                K = K->getpNext();
            }
            return i;
        }

        bool isEmpty() {
            if(pHead == nullptr)
                return true;
            return false;
        }

        void push(int x) {
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

        void pop() {
            Element *K = pHead;
            pHead = pHead->getpNext();
            delete K;
        }

        int top() {
            return pHead->getData();
        }

        ~Stack() {};
};

void menu() {
    cout << "\n\t //===============MENU===============\\\\ ";
	cout << "\n\t||        CONVERT TOOL DECIMAL        ||";
	cout << "\n\t||====================================||";
	cout << "\n\t||             1.Binary               ||";
	cout << "\n\t||             2.Octal                ||";
	cout << "\n\t||             3.Hexadecimal          ||";
	cout << "\n\t||             0.Exit                 ||";
	cout << "\n\t \\\\==================================//";
	cout << "\n\n\t\t Enter select: ";
}

void Convert(Stack &T, int n, int base) {
    while(n != 0) {
        T.push(n % base);
        n/=base;
    }
}

void print(Stack T, int n, string base) {
    cout << "\n\t\t" << n << "(DEC) ==> ";
    if(base != "HEX") {
        while(!T.isEmpty()) {
            cout << T.top();
            T.pop();
        }
    }
    else {
        while(!T.isEmpty()) {
            switch(T.top()) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                    cout << T.top();
                    break;
                case 10:
                    cout << "A";
                    break;
                case 11:
                    cout << "B";
                    break;
                case 12:
                    cout << "C";
                    break;
                case 13:
                    cout << "D";
                    break;
                case 14:
                    cout << "E";
                    break;
                case 15:
                    cout << "F";
                    break;
                default:
                    break;
            }
            T.pop();
        }
    }
    cout << "(" << base << ")\n\n";
}

void managementConvert() {
    int select;
    do {
        system("cls");
        int n;
        cout << "\n\tEnter the number of decimals to convert: "; cin >> n;
        menu();
        cin >> select;
        switch (select){
        case 0: break;
        case 1:{
                Stack T;
                Convert(T, n, 2);
                print(T, n, "BIN");
                break;}
        case 2:{
                Stack T;
                Convert(T, n, 8);
                print(T, n, "OCT");
                break;}
        case 3:{
                Stack T;
                Convert(T, n, 16);
                print(T, n, "HEX");
                break;}
        default:
            break;}
        system("pause");
    }while(select != 0);
}

int main()
{
    managementConvert();
    return 0;
}
