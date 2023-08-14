#include <iostream>

using namespace std;

void binaryString(string stringNumber, int n) {
    if(n == 0) {
        cout << stringNumber << endl;
        return;
    }

    if(stringNumber[stringNumber.length() - 1] != '0') {
        binaryString(stringNumber + '0', n - 1);
    }

    binaryString(stringNumber + '1', n - 1);
}

int main()
{
    binaryString("", 10);
    return 0;
}
