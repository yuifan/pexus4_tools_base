#ifndef __STACKTEST3_H__
#define __STACKTEST3_H__

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define ADD_NODE    1
#define REM_NODE    2
#define PRINT_ALL   3
#define SAVE        4
#define RESTORE     5
#define QUIT        6

using namespace std;
class StackTest3 {
public:
    int value;
    StackTest3* linked;
    
    StackTest3();
    ~StackTest3();
};

bool isEmptyNodePool();
bool isEmptyStack();
int input();
void setNodeValue(StackTest3*);
StackTest3* addNewNode();
void addNode();
void remNode();
void printStack();
void printAll();
void printMainMenu();
void saveStackToFile(StackTest3*);
void restoreNode(int);
void restoreNodes(int, int*);
void restoreStackFromFile(StackTest3*);
void save();
void restore();
void releaseHEAD();
void releasePOOL();
void releaseAllNodes();
void quit();


#endif