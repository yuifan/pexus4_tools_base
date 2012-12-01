#include "StackTest3.h"

int numNodes;

StackTest3::StackTest3():value(0), linked(NULL) {
}

StackTest3::~StackTest3(){
    delete linked;
}

//HEAD
StackTest3* HEAD = NULL;
//Node POOL
StackTest3* POOL = NULL;

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

void setNodeValue(StackTest3* node) {
    cout << "Input Value : ";
    int value = input();
    node->value = value;
}

StackTest3* addNewNode() {
    StackTest3* newNode = new StackTest3;
    setNodeValue(newNode);
    return newNode;
}

void addNode() {
    StackTest3* node;
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
    numNodes += 1;
}

void remNode() {
    StackTest3* temp;
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
    numNodes -= 1;
}

void printStack(StackTest3* p) {
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
    cout << "4. Save to file." << endl;
    cout << "5. Restore from file." << endl;
    cout << "6. Quit." << endl;
    cout << "Select: ";
}

void saveStackToFile(StackTest3* head) {
    FILE* saveFILE = fopen("save.dat", "w");
    fprintf(saveFILE, "%2d", numNodes);

    if (head == NULL) {
        return;
    } else {
        while(head != NULL) {
            fprintf(saveFILE, "%5d", head->value);
            head = head->linked;
        }
    }
    
    fclose(saveFILE);
}

void restoreNode(int value_nodes) {
    StackTest3* node = new StackTest3;
    node->value = value_nodes;
    if (HEAD == NULL) {
        node->linked = NULL;
        HEAD = node;
    } else {
        node->linked = HEAD;
        HEAD = node;
    }
}

void restoreNodes(int num_nodes, int* value_nodes) {
    int i = 0;
    while(i < num_nodes) {
        restoreNode(value_nodes[num_nodes - (i+1)]);
        i++;
    }
}

void restoreStackFromFile(StackTest3* head) {
    if (HEAD != NULL || numNodes != 0) {
        cout << "STOP!! Stack has any nodes. If you continue, stack will overwrited." << endl;
        return;
    }
    
    FILE* restoreFILE = fopen("save.dat", "r");
    fscanf(restoreFILE, "%2d", &numNodes);
    int* valueNodes = new int[numNodes];
    int i = 0;
    
    while(i < numNodes) {
        fscanf(restoreFILE, "%5d", &valueNodes[i++]);
    }

    restoreNodes(numNodes, valueNodes);
    fclose(restoreFILE);
}

void save() {
    saveStackToFile(HEAD);
}

void restore() {
    restoreStackFromFile(HEAD);
}

void releaseHEAD() {
    if (isEmptyStack()) {
        return;
    } else {
        StackTest3* deleteNode;
        while(HEAD != NULL) {
            deleteNode = HEAD;
            HEAD = HEAD->linked;
            deleteNode->linked = NULL;
            delete deleteNode;
        }
    }
}

void releasePOOL() {
    if (isEmptyNodePool()) {
        return;
    } else {
        StackTest3* deleteNode;
        while(POOL != NULL) {
            deleteNode = POOL;
            POOL = POOL->linked;
            deleteNode->linked = NULL;
            delete deleteNode;
        }
    }
}

void releaseAllNodes() {
    releaseHEAD();
    releasePOOL();
}

void quit() {
    //TODO: delete all nodes.
    releaseAllNodes();
    printAll();
    exit(0);
}