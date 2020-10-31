/*
 * キュー 
*/
#include <stdio.h>
#include <pthread.h>
#include "QueueThreads.h"
#include "Queue.h"

int main(int argc, char const *argv[]) {
    // キュー初期化
    Queue queue, *Q;
    Q = &queue;
    initQueue(Q);

    // enQueueスレッド・deQueueスレッドを立てる
    int endReq = 0;
    QueueConf conf;
    conf.Q = Q;
    conf.timeout = 10;
    conf.endReq = &endReq;

    pthread_t eqThread, dqThread;
    pthread_create(&dqThread, NULL, deQueueThread, &conf);
    pthread_create(&eqThread, NULL, enQueueThread, &conf);

    //
    printf("Type any key to endReq.\n");
    while(getc(stdin) != '\n');
    *(conf.endReq) = 1;
    printf("## endReq ##\n");
    
    deinitQueue(Q);
    return 0;
}
