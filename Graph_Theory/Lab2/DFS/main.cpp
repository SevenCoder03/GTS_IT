#include <iostream>
#include <fstream>
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

void addEdge(int x, int y) {
    matrix[x][y] = 1;
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
    inFile.open("3a.txt", ios::in);
    inFile >> n;
    for(int i = 0; i < n; i++) {
        inFile >> label[i];
    }
    inFile >> Egde;
    int x, y;
    for(int i = 0; i < Egde; i++) {
        inFile >> x >> y;
        addEdge(findIndex(x), findIndex(y));
    }
    inFile.close();
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

void DFS(int start) {
    setVisited();
    stack<int> dfs;
    int indexStart = findIndex(start);
    visited[indexStart] = true;
    dfs.push(indexStart);
    cout << "DFS(" << start << "): ";
    while(!dfs.empty()) {
        int t = dfs.top();
        dfs.pop();
        cout << label[t] << " ";
        for(int i = 0; i < n; i++) {
            if(matrix[t][i] == 1 && visited[i] == false) {
                dfs.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    readFile();
    outputMatrix();
    DFS(8);
    return 0;
}
