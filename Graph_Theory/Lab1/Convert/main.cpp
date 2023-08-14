#include <iostream>
#include <fstream>
#define Max 100
using namespace std;

int n;
int Egde;
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

void addNode(int x, int y) {
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

void readMatrixToList() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1) {
                addNode(i, j);
            }
        }
    }
}

void addEdge(int x, int y) {
    matrix[x][y] = 1;
}

void findIndexEgde(int x, int y) {
    for(int i = 0; i < n; i++) {
        if(x == label[i]) {
            x = i;
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(y == label[i]) {
            y = i;
            break;
        }
    }
    addEdge(x, y);
}

void findIndexList(int x, int y) {
    for(int i = 0; i < n; i++) {
        if(y == label[i]) {
            y = i;
            break;
        }
    }
    addEdge(x, y);
}

void readFileMatrix() {
    ifstream inFile;
    inFile.open("Adjacency matrix (in).txt", ios::in);
    inFile >> n;
    while (!inFile.eof()) {
        for(int i = 0; i < n; i++) {
            inFile >> label[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                inFile >> matrix[i][j];
            }
        }
        if (inFile.eof()) {
            break;
        }
    }
    inFile.close();
}

void readFileList() {
    ifstream inFile;
    inFile.open("Adjacency list (in).txt", ios::in);
    inFile >> n;
    setMatrix();
    int x;
    for(int i = 0; i < n; i++) {
        inFile >> label[i];
    }

    for(int i = 0; i < n; i++) {
        inFile >> x;
        while(x != -1) {
            findIndexList(i, x);
            inFile >> x;
        }
    }
    inFile.close();
}

void readFileEgde() {
    ifstream inFile;
    inFile.open("Edge, arc list (in).txt", ios::in);
    inFile >> n;
    for(int i = 0; i < n; i++) {
        inFile >> label[i];
    }
    inFile >> Egde;
    int x, y;
    for(int i = 0; i < Egde; i++) {
        inFile >> x >> y;
        findIndexEgde(x, y);
    }
    inFile.close();
}

void writeFileMatrix() {
    ofstream outFile;
    outFile.open("Adjacency matrix (out).txt", ios::out);
    outFile << n << endl;
    for(int i = 0; i < n; i++) {
        outFile << label[i] << " ";
    }
    outFile << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }
}

void writeFileEgde() {
    ofstream outFile;
    outFile.open("Edge, arc list (out).txt", ios::out);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1) {
                outFile << label[i] << " " << label[j] << endl;
            }
        }
    }
}

void writeFileList() {
    ofstream outFile;
    outFile.open("Adjacency list (out).txt", ios::out);
    for (int i = 0; i < n; i++) {
        outFile << label[i];
        Node *K = adjList[i].pHead;
        if(K != nullptr) {
            outFile << " -> ";
        }
        while(K != nullptr) {
            if(K->pNext != nullptr){
                outFile << label[K->data] << " -> ";
                K = K->pNext;
            }
            else {
                outFile << label[K->data];
                K = K->pNext;
            }
        }
        outFile << endl;
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

void print() {
    for (int i = 0; i < n; i++) {
        cout << label[i];
        printAdjList(adjList[i]);
        cout << endl;
    }
}

int main()
{
    readFileEgde();
    readMatrixToList();
    writeFileList();
    return 0;
}
