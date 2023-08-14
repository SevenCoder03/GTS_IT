#include <iostream>

using namespace std;

struct Product {
    int idProduct;
    string nameProduct;
    string species;
    int yearOfProduction;
    int numberYearWarranty;
};

struct Node {
    Product data;
    Node *pNext;
    Node *pPre;
};

struct doubleList {
    Node *pHead;
    Node *pTail;
};

void createList(doubleList &L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

int checkNull(doubleList L) {
    if(L.pHead == nullptr)
        return 1;
    return 0;
}

Node* createNode(Product x) {
    Node *p;
    p = new Node;
    p->data = x;
    p->pNext = nullptr;
    p->pPre = nullptr;
    return p;
}

void inputFirst(doubleList &L, Node *p) {
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
    }else {
        p->pNext = L.pHead;
        L.pHead->pPre = p;
        L.pHead = p;
    }
}
void inputLast(doubleList &L, Node *p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
    }else{
        L.pTail->pNext = p;
        p->pPre = L.pTail;
        L.pTail = p;
    }
}

void inputList(doubleList &L, int n) {
    for(int i = 0; i < n; i++) {
        Product x;
        cout << "\nEnter product " << i+1 << ":";
        cout << "\n\tId product: ";
        cin >> x.idProduct;
        cout << "\tName product: ";
        cin >> x.nameProduct;
        cout << "\tSpecies: ";
        cin >> x.species;
        cout << "\tYear of production: ";
        cin >> x.yearOfProduction;
        cout << "\tNumber of years of warranty: ";
        cin >> x.numberYearWarranty;
        Node *p = new Node;
        p = createNode(x);
        inputLast(L, p);
    }
}

void outputList(doubleList L){
    Node *p = new Node;
    int i = 1;
    for(p = L.pHead; p != nullptr; p = p->pNext){
        cout << "\nProduct " << i << ":";
        i++;
        Product x = p->data;
        cout << "\n\tId product: " << x.idProduct;
        cout << "\n\tName product: " << x.nameProduct;
        cout << "\n\tSpecies: " << x.species;
        cout << "\n\tYear of production: " << x.yearOfProduction;
        cout << "\n\tNumber of years of warranty: " << x.numberYearWarranty;
    }
}

void sortList(doubleList &L) {
    Node *p = new Node;
    Node *k = new Node;
    for(p = L.pHead; p != L.pTail; p = p->pNext) {
        for(k = p->pNext; k != nullptr; k = k->pNext) {
            if(p->data.idProduct < k->data.idProduct) {
                swap(p->data, k->data);
            }
        }
    }
}

void deleteFirst(doubleList &L){
    Node *p = L.pHead;
    L.pHead = L.pHead->pNext;
    L.pHead->pPre = nullptr;
    if (L.pHead == nullptr){
        L.pTail = nullptr;
    }
    p->pNext = nullptr;
    delete p;
}

void deleteLast(doubleList &L){
    Node *p = L.pTail;
    L.pTail = L.pTail->pPre;
    L.pTail->pNext = nullptr;
    if (L.pTail==nullptr){
        L.pHead = nullptr;
    }
    p->pPre = nullptr;
    delete p;
}

Node* searchNode(doubleList L, Product x){
    Node *p;
    p = L.pHead;
    while ((p != nullptr) && (p->data.idProduct != x.idProduct)){
        p = p->pNext;
    }
    return p;
}

void deleteIndex(doubleList &L, Product x){
    Node *p = searchNode(L, x);
    if(p != nullptr){
        if (p->pPre == nullptr){
            deleteFirst(L);
            return;
        }
        if (p->pNext == nullptr){
            deleteLast(L);
            return;
        }
        p->pPre->pNext = p->pNext;
        p->pNext->pPre = p->pPre;
        p->pPre = nullptr;
        p->pNext = nullptr;
        delete p;
    }
}

void deleteExpire(doubleList &L) {
    Node *p = new Node;
    for(p = L.pHead; p != nullptr; p = p->pNext){
        if(p->data.yearOfProduction + p->data.numberYearWarranty > 2022) {
            deleteIndex(L, p->data);
        }
    }
}

int main()
{
    doubleList L;
    int n;
    cout << "Enter quantity of product: ";
    cin >> n;
    createList(L);
    inputList(L, n);
    sortList(L);
    cout << "\n\tLIST OF PRODUCT\n";
    outputList(L);
    deleteExpire(L);
    cout << "\n\tLIST OF PRODUCT\n";
    outputList(L);
    return 0;
}
