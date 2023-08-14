#include "rect.h"

Rectangle::Rectangle()
{
    this->len = 10;
    this->wid = 10;
}

Rectangle::Rectangle(double len, double wid) {
    this->len = len;
    this->wid = wid;
}

void Rectangle::setLength(double len) {
    this->len = len;
}

void Rectangle::setWidth(double wid) {
    this->wid = wid;
}

double Rectangle::getLength() {
    return len;
}

double Rectangle::getWidth() {
    return wid;
}

double Rectangle::perimeter() {
    return (len+wid)*2;
}
double Rectangle::area() {
    return len*wid;
}

double Rectangle::diagonal() {
    return sqrt(pow(len, 2) + pow(wid, 2));
}

void Rectangle::display() {
    cout << len << "x" << wid << endl;
    while(this->len < 0 || this->len > 20){
        if(this->len < 0 || this->len > 20) {
            double newLength;
            cout << "Length valid!!!\n Enter again Length: "; cin >> newLength;
            this->len = newLength;
        }
        cout << len << "x" << wid << endl;
    }

    while(this->wid < 0 || this->wid > 20){
        if(this->wid < 0 || this->wid > 20) {
            double newWidth;
            cout << "Width valid!!!\n Enter again Width:"; cin >> newWidth;
            this->wid = newWidth;
        }
        cout << len << "x" << wid << endl;
    }
}

bool Rectangle::isSquare() {
    if(len == wid)
        return true;
    return false;
}

void Rectangle::draw(char c) {
    for(int i=1; i<=wid; i++) {
        for(int j=1; j<=len; j++) {
            if(i == 1 || i == wid || j == len || j == 1)
            {
                cout << c << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

Rectangle::~Rectangle() {}
