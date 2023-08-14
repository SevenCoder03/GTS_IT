#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void findSum(int n, vector<int>& v, int start) {
    if (n == 0) {
        printVector(v);
        return;
    }

    for (int i = start; i <= n; i++) {
        v.push_back(i);
        findSum(n - i, v, i);
        v.pop_back();
    }
}

void findUniqueSum(int n) {
    vector<int> v;
    findSum(n, v, 1);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    cout << "All unique sums of " << n << ":\n";
    findUniqueSum(n);

    return 0;
}

