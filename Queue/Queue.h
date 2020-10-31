/*
 * FIFOキュー 
*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define NDEBUG

#define QUEUE_SIZE 100000

#define QUEUE_OK 0
#define QUEUE_FULL 1
#define QUEUE_EMPTY 2

/* -------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} Queue;

// typedef struct queueconf {
//     Queue* Q;
//     int timeout;
//     int* endReq;

// } QueueConf;


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

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _QUEUE_H_ */