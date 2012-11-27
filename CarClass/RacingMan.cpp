#include "Car.h"

int main(void) {
    Car run99;
    run99.initMembers("run99", 100);
    run99.accel();
    run99.accel();
    run99.accel();
    run99.showCarState();
    run99._break();
    run99.showCarState();
    
    return 0;
}