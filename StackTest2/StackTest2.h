#ifndef __STACKTEST2_H__
#define __STACKTEST2_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

#define ADD_NODE 1
#define REM_NODE 2
#define PRINT_ALL 3
#define QUIT 4

using namespace std;
class StackTest2 {
public:
    int value;
    StackTest2* linked;
    
    StackTest2();
    ~StackTest2();
};

bool isEmptyNodePool();
bool isEmptyStack();
int input();
void setNodeValue(StackTest2*);
StackTest2* addNewNode();
void addNode();
void remNode();
void printStack();
void printAll();
void printMainMenu();
void quit();


#endif