/*
 * FIFOキュー 
*/
#ifndef QUEUE_H
#define QUEUE_H

/* -------- */
#include <stdio.h>
#include <string.h>

#define QUEUE_SIZE 10

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
    Item data[QUEUE_SIZE + 1];
    int head;
    int tail;
    int length;
} Queue;

/* -------- */

// Initializer.c
void initQueue(Queue* queue);
void deinitQueue(Queue* queue);
void initItem(Item *item);

// Dump.c
void dumpItem(Item *item, char* buffer);
void dumpQueue(Queue *queue, char* buffer);
void dumpu8Array(uint8_t *data, int length, char *buffer);

// Operate.c
int enQueue(Queue* queue, Item item);
int deQueue(Queue* queue, Item* item);

#endif