#ifndef __QUEUE_TEST_H__
#define __QUEUE_TEST_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define ADD_NODE    1
#define REM_NODE    2
#define PRINT_ALL   3

class QueueTest1 {
public:
    int value;
    QueueTest1* link_field;
    
    QueueTest1();
    ~QueueTest1();
};

#endif
    