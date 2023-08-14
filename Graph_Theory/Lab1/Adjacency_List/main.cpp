#include <iostream>
#include <fstream>
#define Max 100
using namespace std;

int n;
int label[Max];
int matrix[Max][Max];

struct Node {
    int data;
    Node *pNext;
};

struct List {
    Node *pHead;
    Node *pTail;
};

List adjList[Max];

void createList(List &L){
    L.pHead = nullptr;
    L.pTail = nullptr;
}

void setMatrix() {
    for (int i = 0; i < n; i++) {
        createList(adjList[i]);
    }
}

void addEdge(int x, int y) {
    Node *node = new Node;
    node->data = y;
    node->pNext = nullptr;
    if(adjList[x].pHead == nullptr) {
        adjList[x].pHead = node;
        adjList[x].pTail = node;
    }
    else {
        adjList[x].pTail->pNext = node;
        adjList[x].pTail = node;
    }
}

void printAdjList(List &L) {
    Node *K = L.pHead;
    if(K != nullptr) {
         cout << " -> ";
    }
    while(K != nullptr) {
        if(K->pNext != nullptr){
            cout << K->data << " -> ";
            K = K->pNext;
        }
        else {
            cout << K->data;
            K = K->pNext;
        }
    }
}

void readFile() {
    ifstream inFile;
    inFile.open("Graph2.txt", ios::in);
    inFile >> n;
    setMatrix();
    int x;
    for(int i = 0; i < n; i++) {
        inFile >> label[i];
    }

    for(int i = 0; i < n; i++) {
        inFile >> x;
        while(x != -1) {
            addEdge(i, x);
            inFile >> x;
        }
    }
    inFile.close();
}

void countDegree() {
    cout << endl;
    for(int i = 0; i < n; i++) {
        int Count = 0;
        Node *K = adjList[i].pHead;
        while(K != nullptr) {
            if(K != nullptr){
                Count++;
            }
            K = K->pNext;
        }
        cout << "Deg(" << label[i] << ") = " << Count << endl;
    }
}

//Phan co huong
void countInDegree() {
    cout << endl;
    for(int i = 0; i < n; i++) {
        int Count = 0;
        for(int j = 0; j < n; j++) {
            Node *K = adjList[j].pHead;
            while(K != nullptr) {
                if(K != nullptr && K->data == label[i]){
                    Count++;
                }
                K = K->pNext;
            }
        }
        cout << "InDeg(" << label[i] << ") = " << Count << endl;
    }
}

void countOutDegree() {
    cout << endl;
    for(int i = 0; i < n; i++) {
        int Count = 0;
        Node *K = adjList[i].pHead;
        if(K != nullptr) {
            Count++;
        }
        while(K != nullptr) {
            if(K->pNext != nullptr){
                Count++;
            }
            K = K->pNext;
        }
        cout << "OutDeg(" << label[i] << ") = " << Count << endl;
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << label[i];
        printAdjList(adjList[i]);
        cout << endl;
    }
}

int main()
{
    readFile();
    print();
    countDegree();
    //countInDegree();
    //countOutDegree();
    return 0;
}
