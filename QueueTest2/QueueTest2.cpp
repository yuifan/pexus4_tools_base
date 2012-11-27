#include "QueueTest2.h"

QueueTest2::QueueTest2(): value(0), linked(NULL) {
}

QueueTest2::~QueueTest2() {
    delete linked;
}