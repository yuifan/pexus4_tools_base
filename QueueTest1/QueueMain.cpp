#include "QueueTest1.h"
void addNode();
void remNode();
void printAll();

QueueTest1* HEAD = NULL;

int main(void) {
    addNode();
    addNode();
    addNode();
    
    printAll();
    
    return 0;
}

void addNode() {
    QueueTest1* newNode = new QueueTest1();
    newNode->link_field = NULL;
    if (HEAD == NULL) {
        HEAD = newNode;
        newNode->value = 1;
    } else {
        int i = 1;
        QueueTest1* pre = NULL;
        QueueTest1* cur = HEAD;
        while (cur != NULL) {
            i++;
            pre = cur;
            cur = cur->link_field;
        }
        newNode->value = i;
        pre->link_field = newNode;
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
            cout << "Value: " << p->value << endl;
            p = p->link_field;
        }
    }
}