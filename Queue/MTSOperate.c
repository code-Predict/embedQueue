/*
 * 処理(Multi-Thread-Safe)
*/
#include "Queue.h"

int enQueueMT(Queue* queue, Item item){
    int rst;
    pthread_mutex_lock(&(queue->mutex));
    rst = enQueue(queue, item);
    pthread_mutex_unlock(&(queue->mutex));
    pthread_cond_broadcast(&(queue->isNotEmpty));
    return rst;
}

int deQueueMT(Queue* queue, Item *item){
    int rst;
    pthread_mutex_lock(&(queue->mutex));
    rst = deQueue(queue, item);
    pthread_mutex_unlock(&(queue->mutex));
    pthread_cond_broadcast(&(queue->isNotFull));
    return rst;
}

// deQueue, enQueueを待機する
int waitFordeQueue(Queue* queue, int timeout){
    // timespec再計算
    struct timespec timeoutTS;
    calcTimeSpec(&timeoutTS,10);
    int stat = waitSignal(&(queue->mutex), &(queue->isNotEmpty), &timeoutTS);
    return stat;
}

int waitForenQueue(Queue* queue, int timeout){
    // timespec再計算
    struct timespec timeoutTS;
    calcTimeSpec(&timeoutTS,10);
    int stat = waitSignal(&(queue->mutex), &(queue->isNotFull), &timeoutTS);
    return stat;
}

void calcTimeSpec(struct timespec* ts, int timeout){
    ts->tv_nsec = 0;
    ts->tv_sec = time(NULL) + timeout;
}

int waitSignal(pthread_mutex_t* mutex, pthread_cond_t* cond, struct timespec* ts){
    int stat = 0;
    pthread_mutex_lock(mutex);
    stat = pthread_cond_timedwait(cond, mutex, ts);
    pthread_mutex_unlock(mutex);
    return stat;
}
