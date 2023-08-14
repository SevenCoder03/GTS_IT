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

void printSolution(int path[])
{
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < n; i++)
        cout << path[i] << " ";

    cout << path[0] << " ";
    cout << endl;
}

bool isSafe(int v, int path[], int pos)
{
    if (matrix[path[pos - 1]][ v ] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(int path[], int pos)
{
    if (pos == n)
    {
        if (matrix[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < n; v++)
    {
        if (isSafe(v, path, pos))
        {
            path[pos] = v;

            if (hamCycleUtil(path, pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamCycle()
{
    int path[n];
    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;
    if (hamCycleUtil(path, 1) == false )
    {
        cout << "\nSolution does not exist";
        return false;
    }

    printSolution(path);
    return true;
}

int main()
{
    readFile();
    outputMatrix();
    hamCycle();
    return 0;
}
