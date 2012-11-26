#include "HelloWorld2.h"

HelloWorld2::HelloWorld2() {
    this->hello = new char[strlen("Hello") + 1];
    this->world = new char[strlen("World") + 1];
    strcpy(this->hello, "Hello");
    strcpy(this->world, "World");
}

HelloWorld2::HelloWorld2(char* hello, char* world) {
    this->hello = new char[strlen(hello) + 1];
    this->world = new char[strlen(world) + 1];
    strcpy(this->hello, hello);
    strcpy(this->world, world);
}

HelloWorld2::HelloWorld2(const HelloWorld2& v) {
    hello = new char[strlen(v.hello) + 1];
    world = new char[strlen(v.world) + 1];

    strcpy(hello, v.hello);
    strcpy(world, v.world);
}

HelloWorld2::~HelloWorld2() {
    delete[] this->hello;
    delete[] this->world;
}

void HelloWorld2::printString() {
    cout << hello << " " << world << endl;
}

int main(void) {
    HelloWorld2* hw1 = new HelloWorld2();
    HelloWorld2* hw2 = new HelloWorld2("Wonderful", "World!!");
    //HelloWorld2 hw3 = hw2;

    hw1->printString();
    hw2->printString();
    //hw3->printString();

    delete hw1;
    delete hw2;
    //delete hw3;

    return 0;
} 
