#include "CppThread4.h"

int main(void) {
    pthread_t p_thread[2];
    int tid, status;
    init();
    
    tid = pthread_create(&p_thread[0], NULL, nextAlphabet1, NULL);
    usleep(200);
    tid = pthread_create(&p_thread[1], NULL, nextAlphabet2, NULL);
    
    pthread_join(p_thread[0], (void**) status);
    pthread_join(p_thread[0], (void**) status);
    return 0;
}

void* nextAlphabet1(void* next1) {
    while(1) {
        pthread_mutex_lock(&mutex);
        cout << mMyAlphabet.ch << "(tid.1)" << endl;
        if (mMyAlphabet.ch == 'z') {
            cout << "The end." << endl;
            exit(0);
        }
        (mMyAlphabet.ch)++;
        pthread_cond_wait(&cond, &mutex);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

void* nextAlphabet2(void* next2) {
    while(1) {
        pthread_mutex_lock(&mutex);
        cout << mMyAlphabet.ch << "(tid.2)" << endl;
        if (mMyAlphabet.ch == 'z') {
            cout << "The end." << endl;
            exit(0);
        }
        (mMyAlphabet.ch)++;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        
        usleep(200);
    }
}

void init() {
    mMyAlphabet.ch = 'a';
}