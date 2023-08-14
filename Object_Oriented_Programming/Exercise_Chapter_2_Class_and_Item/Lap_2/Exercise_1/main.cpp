#include <iostream>
#include "rect2.h"

using namespace std;

int main()
{
    cout << "Starting # of Rectangles: " << Rectangle::howMany() << endl << endl;
    Rectangle a;
    cout << "Rectangle A = ";
    a.display();
    cout << endl << "Now this many Rectangles: " << a.howMany();
    cout << endl << endl;
    Rectangle b(12, 20, "Rectangle B");
    cout << "Rectangle B = ";
    b.display();
    cout << endl << "Now this many Rectangles: " << b.howMany();
    cout << endl << endl;
    {
        const Rectangle c(-5, 15, "Rectangle C");
        cout << "Rectangle C = ";
        c.display();
        cout << endl << "Now this many Rectangles: " << c.howMany();
        cout << endl << "Perimeter of Rectangle C is: " << c.perimeter();
        cout << endl << "Fill string of Rectangle C is: " << c.fill();
        cout << endl << endl;
    }
    cout << "After exiting block, this many Rectangles:" << Rectangle::howMany() << endl << endl;
    return 0;
}
