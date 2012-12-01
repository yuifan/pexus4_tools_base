#include "StackTest3.h"

int main(void) {
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
        case SAVE:
            save();
            break;
        case RESTORE:
            restore();
            break;
        case QUIT:
            quit();
            break;
        default:
            return 0;
        }
    }
    return 0;
}