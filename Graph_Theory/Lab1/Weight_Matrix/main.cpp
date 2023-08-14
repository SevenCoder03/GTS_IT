#include <iostream>
#include <fstream>
#define Max 100
using namespace std;

int n;
int matrix[Max][Max];

void setMatrix() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }
}

void addEdge(int x, int y, int weight) {
    matrix[x-1][y-1] = weight;
    //matrix[y-1][x-1] = weight; //vo huong thi mo len
}

void readFile() {
    ifstream inFile;
    inFile.open("Matrix.txt", ios::in);
    inFile >> n;
    setMatrix();
    while (!inFile.eof()) {
        int x, y, w;
        inFile >> x >> y >> w;
        addEdge(x, y, w);
        if (inFile.eof()) {
            break;
        }
    }
    inFile.close();
}

void outputMatrix() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    readFile();
    outputMatrix();
    return 0;
}
