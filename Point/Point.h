#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Point {
private:
    int x;
    int y;
    
public:
    void initMembers(int, int);
    int getX();
    int getY();
    bool setX(int value);
    bool setY(int value);
};

#endif