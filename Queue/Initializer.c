/*
 * 初期化
*/
#include "Queue.h"

void initQueue(Queue* queue){
    for(int i = 0; i < QUEUE_SIZE; i++){
        initItem(&(queue->data[i]));
    }
    queue->head = 0;
    queue->tail = 0;
    queue->length = 0;
}

void deinitQueue(Queue* queue){
    
}

void initItem(Item* item){
    item->id = 0;
    memset(item->data, '\0', 8);
}