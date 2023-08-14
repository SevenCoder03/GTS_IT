#include <iostream>
#include <vector>
#define n 8
using namespace std;

vector<int> column(n, 0), c1(2 * n - 1, 0), c2(2 * n - 1, 0);

void printSolution(vector<int> row) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(row[i] == j) {
                cout << "Q ";
            }
            else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void Solution(int i, vector<int> &row) {
    if(i == n) {
        printSolution(row);
        return;
    }

    for(int j = 0; j < n; j++) {
        if (column[j] || c1[j + i] || c2[j - i + n - 1]) continue;
        row.push_back(j);
        column[j] = c1[j + i] = c2[j - i + n - 1] = 1;
        Solution(i + 1, row);
        row.pop_back();
        column[j] = c1[j + i] = c2[j - i + n - 1] = 0;
    }
}

int main()
{
    vector<int> row;
    Solution(0, row);
    return 0;
}
