#include <iostream>

using namespace std;

class Element{
    private:
        int Data;
        Element *pNext;
        Element *pPre;
    public:
        Element *createElement(int x);
        void setData(int x);
        void setpNext(Element *pNext);
        void setpPre(Element *pPre);
        int getData();
        Element *getpNext();
        Element *getpPre();
};

Element *Element::createElement(int x) {
    Element *p = new Element;
    p->setData(x);
    p->setpNext(nullptr);
    p->setpPre(nullptr);
    return p;
}

void Element::setData(int x) {
    Data = x;
}

void Element::setpNext(Element *pNext) {
    this->pNext = pNext;
}

void Element::setpPre(Element *pPre) {
    this->pPre = pPre;
}

int Element::getData() {
    return Data;
}

Element *Element::getpNext() {
    return pNext;
}

Element *Element::getpPre() {
    return pPre;
}

class doubleList {
    private:
        Element *pHead;
        Element *pTail;
    public:
        void Create();
        void importList(int n);
        void importFirst(int x);
        void importLast(int x);
        void importIndex(int x, int index);
        void importAfterQ(Element *P, Element *Q);
        Element *RuntoQ(int index);
        int listLen();
        void printListHead();
        void printListTail();
        int Position(int x);
        void deleteFirst();
        void deleteLast();
        void deleteIndex(int index);
        void deleteValue(int value);
        void deleteAfterQ(Element *Q);
};

void doubleList::Create() {
    pHead = nullptr;
    pTail = nullptr;
}

void doubleList::importFirst(int x) {
    Element *p = p->createElement(x);
    if(pHead == nullptr) {
        pHead = p;
        pTail = p;
    }
    else {
        p->setpNext(pHead);
        pHead->setpPre(p);
        pHead = p;
    }
}

void doubleList::importLast(int x) {
    Element *p = p->createElement(x);
    if(pHead == nullptr) {
        pHead = p;
        pTail = p;
    }
    else {
        pTail->setpNext(p);
        p->setpPre(pTail);
        pTail = p;
    }
}

void doubleList::importList(int n) {
    while(n--) {
        int x;
        cout << "Enter x: "; cin >> x;
        importLast(x);
    }
}

void doubleList::printListHead() {
    Element *K = pHead;
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
    cout << " ]";
}

void doubleList::printListTail() {
    Element *K = pTail;
    cout << "\n[ ";
    while(K != nullptr) {
        if(K->getpPre() != nullptr){
            cout << K->getData() << ", ";
            K = K->getpPre();
        }
        else {
            cout << K->getData();
            K = K->getpPre();
        }
    }
    cout << " ]";
}

Element *doubleList::RuntoQ(int indexQ) {
    Element *K = pHead;
    while(indexQ--) {
        K = K->getpNext();
    }
    return K;
}

int doubleList::listLen() {
    Element *K = pHead;
    int i = 0;
    while (K != nullptr) {
        i++;
        K = K->getpNext();
    }
    return i;
}

int doubleList::Position(int x) {
    Element *K = pHead;
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

void doubleList::importIndex(int x, int index) {
    if(index <= 1) {
        importFirst(x);
    }
    else if(index >= listLen()) {
        importLast(x);
    }
    else {
        int i = 1;
        Element *K = pHead;
        Element *p = p->createElement(x);
        while(i != index - 1) {
            i++;
            K = K->getpNext();
        }
        p->setpNext(K->getpNext());
        K->setpNext(p);
    }
}

void doubleList::importAfterQ(Element *P, Element *Q) {
    if(Q == pTail) {
        Q->setpNext(P);
        P->setpPre(Q);
        P->setpNext(nullptr);
        pTail = P;
    }
    else if(Q != nullptr) {
        P->setpNext(Q->getpNext());
        P->setpPre(Q);
        Q->getpNext()->setpPre(P);
        Q->setpNext(P);
        if(pTail == Q) {
            pTail = P;
        }
    }
    else {
        importFirst(P->getData());
    }
}

void doubleList::deleteFirst() {
    if(pHead == nullptr) {
        cout << "\nNo element to delete";
    }
    else {
        if(listLen() == 1) {
            pHead = nullptr;
            pTail = nullptr;
        }
        else {
            Element *K = pHead;
            pHead->getpNext()->setpPre(nullptr);
            pHead = pHead->getpNext();
            delete K;
        }
    }
}

void doubleList::deleteLast() {
    if(pHead == nullptr) {
        cout << "\nNo element to delete";
    }
    else if(pHead->getpNext() == nullptr) {
        deleteFirst();
    }
    else {
        if(listLen() == 1) {
            pHead = nullptr;
            pTail = nullptr;
        }
        else {
            Element *K = pTail;
            pTail->getpPre()->setpNext(nullptr);
            pTail = pTail->getpPre();
            delete K;
        }
    }
}

void doubleList::deleteIndex(int index) {
    if(index < 1 || index > listLen()) {
        cout << "\nNo element to delete";
    }
    else if(index == 1) {
        deleteFirst();
    }
    else if(index == listLen()) {
        deleteLast();
    }
    else {
        Element *K = pHead;
        int i = 1;
        while(i != index) {
            K = K->getpNext();
            i++;
        }
        Element *Q = K;
        K->getpPre()->setpNext(K->getpNext());
        K->getpNext()->setpPre(K->getpPre());
        delete Q;
    }
}

/*void doubleList::deleteValue(int value) {
    if(pHead == nullptr) cout << "\nNo element to delete";
    while(Position(value)) {
        deleteIndex(Position(value));
    }
}*/

void doubleList::deleteValue(int value) {
    if(pHead == nullptr) {
        cout << "\nNo element to delete";
    }
    else {
        Element *K = pHead;
        while(K != nullptr) {
            if(K->getData() == value) {
                if(K == pHead) {
                    deleteFirst();
                    K = pHead;
                }
                else if(K == pTail) {
                    deleteLast();
                    K = nullptr;
                }
                else {
                    Element *Q = K;
                    K->getpPre()->setpNext(K->getpNext());
                    K->getpNext()->setpPre(K->getpPre());
                    K = K->getpNext();
                    delete Q;
                }
            }
            else {
                K = K->getpNext();
            }
        }
    }
}

void doubleList::deleteAfterQ(Element *Q) {
    if(Q != pTail) {
        Element *K = Q->getpNext();
        Q->setpNext(nullptr);
        pTail = Q;
        delete K;
    }
    else if(Q != nullptr) {
        Element *K = Q->getpNext();
        Q->setpNext(K->getpNext());
        K->getpNext()->setpPre(Q);
        delete K;
    }
    else {
        deleteFirst();
    }
}

int main()
{
    doubleList L;
    L.Create(); // Create linked list L
    int n;
    cout << "Enter quantity of linked list: "; cin >> n;
    L.importList(n);
    L.printListHead();
    L.printListTail();
    /*cout << "\nLength of linked list: " << L.listLen();
    cout << "\nPosition 5 in linked list: " << L.Position(5);
    cout << "\nImport 6 with index 6";
    L.importIndex(6, 6);
    cout << "\n\nAfter import: ";
    L.printListHead();
    L.printListTail();
    cout << "\n\nAfter delete first";
    L.deleteFirst();
    L.printListHead();
    L.printListTail();
    cout << "\n\nAfter delete last";
    L.deleteLast();
    L.printListHead();
    L.printListTail();
    cout << "\n\nAfter delete index 2";
    L.deleteIndex(2);
    L.printListHead();
    L.printListTail();
    cout << "\n\nAfter delete value 1";
    L.deleteValue(1);
    L.printListHead();
    L.printListTail();
    Element *P = P->createElement(5);
    int indexQ;
    cout << "\nEnter index Q: "; cin >> indexQ;
    cout << "After import after Q";
    L.importAfterQ(P, L.RuntoQ(indexQ - 1));
    L.printListHead();
    L.printListTail();*/
    int indexQ;
    cout << "\nEnter index Q: "; cin >> indexQ;
    cout << "After delete after Q";
    L.deleteAfterQ(L.RuntoQ(indexQ - 1));
    L.printListHead();
    L.printListTail();
    return 0;
}
