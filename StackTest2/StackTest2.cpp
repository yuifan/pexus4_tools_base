#include "StackTest2.h"

StackTest2::StackTest2():value(0), linked(NULL) {
}

StackTest2::~StackTest2(){
    delete linked;
}

//HEAD
StackTest2* HEAD = NULL;
//Node POOL
StackTest2* POOL = NULL;

bool isEmptyNodePool() {
    return (POOL == NULL);
}

bool isEmptyStack() {
    return (HEAD == NULL);
}

int input() {
    int value;
    cin >> value;
    return value;
}

void setNodeValue(StackTest2* node) {
    cout << "Input Value : ";
    int value = input();
    node->value = value;
}

StackTest2* addNewNode() {
    StackTest2* newNode = new StackTest2;
    setNodeValue(newNode);
    return newNode;
}

void addNode() {
    StackTest2* node;
    //Do node pool has any node?
    if (isEmptyNodePool()) {
        node = addNewNode();
    } else {
        node = POOL;
        setNodeValue(node);
        POOL = POOL->linked;
    }
    
    if (isEmptyStack()) {
        HEAD = node;
        node->linked = NULL;
    } else {
        node->linked = HEAD;
        HEAD = node;
    }
}

void remNode() {
    StackTest2* temp;
    if (isEmptyStack()) {
        return;
    } else {
        if (isEmptyNodePool()) {
            temp = POOL;
            
            POOL = HEAD;
            HEAD = HEAD->linked;
            
            POOL->linked = temp;
        } else {
            temp = HEAD;
            HEAD = HEAD->linked;
            
            temp->linked = POOL;
            POOL = temp;
        }
    }
}

void printStack(StackTest2* p) {
    while(p != NULL) {
        cout << "Value : " << p->value << endl;
        p = p->linked;
    }
}

void printAll() {
    cout << endl;
    if (isEmptyStack()) {
        cout << "Stack is empty..." << endl << endl;
        if (isEmptyNodePool()) {
            cout << "NodePool is empty..." << endl << endl;
        } else {
            cout << "NodePool..." << endl;
            printStack(POOL);
            cout << endl;
        }
    } else {
        cout << "Stack..." << endl;
        printStack(HEAD);
        cout << endl;
        if (isEmptyNodePool()) {
            cout << "NodePool is empty..." << endl << endl;
        } else {
            cout << "NodePool..." << endl;
            printStack(POOL);
            cout << endl;
        }
    }
}

void printMainMenu(){
    cout << "1. Add node." << endl;
    cout << "2. Remove node." << endl;
    cout << "3. Print All." << endl;
    cout << "4. Quit." << endl;
    cout << "Select: ";
}

void quit() {
    exit(0);
}