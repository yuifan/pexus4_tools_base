#ifndef __CPP_THREAD_2_H__
#define __CPP_THREAD_2_H__

#include <iostream>
#include <cstdlib>
#include <cstring>

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

void* do_plus(void*);
void* do_minus(void*);

void plusOper();
void minusOper();

void init();

#endif
