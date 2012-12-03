#ifndef __CPP_THREAD_1_H__
#define __CPP_THREAD_1_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct com_data {
    int a;
    int b;
};

struct com_data mydata;

void* do_write(void*);
void* do_read(void*);

void init();

#endif
