#include <bits/stdc++.h>
using namespace std;
#define n 6

int label[n] = {1, 2, 3, 4, 5, 6};

int minKey(int key[], bool visited[])
{
    int Min = INT_MAX, min_index;

    for (int i = 0; i < n; i++)
        if (visited[i] == false && key[i] < Min)
            Min = key[i], min_index = i;

    return min_index;
}

void printMST(int front[], int matrix[n][n])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < n; i++)
        cout << label[front[i]] << " - " << label[i] << " \t  " << matrix[i][front[i]] << " \n";
}

void primMST(int matrix[n][n])
{
    int front[n];
    int key[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, visited[i] = false;

    key[0] = 0;
    front[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, visited);
        visited[u] = true;
        for (int i = 0; i < n; i++)
            if (matrix[u][i] && visited[i] == false && matrix[u][i] < key[i]) {
                front[i] = u, key[i] = matrix[u][i];
            }
    }

    printMST(front, matrix);
}

int main()
{
    int matrix[n][n] = {{0, 5, 0, 0, 0, 1},
                       {5, 0, 3, 0, 0, 9},
                       {0, 3, 0, 8, 7, 4},
                       {0, 0, 8, 0, 2, 0},
                       {0, 0, 7, 2, 0, 6},
                       {1, 9, 4, 0, 6, 0}};

    primMST(matrix);
    return 0;
}
