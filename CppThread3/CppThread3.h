#ifndef __CPP_THREAD_3_H__
#define __CPP_THREAD_3_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct alpha {
    char ch;
};

int tid;
struct alpha myalphabet;

void* nextAlphabet1(void*);
void* nextAlphabet2(void*);
void init();

#endif