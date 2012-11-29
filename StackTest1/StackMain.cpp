#include "StackTest1.h"

//about menu
void printMainMenu();
//about input
int input();
//add a node
void addNode();
//void addNewNode();
//remove a node
void remNode();
//print stack
void printAll();
//quit
void quit();

StackTest1* HEAD = NULL;

int main() {
    while(1) {
        printMainMenu();
        int sel = input();
        
        switch(sel) {
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
            quit();
            break;
        default:
            cout << "Fault!!" << endl;
        }
    }
    return 0;
}

void printMainMenu() {
    cout << endl << endl;
    cout << "1. Add a node." << endl;
    cout << "2. Remove a node." << endl;
    cout << "3. Print stack." << endl;
    cout << "4. Quit." << endl;
    cout << "Select: ";
}

int input() {
    int value;
    cin >> value;
    return value;
}

void addNode() {
    StackTest1* newNode = new StackTest1;
    int value = input();
    newNode->value = value;
    if (HEAD == NULL) {
        HEAD = newNode;
        newNode->linked = NULL;
    } else {
        newNode->linked = HEAD;
        HEAD = newNode;
    }
}

void remNode() {
    if (HEAD == NULL) {
        return;
    } else {
        StackTest1* tempNode = HEAD;
        HEAD = HEAD->linked;
        tempNode->linked = NULL;
        delete tempNode;
    }
}

void printAll() {
    if (HEAD == NULL) {
        return;
    } else {
        StackTest1* p = HEAD;
        while(p != NULL) {
            cout << "Value: " << p->value << endl;
            p = p->linked;
        }
    }
}

void quit() {
    if (HEAD == NULL) {
        return;
    } else {
        while(HEAD != NULL) {
            remNode();
        }
    }
    return;
}