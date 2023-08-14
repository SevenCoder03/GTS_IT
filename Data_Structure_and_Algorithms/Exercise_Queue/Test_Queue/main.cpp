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

class Queue {
    private:
        Element *pHead;
        Element *pTail;
    public:
        Queue();
        int size();
        bool isEmpty();
        void push(int x);
        void pop();
        int front();
        int back();
        ~Queue();
};

Queue::Queue() {
    pHead = nullptr;
    pTail = nullptr;
}

int Queue::size() {
    Element *K = pHead;
    int i = 0;
    while (K != nullptr) {
        i++;
        K = K->getpNext();
    }
    return i;
}

bool Queue::isEmpty() {
    if(pHead == nullptr)
        return true;
    return false;
}

void Queue::push(int x) {
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

void Queue::pop() {
    Element *K = pHead;
    pHead = pHead->getpNext();
    delete K;
}

int Queue::front() {
    return pHead->getData();
}

int Queue::back() {
    return pTail->getData();
}

Queue::~Queue() {}

int main()
{
    Queue a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        a.push(i);
    }

    while(!a.isEmpty()) {
        cout << a.front() << " ";
        a.pop();
    }
    return 0;
}
