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
        Stack();
        int size();
        bool isEmpty();
        void push(int x);
        void pop();
        int top();
        ~Stack();
};

Stack::Stack() {
    pHead = nullptr;
    pTail = nullptr;
}

int Stack::size() {
    Element *K = pHead;
    int i = 0;
    while (K != nullptr) {
        i++;
        K = K->getpNext();
    }
    return i;
}

bool Stack::isEmpty() {
    if(pHead == nullptr)
        return true;
    return false;
}

void Stack::push(int x) {
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

void Stack::pop() {
    Element *K = pHead;
    pHead = pHead->getpNext();
    delete K;
}

int Stack::top() {
    return pHead->getData();
}

Stack::~Stack() {}

int main()
{
    Stack a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        a.push(i);
    }

    while(!a.isEmpty()) {
        cout << a.top() << " ";
        a.pop();
    }
    return 0;
}
