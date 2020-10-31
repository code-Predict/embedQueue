/*
 * FIFOキュー 
*/
#ifndef QUEUE_H
#define QUEUE_H

/* -------- */
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>
#include <errno.h>
#include <sys/time.h>

#define NDEBUG

#define QUEUE_SIZE 100000

#define QUEUE_OK 0
#define QUEUE_FULL 1
#define QUEUE_EMPTY 2

#ifndef uint8_t
    #define uint8_t unsigned char
#endif

/* -------- */
typedef struct item {
    int id;
    uint8_t data[8];
} Item;

typedef struct queue {
    // Data
    Item data[QUEUE_SIZE + 1];
    int head;
    int tail;
    int length;

    // Thread
    pthread_mutex_t mutex;

    pthread_cond_t isNotEmpty;
    pthread_cond_t isNotFull;

    pthread_cond_t isDequeueFinished;
    pthread_cond_t isEnqueueFinished;

} Queue;

typedef struct queueconf {
    Queue* Q;
    int timeout;
    int* endReq;

} QueueConf;


/* -------- */

// Initializer.c
int initQueue(Queue* queue);
int deinitQueue(Queue* queue);
void initItem(Item *item);

// Dump.c
void dumpItem(Item *item, char* buffer);
void dumpQueue(Queue *queue, char* buffer);
void dumpu8Array(uint8_t *data, int length, char *buffer);

// Operate.c
int enQueue(Queue* queue, Item item);
int deQueue(Queue* queue, Item* item);

//MTSOperate.c
int enQueueMT(Queue* queue, Item item);
int deQueueMT(Queue* queue, Item* item);
int waitForenQueue(Queue* queue, int timeout);
int waitFordeQueue(Queue* queue, int timeout);
void calcTimeSpec(struct timespec* ts, int timeout);
int waitSignal(pthread_mutex_t* mutex, pthread_cond_t* cond, struct timespec* ts);

#endif