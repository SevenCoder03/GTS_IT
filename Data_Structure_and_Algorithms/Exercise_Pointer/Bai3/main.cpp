#include <iostream>
using namespace std;

void inputArr(int *&Arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << "Enter Arr[" << i << "]:";
        cin >> *(Arr + i);
    }
}

void outputArr(int *Arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << *(Arr + i)<<" ";
    }
}

int sumArr(int *Arr, int n) {
    int Sum = 0;
    for(int i = 0; i < n; i++) {
        Sum += *(Arr + i);
    }
    return Sum;
}
int main()
{
    int n;
    cout << "Enter quantity: ";
    cin >> n;
    int *Arr = new int[n];
    inputArr(Arr, n);
    outputArr(Arr, n);
    cout << "\nTotal array: " << sumArr(Arr, n);
    delete []Arr;
    return 0;
}
