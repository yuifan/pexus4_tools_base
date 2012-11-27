#ifndef __CAR_H__
#define __CAR_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

namespace CAR_CONST {
    enum {
        ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
        ACC_STEP = 10, BRK_STEP = 20
    };
};

class Car {
private:
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

public:
    void initMembers(char*, int);
    void showCarState();
    void accel();
    void _break();
};

#endif