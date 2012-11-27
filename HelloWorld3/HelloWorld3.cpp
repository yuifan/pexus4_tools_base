#include "HelloWorld3.h"

HelloWorld3::HelloWorld3(char* hello, char* world) {
    this->hello = new char[strlen(hello) + 1];
    this->world = new char[strlen(world) + 1];
    
    strcpy(this->hello, hello);
    strcpy(this->world, world);
}

HelloWorld3::HelloWorld3(const HelloWorld3& hw) {
    this->hello = new char[strlen(hw.hello) + 1];
    this->world = new char[strlen(hw.world) + 1];
    
    strcpy(this->hello, hw.hello);
    strcpy(this->world, hw.world);
}

HelloWorld3::~HelloWorld3() {
    delete[] hello;
    delete []world;
}

void HelloWorld3::printCharSequence() {
    cout << hello << " " << world << endl;
}

int main(void) {
    HelloWorld3 hw1("Hello", "World");
    HelloWorld3 hw2 = hw1;
    
    hw1.printCharSequence();
    hw2.printCharSequence();
    
    return 0;
}