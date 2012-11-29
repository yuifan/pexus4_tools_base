#ifndef __STACK_TEST_1_H__
#define __STACK_TEST_1_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

#define ADD_NODE    1
#define REM_NODE    2
#define PRINT_ALL   3
#define QUIT        4

using namespace std;

class StackTest1 {
public:
    int value;
    StackTest1* linked;
    
    StackTest1();
    ~StackTest1();
};

#endif