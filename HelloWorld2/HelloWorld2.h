#ifndef _HELLO_WORLD_H_
#define _HELLO_WORLD_H_

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class HelloWorld2 {
public:
    char* hello;
    char* world;

    //Default Constructor
    HelloWorld2();

    //Constructor
    HelloWorld2(char*, char*);

    //Copy Constructor
    HelloWorld2(const HelloWorld2& helloworld);

    //Destructor
    ~HelloWorld2();

    void printString();
};

#endif
