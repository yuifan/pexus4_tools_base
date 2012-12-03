#include "CppThread1.h"

int main(void) {
    pthread_t p_thread[2];      //will run two threads.
    int tid;                    //thread id.
    int status;                 //attention this var.
    
    tid = pthread_create(&p_thread[1], NULL, do_read, NULL);
    
    usleep(200);
    
    tid = pthread_create(&p_thread[0], NULL, do_write, NULL);
    
    pthread_join(p_thread[0], (void**) status);     //what's 'status'??
    pthread_join(p_thread[1], (void**) status);     //??????
    
    return 0;
}

void* do_write(void* doWrite) {
    while(1) {
        cout << "write: ";
        pthread_mutex_lock(&mutex);
        mydata.a = random() % 6000;
        mydata.b = random() % 6000;
        cout << "mydata.a = " << mydata.a << ", " << "mydata.b = " << mydata.b << endl;
        pthread_cond_signal(&cond);
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        
        usleep(200);
    }
}

void* do_read(void* doRead) {
    while(1) {
        cout << "read: ";
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        cout << "mydata.a(" << mydata.a << ") + mydata.b(" << mydata.b << ") = " << mydata.a + mydata.b << endl;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

void init() {
    mydata.a = 0;
    mydata.b = 0;
}