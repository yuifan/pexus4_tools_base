#include "Point.h"

int main(void) {
    Point p1;
    Point p2;
    Point p3;
    
    p1.initMembers(100, 0);
    p2.initMembers(50, 10);
    p3.initMembers(0, 45);
    
    cout << "P1: " << p1.getX() << ", " << p1.getY() << endl;
    cout << "P2: " << p2.getX() << ", " << p2.getY() << endl;
    cout << "P3: " << p3.getX() << ", " << p3.getY() << endl << endl;
    
    p1.setX(90), p1.setY(50);
    p2.setX(30), p2.setY(99);
    p3.setX(74), p3.setY(61);
    
    cout << "P1: " << p1.getX() << ", " << p1.getY() << endl;
    cout << "P2: " << p2.getX() << ", " << p2.getY() << endl;
    cout << "P3: " << p3.getX() << ", " << p3.getY() << endl;
    
    return 0;
}