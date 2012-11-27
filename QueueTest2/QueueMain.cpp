#include "QueueTest2.h"

void addNode();
void addNodeFst();
void addNodeLst();
void remNode();
void remNodeFst();
void remNodeLst();
void printAll();
int input();
void quit();
void printMainSelect();
void printAddSelect();
void printRemSelect();

QueueTest2* HEAD = NULL;

int main(void) {
    while(1){
        printMainSelect();
        int mainSelect = input();
        switch(mainSelect) {
        case ADD_NODE:
            addNode();
            break;
        case REM_NODE:
            remNode();
            break;
        case PRINT_ALL:
            printAll();
            break;
        case QUIT:
            cout << "quit~" << endl;
            quit();
            return 0;
        default:
            cout << "Fault!!" << endl;
        }
    }
    return 0;
}

//Add Node
void addNode() {
    printAddSelect();
    int sel = input();
    
    switch(sel) {
    case ADD_NODE_FST:
        addNodeFst();
        break;
    case ADD_NODE_LST:
        addNodeLst();
        break;
    case BACK_MAIN:
    default:
        return;
    }
}

void addNodeFst() {
    int input;
    cout << "value: ";      cin >> input;
    QueueTest2* newNode = new QueueTest2;
    newNode->value = input;
    if (HEAD == NULL) {
        HEAD = newNode; 
        newNode->linked = NULL;
    } else {
        newNode->linked = HEAD;
        HEAD = newNode;
    }
}

void addNodeLst() {
    int input;
    cout << "value: ";      cin >> input;
    QueueTest2* newNode = new QueueTest2;
    newNode->value = input;
    newNode->linked = NULL;
    if (HEAD == NULL) {
        HEAD = newNode;
    } else {
        QueueTest2* p = HEAD;
        while(p->linked != NULL) {
            p = p->linked;
        }
        p->linked = newNode;
    }
}

//Rem Node
void remNode() {
    printRemSelect();
    int sel = input();
    
    switch(sel) {
    case REM_NODE_FST:
        remNodeFst();
        break;
    case REM_NODE_LST:
        remNodeLst();
        break;
    case BACK_MAIN:
    default:
        return;
    }
}

void remNodeFst() {
    if (HEAD == NULL) {
        return;
    } else {
        QueueTest2* del = HEAD;
        HEAD = HEAD->linked;
        del->linked = NULL;
        delete del;
    }
}

void remNodeLst() {
    if (HEAD == NULL) {
        return;
    } else {
        QueueTest2* q = NULL;
        QueueTest2* p = HEAD;
        while(p->linked != NULL) {
            q = p;
            p = p->linked;
        }
        if (p == HEAD) {
            delete HEAD;
            HEAD = NULL;
        } else {
            delete p;
            q->linked = NULL;
        }
    }
}


void printAll() {
    QueueTest2* p = HEAD;
    if(HEAD == NULL) {
        return;
    } else {
        while(p != NULL) {
            cout << "value: " << p->value << endl;
            p = p->linked;
        }
    }
}

//Selection
void printMainSelect() {
    cout << endl << endl;
    cout << "1. Add a new node." << endl;
    cout << "2. Rem a node." << endl;
    cout << "3. Print queue." << endl;
    cout << "4. Quit." << endl;
    cout << "Select: " ;

}

void printAddSelect() {
    cout << endl << endl;
    cout << "10. Add a new node to back of HEAD." << endl;
    cout << "11. Add a new node to back of TAIL." << endl;
    cout << "5. Back to the main menu." << endl;
    cout << "Select: " ;
}

void printRemSelect() {
    cout << endl << endl;
    cout << "20. Rem HEAD node." << endl;
    cout << "21. Rem TAIL node." << endl;
    cout << "5. Back to the main menu." << endl;
    cout << "Select: " ;
}

//user input
int input() {
    int sel;
    cin >> sel;
    return sel;
}

//quit
void quit() {
}