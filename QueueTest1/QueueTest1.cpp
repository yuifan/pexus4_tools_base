#include "QueueTest1.h"

QueueTest1::QueueTest1(): value(0), link_field(NULL) {
}

QueueTest1::~QueueTest1() {
    delete link_field;
}
/*
void addNode() {
    QueueTest1* newNode = new QueueTest1();
    if (HEAD == NULL) {
        HEAD = newNode;
        newNode->value = 1;
    } else {
        int i = 1;
        QueueTest1* p = HEAD;
        while (p != NULL) {
            i++;
            p = p->link_field;
        }
        newNode->value = i;
        p->link_field = newNode;
    }
}

void remNode() {
    if (HEAD == NULL) {
        return;
    } else {
        QueueTest1* pre = NULL;
        QueueTest1* cur = HEAD;
        while(cur != NULL) {
            pre = cur;
            cur = cur->link_field;
        }
        delete pre;
        pre = NULL;
    }
}

void printAll() {
    if (HEAD == NULL) {
        return;
    } else {
        QueueTest1* p = HEAD;
        while(p != NULL) {
            //print!!
            p = p->link_field;
        }
    }
}
*/