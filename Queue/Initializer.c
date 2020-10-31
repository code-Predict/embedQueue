/*
 * 初期化
*/
#include "Queue.h"

int initQueue(Queue* queue){
    // Data
    for(int i = 0; i < QUEUE_SIZE; i++){
        initItem(&(queue->data[i]));
    }
    queue->head = 0;
    queue->tail = 0;
    queue->length = 0;
    return 0;
}

int deinitQueue(Queue* queue){
    int rst = 0;
    return 0;
}

void initItem(Item* item){
    item->id = 0;
    memset(item->data, '\0', 8);
}