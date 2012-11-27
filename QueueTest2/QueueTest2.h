#ifndef __QUEUE_TEST2_H__
#define __QUEUE_TEST2_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

#define ADD_NODE        1
#define ADD_NODE_FST    10
#define ADD_NODE_LST    11

#define REM_NODE        2
#define REM_NODE_FST    20
#define REM_NODE_LST    21

#define PRINT_ALL       3
#define QUIT            4
#define BACK_MAIN       5


using namespace std;

class QueueTest2 {
public:
    int value;
    QueueTest2* linked;
    
    QueueTest2();
    ~QueueTest2();
};

#endif