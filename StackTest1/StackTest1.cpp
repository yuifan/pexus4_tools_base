#include "StackTest1.h"

StackTest1::StackTest1(): value(0), linked(NULL) {
}

StackTest1::~StackTest1() {
    delete linked;
}