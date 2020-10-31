/*
 * 
*/
#include "QueueThreads.h"

void *deQueueThread(void *_conf){
    // コンフィグからキューとタイムアウト時間を取り出す
    QueueConf conf = *(QueueConf *)_conf;
    Queue *queue = conf.Q;
    int *endReq = conf.endReq;

    // enQueueされたら表示する タイムアウト時スレッド終了
    int deQueueStat = QUEUE_OK, waitStat = 0;
    char buffer[35];
    while(!(*endReq)){
        Item item;
        deQueueStat = deQueueMT(queue, &item);

        if(deQueueStat == QUEUE_OK){
            memset(buffer, 0, 35);
            dumpItem(&item, buffer);
        }else{
            waitStat = waitFordeQueue(queue, conf.timeout);
            if(waitStat == ETIMEDOUT){
                *endReq = 1;
                continue;
            }
        }
        usleep(1000);
    }

    printf("DeQueueThread: Timeout or detect signal.\n");
    pthread_cond_broadcast(&(queue->isDequeueFinished));
    pthread_exit(NULL);
}