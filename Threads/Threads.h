/*
 * 
*/
#ifndef EQTHREAD_H
#define EQTHREAD_H

/* -------- */
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>
#include "Queue.h"

/* -------- */
void *enQueueThread(void *_conf);
void *deQueueThread(void *_conf);

#endif