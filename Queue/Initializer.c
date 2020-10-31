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

    // Thread
    int rst = 0;
    rst = pthread_mutex_init(&queue->mutex, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&queue->isNotEmpty, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&queue->isNotFull, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&queue->isDequeueFinished, NULL);
    assert(rst == 0);
    rst = pthread_cond_init(&queue->isEnqueueFinished, NULL);
    assert(rst == 0);
    return rst;
}

int deinitQueue(Queue* queue){
    int rst = 0;
    rst = pthread_cond_destroy(&queue->isNotEmpty);
    assert(rst == 0);
    rst = pthread_cond_destroy(&queue->isNotFull);
    assert(rst == 0);
    rst = pthread_cond_destroy(&queue->isDequeueFinished);
    assert(rst == 0);
    rst = pthread_cond_destroy(&queue->isEnqueueFinished);
    assert(rst == 0);
    rst = pthread_mutex_destroy(&queue->mutex);
    assert(rst == 0);
    
    return rst;
}

void initItem(Item* item){
    item->id = 0;
    memset(item->data, '\0', 8);
}