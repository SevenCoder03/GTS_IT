#include <iostream>

using namespace std;

class Node {
    private:
        int Data;
        Node *pNext;
    public:
        Node();
        Node(int Data) {
            this->Data = Data;
            this->pNext = nullptr;
        }
        void setData(int x) {
            this->Data = x;
        }
        void setpNext(Node *pNext) {
            this->pNext = pNext;
        }
        int getData() {
            return Data;
        }
        Node *getpNext() {
            return pNext;
        }
};

class List {
    private:
        Node *pHead;
        Node *pTail;
    public:
        List();
        void setpHead(Node *pHead);
        Node *getpHead();
        void setpTail(Node *pTail);
        Node *getpTail();
        int listLen();
        void printList();
        int Position(int x);
        Node *RuntoQ(int index);
        void importList();
        void importFirst(int x);
        void importLast(int x);
        void importIndex(int x, int index);
        void importAfterQ(Node *P, Node *Q);
        void deleteFirst();
        void deleteLast();
        void deleteIndex(int index);
        void deleteValue(int value);
        void deleteAfterQ(Node *Q);
        ~List();
};

List::List() {
    pHead = nullptr;
    pTail = nullptr;
}

void List::setpHead(Node *pHead) {
    this->pHead = pHead;
}

Node *List::getpHead() {
    return pHead;
}

void List::setpTail(Node *pTail) {
    this->pTail = pTail;
}

Node *List::getpTail() {
    return pTail;
}

void List::printList() {
    Node *K = pHead;
    cout << "\n[ ";
    while(K != nullptr) {
        if(K->getpNext() != nullptr){
            cout << K->getData() << ", ";
            K = K->getpNext();
        }
        else {
            cout << K->getData();
            K = K->getpNext();
        }
    }
    cout << " ]" << endl;
}

int List::listLen() {
    Node *K = pHead;
    int i = 0;
    while (K != nullptr) {
        i++;
        K = K->getpNext();
    }
    return i;
}

int List::Position(int x) {
    Node *K = pHead;
    int i = 1;
    while (K != nullptr && K->getData() != x) {
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

Node *List::RuntoQ(int indexQ) {
    Node *K = pHead;
    while(indexQ--) {
        K = K->getpNext();
    }
    return K;
}

void List::importFirst(int x) {
    Node *p = new Node(x);
    if(pHead == nullptr) {
        pHead = p;
        pTail = p;
    }
    else {
        p->setpNext(pHead);
        pHead = p;
    }
}

void List::importLast(int x) {
    Node *p = new Node(x);
    if(pHead == nullptr) {
        pHead = p;
        pTail = p;
    }
    else {
        pTail->setpNext(p);
        pTail = p;
    }
}

void List::importList() {
    int x;
    while(x != -1) {
        cout << "Enter value: "; cin >> x;
        if(x != -1) {
            importLast(x);
        }
    }
}

void List::importIndex(int x, int index) {
    if(index <= 1) {
        importFirst(x);
    }
    else if(index >= listLen()) {
        importLast(x);
    }
    else {
        int i = 1;
        Node *K = pHead;
        Node *p = new Node(x);
        while(i != index - 1) {
            i++;
            K = K->getpNext();
        }
        p->setpNext(K->getpNext());
        K->setpNext(p);
    }
}

void List::importAfterQ(Node *P, Node *Q) {
    if(Q != nullptr) {
        P->setpNext(Q->getpNext());
        Q->setpNext(P);
        if(pTail == Q) {
            pTail = P;
        }
    }
    else {
        importFirst(P->getData());
    }
}

void List::deleteFirst() {
    if(pHead == nullptr) {
        cout << "\nNo Node to delete";
    }
    else {
        Node *K = pHead;
        pHead = pHead->getpNext();
        delete K;
    }
}

void List::deleteLast() {
    if(pHead == nullptr) {
        cout << "\nNo Node to delete";
    }
    else if(pHead->getpNext() == nullptr) {
        deleteFirst();
    }
    else {
        Node *K = pHead;
        while(K->getpNext()->getpNext() != nullptr)
        {
            K = K->getpNext();
        }
        Node *Q = K->getpNext();
        K->setpNext(nullptr);
        pTail = K;
        delete Q;
    }
}

void List::deleteIndex(int index) {
    if(index < 1 || index > listLen()) {
        cout << "\nNo Node to delete";
    }
    else if(index == 1) {
        deleteFirst();
    }
    else {
        Node *K = pHead;
        int i = 1;
        while(i != index - 1) {
            K = K->getpNext();
            i++;
        }
        Node *Q = K->getpNext();
        K->setpNext(Q->getpNext());
        delete Q;
    }
}

void List::deleteValue(int value) {
    if(pHead == nullptr) {
        cout << "\nNo Node to delete";
    }
    else {
        Node *K = pHead;
        while(K->getpNext() != nullptr) {
            if(K->getpNext()->getData() == value) {
                Node *Q = K->getpNext();
                K->setpNext(Q->getpNext());
                delete Q;
            }
            else
            {
                K = K->getpNext();
            }
        }
        if(pHead->getData() == value) deleteFirst();
    }
}

void List::deleteAfterQ(Node *Q) {
    if(Q != pTail && Q != nullptr) {
        Node *K = Q->getpNext();
        Q->setpNext(K->getpNext());
        delete K;
    }
    else {
        deleteFirst();
    }
}

List::~List() {};

void convert(List &A, List &B) {
    Node *M = A.getpHead();
    Node *N = B.getpHead();
    while(M != nullptr) {
        bool flag = false;
        if(M->getData() % 2 != 0) {
            while(N != nullptr) {
                if(N->getData() % 2 == 0) {
                    int temp = M->getData();
                    M->setData(N->getData());
                    N->setData(temp);
                    flag = true;
                    break;
                }
                N = N->getpNext();
            }
        }
        if(flag == false) {
            int delData = M->getData();
            M = M->getpNext();
            B.importLast(delData);
            A.deleteIndex(A.Position(delData));
        }
        else {
            M = M->getpNext();
        }
    }
    N = B.getpHead();
    while(N != nullptr) {
        if(N->getData() % 2 == 0) {
            int delData = N->getData();
            N = N->getpNext();
            A.importLast(delData);
            B.deleteIndex(B.Position(delData));
        }
        else {
            N = N->getpNext();
        }
    }
}

int main()
{
    List A, B;
    cout << "Enter list A: " << endl;
    A.importList();
    cout << "Enter list B: " << endl;
    B.importList();
    A.printList();
    B.printList();
    convert(A, B);
    cout << "\nAfter convert: " << endl;
    A.printList();
    B.printList();
    return 0;
}
