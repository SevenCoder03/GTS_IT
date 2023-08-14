#ifndef RECT_H
#define RECT_H
#include <math.h>
#include <iostream>
using namespace std;

class Rectangle
{
    private:
        double len;
        double wid;
    public:
        Rectangle();
        Rectangle(double len, double wid);
        void setLength(double len);
        void setWidth(double wid);
        double getLength();
        double getWidth();
        double perimeter();
        double area();
        double diagonal();
        void display();
        bool isSquare();
        void draw(char c);
        ~Rectangle();
};

#endif
