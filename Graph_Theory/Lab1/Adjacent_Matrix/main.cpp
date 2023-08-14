#include <iostream>
#include <fstream>
#define Max 100
using namespace std;

int n;
int label[Max];
int matrix[Max][Max];

/*void addEdge(int x, int y) {
    matrix[x-1][y-1] = 1;
    //matrix[y-1][x-1] = 1; //vo huong thi mo len
}*/

void readFile() {
    ifstream inFile;
    inFile.open("Graph1.txt", ios::in);
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
}

//Phan vo huong
void countDegree() {
    cout << endl;
    for(int i = 0; i < n; i++) {
        int Count = 0;
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                Count++;
            }
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
            if(matrix[j][i] != 0) {
                Count++;
            }
        }
        cout << "InDeg(" << label[i] << ") = " << Count << endl;
    }
}

void countOutDegree() {
    cout << endl;
    for(int i = 0; i < n; i++) {
        int Count = 0;
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] != 0) {
                Count++;
            }
        }
        cout << "OutDeg(" << label[i] << ") = " << Count << endl;
    }
}

int main()
{
    readFile();
    outputMatrix();
    //countDegree();
    countInDegree();
    countOutDegree();
    return 0;
}
