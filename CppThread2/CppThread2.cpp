#include "CppThread2.h"

int main(void) {
    pthread_t p_thread[2];
    int tid;
    int status;
    
    tid = pthread_create(&p_thread[1], NULL, do_plus, NULL);
    
    usleep(200);
    
    tid = pthread_create(&p_thread[0], NULL, do_minus, NULL);
    
    pthread_join(p_thread[0], (void**) status);
    pthread_join(p_thread[1], (void**) status);
    return 0;
}

void* do_plus(void* doPlus) {
    while(1) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        cout << "Before Plus : mydata.a = " << mydata.a << ", mydata.b = " << mydata.b << endl;
        plusOper();
        cout << "After Plus  : mydata.a = " << mydata.a << ", mydata.b = " << mydata.b << endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

void* do_minus(void* doMinus) {
    while(1) {
        pthread_mutex_lock(&mutex);
        cout << "Before Minus : mydata.a = " << mydata.a << ", mydata.b = " << mydata.b << endl;
        minusOper();
        cout << "After Minus  : mydata.a = " << mydata.a << ", mydata.b = " << mydata.b << endl;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        
        usleep(200);
    }
}

void plusOper() {
    (mydata.a) += 500;
    (mydata.b) += 500;
}

void minusOper() {
    (mydata.a) -= 500;
    (mydata.b) -= 500;
}

void init() {
    mydata.a = 0;
    mydata.b = 0;
}
