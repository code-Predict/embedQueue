/*
 * キュー 
*/
#include <stdio.h>
#include <pthread.h>
#include "Threads.h"
#include "Queue.h"

int main(int argc, char const *argv[]) {
    // キュー初期化
    Queue queue, *Q;
    Q = &queue;
    initQueue(Q);

    // enQueueスレッド・deQueueスレッドを立てる
    QueueConf conf;
    conf.Q = Q;
    conf.timeout = 10;

    pthread_t eqThread, dqThread;
    pthread_create(&dqThread, NULL, deQueueThread, &conf);
    pthread_create(&eqThread, NULL, enQueueThread, &conf);

    pthread_join(dqThread, NULL);
    
    deinitQueue(Q);
    return 0;
}
