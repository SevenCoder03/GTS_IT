#include "rect2.h"

int Rectangle::thisMany = 0;

int Rectangle::howMany() {
    return thisMany;
}

Rectangle::Rectangle()
{
    this->len = 10;
    this->wid = 10;
    thisMany++;
    fillString = nullptr;
}

Rectangle::Rectangle(double len, double wid, char *fillString) {
    this->len = len;
    while(this->len < 0 || this->len > 20){
        if(this->len < 0 || this->len > 20) {
            double newLength;
            cout << "Length valid!!!\n Enter again Length: "; cin >> newLength;
            this->len = newLength;
        }
    }

    this->wid = wid;
    while(this->wid < 0 || this->wid > 20){
        if(this->wid < 0 || this->wid > 20) {
            double newWidth;
            cout << "Width valid!!!\n Enter again Width:"; cin >> newWidth;
            this->wid = newWidth;
        }
    }

    thisMany++;
    this->fillString = new char[strlen(fillString)+1];
    strcpy(this->fillString, fillString);
}

void Rectangle::setLength(double len) {
    this->len = len;
}

void Rectangle::setWidth(double wid) {
    this->wid = wid;
}

double Rectangle::getLength() const {
    return len;
}

double Rectangle::getWidth() const {
    return wid;
}

double Rectangle::perimeter() const {
    return (len+wid)*2;
}
double Rectangle::area() const {
    return len*wid;
}

double Rectangle::diagonal() const {
    return sqrt(pow(len, 2) + pow(wid, 2));
}

void Rectangle::display() const {
    if(fillString != nullptr) {
        cout << len << " x " << wid << " x " << fillString << endl;
    }
    else {
        cout << len << " x " << wid << endl;
    }
}

bool Rectangle::isSquare() const {
    if(len == wid)
        return true;
    return false;
}

void Rectangle::draw(char c) const {
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

char* Rectangle::fill() const {
    return fillString;
}

Rectangle::~Rectangle() {
    if(fillString != nullptr) {
        delete []fillString;
    }
    thisMany--;
}
