#include <iostream>

using namespace std;

int *crashAddress() {
     return (int *) 0xDEADBEEF;
}

void crashTest1() {
     int value = 0;
     int * crash = crashAddress();
     cout << *crash << endl;
}

int main(void) {
    cout<<"Hello World!!"<<endl;
    cout<<"Hello World!!"<<endl;
    crashTest1();
    return 0;
}
