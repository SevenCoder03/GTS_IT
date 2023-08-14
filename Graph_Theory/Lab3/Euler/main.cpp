#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#define Max 100
using namespace std;


int n;
int Egde;
int label[Max];
int matrix[Max][Max];
bool visited[Max];

void setVisited() {
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
}

int findIndex(int x) {
    for(int i = 0; i < n; i++) {
        if(x == label[i]) {
            return i;
        }
    }
    return -1;
}

void readFile() {
    ifstream inFile;
    inFile.open("Graph6.txt", ios::in);
    inFile >> n;
    inFile >> Egde;
    for(int i = 0; i < n; i++) {
        inFile >> label[i];
    }
    int x, y;
    for(int i = 0; i < Egde; i++) {
        inFile >> x >> y;
        matrix[findIndex(x)][findIndex(y)] = 1;
    }
    inFile.close();
}

void convertMatrix() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                matrix[i][j] = 1;
                matrix[j][i] = 1;
            }
        }
    }
}

void outputMatrix() {
    for(int i = 0; i < n; i++) {
            cout << label[i] << " ";
    }
    cout << endl << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool DFS(int start) {
    setVisited();
    stack<int> dfs;
    int indexStart = findIndex(start);
    visited[indexStart] = true;
    dfs.push(indexStart);
    while(!dfs.empty()) {
        int t = dfs.top();
        dfs.pop();
        for(int i = 0; i < n; i++) {
            if(matrix[t][i] == 1 && visited[i] == false) {
                dfs.push(i);
                visited[i] = true;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            return false;
        }
    }
    return true;
}

bool checkGraph() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isConnected() {
    for(int i = 0; i < n; i++) {
        if(DFS(label[i]) == false) {
            return false;
        }
    }
    return true;
}

int countDeg(int start) {
    int i = findIndex(start);
    int Count = 0;
    for(int j = 0; j < n; j++) {
        if(matrix[i][j] != 0) {
            Count++;
        }
    }
    return Count;
}

int countDegOdd() {
    int countOdd = 0;
    for(int i = 0; i < n; i++) {
        int Count = 0;
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                Count++;
            }
        }
        if(Count % 2 != 0) {
            countOdd++;
        }
    }
    return countOdd;
}

int countDegBalance() {
    int degBalance = 0, in = 0, out = 0;
    for(int i = 0; i < n; i++) {
        int inDeg = 0, outDeg = 0;
        for(int j = 0; j < n; j++) {
            if(matrix[j][i] != 0) {
                inDeg++;
            }
            if(matrix[i][j] != 0) {
                outDeg++;
            }
        }
        if(inDeg == outDeg) {
            degBalance++;
        }
        else if(inDeg == outDeg + 1) {
            out++;
        }
        else if(inDeg == outDeg - 1) {
            in++;
        }
    }
    if(degBalance == Egde) {
        return 0;
    }
    else if (out == in && out == 1 && in == 1) {
        return 1;
    }
    else {
        return 2;
    }
}

void outAEuler(vector<int> euler) {
    for(int i = euler.size() - 1; i >= 0; i--) {
        cout << label[euler[i]] << " ";
    }
    cout << endl;
}

void Euler(int start) {
    stack<int> Stack;
    vector<int> euler;
    int indexStart = findIndex(start);
    Stack.push(indexStart);
    while(!Stack.empty()) {
        int t = Stack.top();
        bool check = false;
        for(int i = 0; i < n; i++) {
            if(matrix[t][i] != 0) {
                matrix[t][i] = 0;
                matrix[i][t] = 0;
                Stack.push(i);
                break;
            }
            if(i == n - 1) {
                check = true;
            }
        }
        if(check == true) {
            t = Stack.top();
            Stack.pop();
            euler.push_back(t);
        }
    }
    outAEuler(euler);
}

void outAllEuler(bool check) {
    for(int i = 0; i < n; i++) {
        readFile();
        if(check) {
            cout << "Eulerian Cycle: ";
            Euler(label[i]);
        }
        else {
            if(countDeg(label[i]) % 2 != 0) {
                cout << "Eulerian Path: ";
                Euler(label[i]);
            }
        }
    }
}

int main()
{
    readFile();
    outputMatrix();
    if(checkGraph() == true) {
        cout << "The graph is undirected" << endl;
        if(isConnected() == false) {
            cout << "The graph is not Eulerian because is not Connected" << endl;
        }
        else if(countDegOdd() == 0){
            cout << "The graph has Euler Circuit" << endl;
            outAllEuler(1);
        }
        else if(countDegOdd() == 2) {
            cout << "The graph has Euler Path" << endl;
            outAllEuler(0);
        }
        else {
            cout << "The graph is not Eulerian" << endl;
        }
    }
    else {
        cout << "The graph is directed" << endl;
        int balance = countDegBalance();
        convertMatrix();
        if(isConnected() == false) {
            cout << "The graph is not Eulerian because is not Connected" << endl;
        }
        else if(balance == 0) {
            cout << "The graph has Euler Circuit" << endl;
            outAllEuler(1);
        }
        else if(balance == 1) {
            cout << "The graph has Euler Path" << endl;
            outAllEuler(0);
        }
        else if(balance == 2) {
            cout << "The graph is not Eulerian" << endl;
        }
    }
    return 0;
}
