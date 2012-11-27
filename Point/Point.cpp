#include "Point.h"

void Point::initMembers(int xPos, int yPos) {
    x = xPos;
    y = yPos;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

bool Point::setX(int value) {
    if (value < 0 && value > 100) {
        cout << "��� ������ �� �Է�" << endl;
        return false;
    }
    x = value;
    return true;
}

bool Point::setY(int value) {
    if (value < 0 && value > 100) {
        cout << "��� ������ �� �Է�" << endl;
        return false;
    }
    y = value;
    return true;
}