#ifndef RECT2_H
#define RECT2_H
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

class Rectangle
{
    private:
        double len;
        double wid;
        static int thisMany;
        char *fillString;
    public:
        Rectangle();
        Rectangle(double len, double wid, char *filString);
        void setLength(double len);
        void setWidth(double wid);
        double getLength() const;
        double getWidth() const;
        double perimeter() const;
        double area() const;
        double diagonal() const;
        void display() const;
        bool isSquare() const;
        void draw(char c) const;
        static int howMany();
        char* fill() const;
        ~Rectangle();
};

#endif
