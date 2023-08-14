#include <iostream>
#include <string.h>
using namespace std;

char *themch(char *s, char *subs, int pos)
{
    char *c = new char[strlen(s)+strlen(subs)+1];
    strcpy(c, s + pos);
    strcpy(s + pos, subs);
    strcat(s , c);
    delete []c;
    return s;
}

int main()
{
    char *s = new char[9999999];
    char *subs = new char[9999999];
    int pos;
    cout << "Nhap chuoi: ";
    cin.getline(s, 9999999);
    cout << "Nhap chuoi con: ";
    cin.getline(subs, 9999999);
    cout << "Nhap vi tri can them: ";
    cin >> pos;
    cout << themch(s, subs, pos);
    delete []s;
    delete []subs;
    return 0;
}
