#include "Car.h"
using namespace std;

void Car::initMembers(char* ID, int fuel) {
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::showCarState() {
    cout << "������ ID: " << gamerID << endl;
    cout << "���ᷮ: " << fuelGauge << " %" << endl;
    cout << "����ӵ�: " << curSpeed << " km/s" << endl << endl;
}

void Car::accel() {
    if (fuelGauge <= 0) {
        return;
    } else {
        fuelGauge -= CAR_CONST::FUEL_STEP;
    }
    
    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD) {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::_break() {
    if (curSpeed < CAR_CONST::BRK_STEP) {
        curSpeed = 0;
        return;
    }
    curSpeed -= CAR_CONST::BRK_STEP;
}