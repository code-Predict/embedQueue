/*
 * 
*/
#include "Threads.h"

void *enQueueThread(void *_conf){
    // コンフィグからキューとタイムアウト時間を取り出す
    QueueConf conf = *(QueueConf *)_conf;
    Queue *queue = conf.Q;

    int endReq = 0, cnt = 0;

    //10秒だけ怒涛のenQueue
    time_t startTime;
    time(&startTime);
    int limit = 5;

    while (!endReq) {
        char buffer[8] = "enQueue";
        Item item;
        item.id = cnt;
        memcpy(item.data, buffer, 8);
        
        int enQueueStat = enQueueMT(queue, item);
        if(enQueueStat == QUEUE_FULL){
            perror("### QUEUE FULL ###");
        }

        // idカウンタを進める
        cnt++;
        if(cnt > 0xFF){
            cnt = 0;
        }

        // 適当に時間待ち
        usleep(100);

        // 指定時間経過?
        if((time(NULL) - startTime) > limit){
            endReq = 1;
            continue;
        }
    }
    printf("enQueue Process finished.\n");
    pthread_exit(NULL);
}