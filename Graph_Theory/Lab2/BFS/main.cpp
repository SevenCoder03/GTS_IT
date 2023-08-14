#include <iostream>
#include <fstream>
#include <queue>
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
    inFile.open("Graph1.txt", ios::in);
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

void BFS(int start) {
    setVisited();
    queue<int> bfs;
    int indexStart = findIndex(start);
    visited[indexStart] = true;
    bfs.push(indexStart);
    cout << "BFS(" << start << "): ";
    while(!bfs.empty()) {
        int t = bfs.front();
        bfs.pop();
        cout << label[t] << " ";
        for(int i = 0; i < n; i++) {
            if(matrix[t][i] == 1 && visited[i] == false) {
                bfs.push(i);
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
    /*BFS(1);
    BFS(2);
    BFS(3);
    BFS(4);
    BFS(5);*/
    BFS(2);
    BFS(3);
    BFS(5);
    BFS(7);
    BFS(8);
    BFS(9);
    BFS(10);
    BFS(11);
    return 0;
}
