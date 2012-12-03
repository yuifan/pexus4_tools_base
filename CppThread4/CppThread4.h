#ifndef __CPP_THREAD_4_H__
#define __CPP_THREAD_4_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <unistd.h>
#include <pthread.h>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct alpha {
    char ch;
}alphabet;

alphabet mMyAlphabet;

void* nextAlphabet1(void*);
void* nextAlphabet2(void*);

void init();

#endif
