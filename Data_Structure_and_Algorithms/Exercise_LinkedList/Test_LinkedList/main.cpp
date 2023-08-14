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

class List {
    private:
        Element *pHead;
        Element *pTail;
    public:
        void Create();
        int listLen();
        void printList();
        int Position(int x);
        Element *RuntoQ(int index);
        void importList(int n);
        void importFirst(int x);
        void importLast(int x);
        void importIndex(int x, int index);
        void importAfterQ(Element *P, Element *Q);
        void deleteFirst();
        void deleteLast();
        void deleteIndex(int index);
        void deleteValue(int value);
        void deleteAfterQ(Element *Q);
};

void List::Create() {
    pHead = nullptr;
    pTail = nullptr;
}

Element* Element::createElement(int x) {
    Element *p = new Element;
    p->Data = x;
    p->pNext = nullptr;
    return p;
}

void List::printList() {
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
    cout << " ]" << endl;
}

int List::listLen() {
    Element *K = pHead;
    int i = 0;
    while (K != nullptr) {
        i++;
        K = K->getpNext();
    }
    return i;
}

int List::Position(int x) {
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

Element *List::RuntoQ(int indexQ) {
    Element *K = pHead;
    while(indexQ--) {
        K = K->getpNext();
    }
    return K;
}

void List::importFirst(int x) {
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

void List::importLast(int x) {
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

void List::importList(int n) {
    while(n--) {
        int x;
        cout << "Enter x: "; cin >> x;
        importLast(x);
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

void List::importAfterQ(Element *P, Element *Q) {
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
        cout << "\nNo element to delete";
    }
    else {
        Element *K = pHead;
        pHead = pHead->getpNext();
        delete K;
    }
}

void List::deleteLast() {
    if(pHead == nullptr) {
        cout << "\nNo element to delete";
    }
    else if(pHead->getpNext() == nullptr) {
        deleteFirst();
    }
    else {
        Element *K = pHead;
        while(K->getpNext()->getpNext() != nullptr)
        {
            K = K->getpNext();
        }
        Element *Q = K->getpNext();
        K->setpNext(nullptr);
        pTail = K;
        delete Q;
    }
}

void List::deleteIndex(int index) {
    if(index < 1 || index > listLen()) {
        cout << "\nNo element to delete";
    }
    else if(index == 1) {
        deleteFirst();
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

/*void List::deleteValue(int value) {
    if(pHead == nullptr) cout << "\nNo element to delete";
    while(Position(value)) {
        deleteIndex(Position(value));
    }
}*/

void List::deleteValue(int value) {
    if(pHead == nullptr) {
        cout << "\nNo element to delete";
    }
    else {
        Element *K = pHead;
        while(K->getpNext() != nullptr) {
            if(K->getpNext()->getData() == value) {
                Element *Q = K->getpNext();
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

void List::deleteAfterQ(Element *Q) {
    if(Q != pTail && Q != nullptr) {
        Element *K = Q->getpNext();
        Q->setpNext(K->getpNext());
        delete K;
    }
    else {
        deleteFirst();
    }
}

int main()
{
    List L;
    L.Create(); // Create linked list L
    int n;
    cout << "Enter quantity of linked list: "; cin >> n;
    L.importList(n);
    L.printList();
    /*cout << "Length of linked list: " << L.listLen() << endl;
    cout << "Position 5 in linked list: " << L.Position(5) << endl;
    cout << "Import 6 with index 6";
    L.importIndex(6, 6);
    cout << "\nAfter import: ";
    L.printList();
    cout << "After delete first";
    L.deleteFirst();
    L.printList();
    cout << "After delete last";
    L.deleteLast();
    L.printList();
    cout << "After delete index 1";
    L.deleteIndex(1);
    L.printList();
    cout << "After delete value 1";
    L.deleteValue(1);
    L.printList();*/
    Element *P = P->createElement(5);
    int indexQ;
    cout << "Enter index Q: "; cin >> indexQ;
    cout << "After import after Q";
    L.importAfterQ(P, L.RuntoQ(indexQ - 1));
    L.printList();
    /*int indexQ;
    cout << "Enter index Q: "; cin >> indexQ;
    cout << "After delete after Q";
    L.deleteAfterQ(L.RuntoQ(indexQ - 1));
    L.printList();*/
    return 0;
}
