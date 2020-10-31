/*
 * キュー 
*/
#include <stdio.h>
#include "Queue.h"

int main(int argc, char const *argv[]) {
    // キュー初期
    Queue queue, *Q;
    Q = &queue;
    initQueue(Q);

    // いくつかenQueue
    Item eqItem;
    for(int i = 0; i < 10; i++){
        printf("enQueue: %d\n", i);
        eqItem.id = i;
        enQueue(Q, eqItem);
    }

    // 空になるまでdeQueue
    Item dqItem;
    int status = QUEUE_OK;
    char strBuffer[100];
    memset(strBuffer, 0, 100);
    while (status != QUEUE_EMPTY) {
        status = deQueue(Q, &dqItem);
        dumpItem(&dqItem, strBuffer);
        printf("%s\n", strBuffer);
    }

    deinitQueue(Q);
    return 0;
}
