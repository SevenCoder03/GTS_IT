#include <iostream>
#include <vector>
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

class Queue {
    private:
        Element *pHead;
        Element *pTail;
    public:
        Queue() {
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
                pTail->setpNext(p);
                pTail = p;
            }
        }

        void pop() {
            Element *K = pHead;
            pHead = pHead->getpNext();
            delete K;
        }

        int front() {
            return pHead->getData();
        }

        int back() {
            return pTail->getData();
        }

        ~Queue(){};
};

bool checkPossible(Queue &A, Stack &B, Queue &C, Queue &T, Queue &R, int n) {
    while(true) {
        if(!A.isEmpty() && A.front() == T.front()) {
            C.push(A.front());
            A.pop();
            T.pop();
            R.push(1);
        }
        else if(!B.isEmpty() && B.top() == T.front()) {
            C.push(B.top());
            B.pop();
            T.pop();
            R.push(2);
        }
        else {
            B.push(A.front());
            A.pop();
            R.push(3);
        }
        if(A.isEmpty() && !B.isEmpty() && B.top() != T.front()) {
            break;
        }
        if(C.size() == n)
            return true;
    }
    return false;
}

int main()
{
    Queue A;
    Stack B;
    Queue C, T, R;
    int n;
    cout << "Enter n: "; cin >> n;
    for(int i = 1; i <= n; i++) {
        A.push(i);
    }
    cout << "Enter required order: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        T.push(x);
    }
    if(checkPossible(A, B, C, T, R, n)) {
        cout << "YES" << endl;
        while(!R.isEmpty()) {
            if(R.front() == 1) {
                cout << "A->C" << endl;
            }
            else if(R.front() == 2) {
                cout << "A->B" << endl;
            }
            else {
                cout << "B->C" << endl;
            }
            R.pop();
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}
