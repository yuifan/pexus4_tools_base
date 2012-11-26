#ifndef _HELLOWORLD3_H_
#define _HELLOWORLD3_H_

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class HelloWorld3 {
private:
    char* hello;
	char* world;
public:
    //Constructor
    HelloWorld3(char*, char*);
    
    //Copy Constructor
    HelloWorld3(const HelloWorld3&);
    
    //Destructor
    ~HelloWorld3();
    
    //PrintMethod
    void printCharSequence();
};

#endif