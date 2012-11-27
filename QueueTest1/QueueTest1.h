#ifndef __QUEUE_TEST_H__
#define __QUEUE_TEST_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class QueueTest1 {
public:
    int value;
    QueueTest1* link_field;
    
    QueueTest1();
    ~QueueTest1();
};

#endif
    