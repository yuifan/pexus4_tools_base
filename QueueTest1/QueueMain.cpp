#include "QueueTest1.h"
void addNode();
void remNode();
void printAll();

QueueTest1* HEAD = NULL;

int main(void) {
    while(1) {
        int userSelection;
        cout << "1. Add Node" << endl;
        cout << "2. Rem Node" << endl;
        cout << "3. Print" << endl;
        cout << "Select: ";     cin >> userSelection;
        
        switch(userSelection) {
        case ADD_NODE:
            addNode();
            break;
        case REM_NODE:
            remNode();
            break;
        case PRINT_ALL:
            printAll();
            break;
        default:
            cout << "Fault!!" << endl;
        }
    }
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
        QueueTest1* ppre = NULL;
        QueueTest1* pre = NULL;
        QueueTest1* cur = HEAD;
        while(cur != NULL) {
            ppre = pre;
            pre = cur;
            cur = cur->link_field;
        }
        if (pre == HEAD) {
            delete pre;
            HEAD = NULL;
        } else {
            delete pre;
            ppre->link_field = NULL;
        }
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